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
 *  FILENAME:   CigiMessage.cpp
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
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.6.0
 */

#define _EXPORT_CCL_

#include "CigiMessage.h"

#include <stdlib.h>

// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiMessage
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiMessage::CigiMessage()
{

   BufferCreated = false;
   BufferBlock = NULL;
   BufferCount = 0;
   BufferSize  = 0;
   BasePtr = NULL;
   FillBufferPos = NULL;
   CrntMsgBuf = 0;
   CrntFillBuf = 0;
   BuffFillCnt = NULL;
   Active = false;
   Data = NULL;
   Locked = false;
   ValidIGCtrlSOF = false;

}

// ================================================
// ~CigiMessage
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiMessage::~CigiMessage()
{

   if( BufferBlock != NULL)
   {
      double *OrigBuf = (double *)BufferBlock;
      delete [] OrigBuf;
   }

   if( BasePtr != NULL)
      delete [] BasePtr;

   if( BuffFillCnt != NULL)
      delete [] BuffFillCnt;

   if( Data != NULL)
      delete [] Data;

}


// ====================================================================
// Processing
// ====================================================================

// ================================================
// CreateBuffer
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiMessage::CreateBuffer(const int NumBuf, const int BufLen)
{

   if(!BufferCreated)
   {
      BufferCount = NumBuf;
      BufferSize  = BufLen;

      double *OrigBuf = new double[NumBuf * ((BufLen/8) + 1)];
      BufferBlock = (unsigned char *)OrigBuf;
      BasePtr = new unsigned char *[NumBuf];
      BuffFillCnt = new int[NumBuf];
      Data = new bool[NumBuf];
      for(int ndx=0;ndx<NumBuf;ndx++)
      {
         BasePtr[ndx] = BufferBlock + (ndx * BufLen);
         BuffFillCnt[ndx] = 0;
         Data[ndx] = false;
      }
      FillBufferPos = BufferBlock;

	   CrntMsgBuf = 0;
      CrntFillBuf = 0;
      Active = false;
      Locked = false;

   }

   return(CIGI_SUCCESS);

}
