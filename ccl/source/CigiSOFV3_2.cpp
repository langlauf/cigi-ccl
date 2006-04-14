/** <pre>
 *  The SDK is used to create and format CIGI compliant messages.
 *  Copyright (c) 2001-2005 The Boeing Company
 *  
 *  This library is free software; you can redistribute it and/or modify it 
 *  under the terms of the GNU Lesser General Public License as published by 
 *  the Free Software Foundation; either version 2.1 of the License, or (at 
 *  your option) any later version.
 *  
 *  This library is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more 
 *  details.
 *  
 *  You should have received a copy of the GNU Lesser General Public License 
 *  along with this library; if not, write to the Free Software Foundation, 
 *  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *  
 *  FILENAME:   CigiSOFV3_2.cpp
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Common Image Generator Interface (CIGI) SDK
 *  
 *  PROGRAM DESCRIPTION: 
 *  ...
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  09/17/2003 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Defined _EXPORT_CCL_ for exporting the class in a Windows DLL.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Removed the inline defnitions for the PackedPointer union.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Changed native C++ types to use CCL-defined types instead where appropriate.
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.6.0
 */

#define _EXPORT_CCL_

#include "CigiSOFV3_2.h"
#include "CigiExceptions.h"
#include "CigiSwapping.h"


// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiSOFV3_2
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSOFV3_2::CigiSOFV3_2()
{

   PacketID = CIGI_SOF_PACKET_ID_V3_2;
   PacketSize = CIGI_SOF_PACKET_SIZE_V3_2;
   Version = 3;
   MinorVersion = 2;

   BSwapEn = false;
   DatabaseID = 0;
   FrameCntr = 0;
   TimeStampV2 = 0.0f;
   TimeStampV3 = 0;
   ByteSwap = 0x8000;
   IGMode = Standby;
   TimestampValid = false;
   EarthRefModel = WGS84;
   LastRcvdHostFrame = 0;

}

// ================================================
// ~CigiSOFV3_2
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSOFV3_2::~CigiSOFV3_2()
{

}





// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSOFV3_2::Pack(CigiBasePacket * Base, unsigned char * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseSOF *Data = ( CigiBaseSOF *) Base;


   CDta.c = Buff;

   *CDta.c++ = PacketID;
   *CDta.c++ = PacketSize;
   *CDta.c++ = Version;

   *CDta.b++ = Data->DatabaseID;
   *CDta.c++ = Data->IGStatus;

   unsigned char HDta = (Data->MinorVersion << 4) & 0xf0;
   HDta |= (Data->TimestampValid) ? 0x04 : 0;
   HDta |= (unsigned char)(Data->IGMode & 0x03);
   HDta |= (unsigned char)((Data->EarthRefModel << 3) & 0x08);

   *CDta.c++ = HDta;

   *CDta.s++ = 0x8000;  // Byte Swap
   *CDta.l++ = Data->FrameCntr;
   *CDta.l++ = Data->TimeStampV3;
   *CDta.l++ = Data->LastRcvdHostFrame;
   *CDta.s++ = 0;


   return(PacketSize);

}


// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSOFV3_2::Unpack(unsigned char * Buff, bool Swap, void *Spec)
{

   PackPointer CDta;

   CDta.c = Buff;

   CDta.c += 3;

   DatabaseID = *CDta.b++;
   IGStatus = *CDta.c++;

   unsigned char HDta = *CDta.c++;

   IGMode = (IGModeGrp)(HDta & 0x03);
   EarthRefModel = (EarthRefModelGrp)((HDta >> 3) & 0x01);
   TimestampValid = ((HDta & 0x04) != 0);

   ByteSwap = *CDta.s++;

   BSwapEn = (ByteSwap == 0x0080);

   if(!BSwapEn)
   {
      FrameCntr = *CDta.l++;
      TimeStampV3 = *CDta.l++;
      LastRcvdHostFrame = *CDta.l++;
   }
   else
   {
      CigiSwap4(&FrameCntr,CDta.l++);
      CigiSwap4(&TimeStampV2,CDta.f++);
      CigiSwap4(&LastRcvdHostFrame,CDta.l++);
   }

   TimeStampV2 = ((float)TimeStampV3) * 10.0f;


   return(CIGI_SUCCESS);

}




// ====================================================================
// Accessors
// ====================================================================



// ================================================
// SetTimeStamp
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSOFV3_2::SetTimeStamp(const Cigi_uint32 TimeStamp, bool bndchk)
{

   TimeStampV3 = TimeStamp;
   TimeStampV2 = ((float)TimeStampV3) * 10.0f;

   return(CIGI_SUCCESS);

}

// ================================================
// SetEarthRefModel
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSOFV3_2::SetEarthRefModel(const EarthRefModelGrp EarthRefModelIn,
                                bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((EarthRefModelIn < 0)||(EarthRefModelIn > 1)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("EarthRefModel",EarthRefModelIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   EarthRefModel = EarthRefModelIn;

   return(CIGI_SUCCESS);

}

