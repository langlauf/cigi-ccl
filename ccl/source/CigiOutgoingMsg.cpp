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
 *  FILENAME:   CigiOutgoingMsg.cpp
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
 *  09/15/2003 James Durtschy                    CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Defined _EXPORT_CCL_ for exporting the class in a Windows DLL.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Changed native C++ types to use CCL-defined types instead where appropriate.
 *  
 *  02/20/2006 Greg Basler                       Version 1.6.0
 *  Added the PackageMsg and FreeMsg methods to better update the frame
 *  the frame counter in the IG_Ctrl packet for hosts
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.6.0
 */

#include <stdlib.h>

#define _EXPORT_CCL_

#include "CigiOutgoingMsg.h"
#include "CigiBasePacket.h"
#include "CigiExceptions.h"
#include "CigiSwapping.h"


#ifdef CIGI_LITTLE_ENDIAN
   #define CIGI_SCOPY2 CigiSwap2
   #define CIGI_SCOPY4 CigiSwap4
   #define CIGI_SCOPY8 CigiSwap8
#else
   #define CIGI_SCOPY2 CigiCopy2
   #define CIGI_SCOPY4 CigiCopy4
   #define CIGI_SCOPY8 CigiCopy8
#endif


// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiOutgoingMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg::CigiOutgoingMsg()
{
   PackagedMsg = -1;
}

// ================================================
// ~CigiOutgoingMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg::~CigiOutgoingMsg()
{

}



// ====================================================================
// Processing
// ====================================================================

// ================================================
// BeginMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::BeginMsg()
{

   if(Active || Locked)
   {

#ifndef CIGI_NO_EXCEPT
      throw CigiCalledOutOfSequenceException();
#endif
      return(CIGI_ERROR_CALLED_OUT_OF_SEQUENCE);
   }

   Active = true;
   ValidIGCtrlSOF = false;

   if(!Data[CrntMsgBuf])
   {
      Data[CrntMsgBuf] = true;

      if(VJmp->GetJmpTbltype() ==
            CigiVersionJumpTable::Host)
      {
         // adjust the following for IG Control Packet
         BuffFillCnt[CrntMsgBuf] = VJmp->GetIGCtrlSize();
         FillBufferPos = BasePtr[CrntMsgBuf] + VJmp->GetIGCtrlSize();
      }
      else
      {
         // adjust the following for SOF Packet
         BuffFillCnt[CrntMsgBuf] = VJmp->GetSOFSize();
         FillBufferPos = BasePtr[CrntMsgBuf] + VJmp->GetSOFSize();
      }
   }

   return(CIGI_SUCCESS);

}


// ================================================
// operator << - IG Control
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg & CigiOutgoingMsg::operator <<(CigiBaseIGCtrl &refPacket)
{
   unsigned char JTblNdx =
      VJmp->GetCnvtID(refPacket.GetPacketID(),refPacket.GetVersion());

   bool Valid = VJmp->GetSndVld(JTblNdx);

   if(Valid)
   {
      CigiBasePacket * PackHndlr = VJmp->GetPcktHndlr(JTblNdx);

      PackHndlr->Pack(&refPacket, BasePtr[CrntFillBuf], NULL);

      ValidIGCtrlSOF = true;
   }
#ifndef CIGI_NO_EXCEPT
   else
      throw CigiImproperPacketException();
#endif

   return(*this);

}


// ================================================
// operator << - Start Of Frame
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg & CigiOutgoingMsg::operator <<(CigiBaseSOF &refPacket)
{
   unsigned char JTblNdx =
      VJmp->GetCnvtID(refPacket.GetPacketID(),refPacket.GetVersion());

   bool Valid = VJmp->GetSndVld(JTblNdx);

   if(Valid)
   {
      CigiBasePacket * PackHndlr = VJmp->GetPcktHndlr(JTblNdx);

      PackHndlr->Pack(&refPacket, BasePtr[CrntFillBuf], NULL);

      ValidIGCtrlSOF = true;
   }
#ifndef CIGI_NO_EXCEPT
   else
      throw CigiImproperPacketException();
#endif

   return(*this);

}


// ================================================
// operator << - Entity Control
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg & CigiOutgoingMsg::operator <<(CigiBaseEntityCtrl &refPacket)
{

   if(!Active || Locked)
      return(*this);  // add exception coding here!

   unsigned char JTblNdx =
      VJmp->GetCnvtID(refPacket.GetPacketID(),refPacket.GetVersion());

   bool Valid = VJmp->GetSndVld(JTblNdx);

   if(Valid)
   {

      CigiBasePacket * PackHndlr = VJmp->GetPcktHndlr(JTblNdx);
    
      int Size = PackHndlr->GetPacketSize();

      if( Size > 0 )
      {

         // Check room left in current buffer
         if((BufferSize - BuffFillCnt[CrntFillBuf]) >= Size)
         {
            PackHndlr->Pack(&refPacket, FillBufferPos, ATbl);
            BuffFillCnt[CrntFillBuf] += Size;
            FillBufferPos += Size;
         }
         else
         {

            // next message buffer
            int NMsgBuf = CrntFillBuf + 1;
            if(NMsgBuf >= BufferCount)
               NMsgBuf = 0;

            if(!Data[NMsgBuf])
            {
               CrntFillBuf = NMsgBuf;
               Data[NMsgBuf] = true;
               if(VJmp->GetJmpTbltype() ==
                         CigiVersionJumpTable::Host)
               {
                  // adjust the following for IG Control Packet
                  BuffFillCnt[NMsgBuf] = VJmp->GetIGCtrlSize();
                  FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetIGCtrlSize();
               }
               else
               {
                  // adjust the following for SOF Packet
                  BuffFillCnt[NMsgBuf] = VJmp->GetSOFSize();
                  FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetSOFSize();
               }


               PackHndlr->Pack(&refPacket, FillBufferPos, ATbl);
               BuffFillCnt[NMsgBuf] += Size;
               FillBufferPos += Size;

            }
#ifndef CIGI_NO_EXCEPT
            else
               throw CigiBufferOverrunException();
#endif

         }

      }

   }

   return(*this);

}



// ================================================
// operator << - Entity Control
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg & CigiOutgoingMsg::operator <<(CigiBaseEnvCtrl &refPacket)
{

   int Size;

   if(!Active || Locked)
      return(*this);  // add exception coding here!

   unsigned char JTblNdx =
      VJmp->GetCnvtID(refPacket.GetPacketID(),refPacket.GetVersion());

   bool Valid = VJmp->GetSndVld(JTblNdx);

   if(Valid)
   {

      CigiBasePacket * PackHndlr = VJmp->GetPcktHndlr(JTblNdx);

      unsigned char FillVer = refPacket.GetVersion();
      unsigned char SendVer = PackHndlr->GetVersion();

      // If the fill and send versions are the same or
      //   they are both below version 3
      if((FillVer == SendVer) ||
         ((FillVer < 3) && (SendVer < 3)))
      {

         Size = PackHndlr->GetPacketSize();

         if( Size > 0 )
         {

            // Check room left in current buffer
            if((BufferSize - BuffFillCnt[CrntFillBuf]) >= Size)
            {
               PackHndlr->Pack(&refPacket, FillBufferPos, NULL);
               BuffFillCnt[CrntFillBuf] += Size;
               FillBufferPos += Size;
            }
            else
            {

               // next message buffer
               int NMsgBuf = CrntFillBuf + 1;
               if(NMsgBuf >= BufferCount)
                  NMsgBuf = 0;

               if(!Data[NMsgBuf])
               {
                  CrntFillBuf = NMsgBuf;
                  Data[NMsgBuf] = true;
                  if(VJmp->GetJmpTbltype() ==
                     CigiVersionJumpTable::Host)
                  {
                     // adjust the following for IG Control Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetIGCtrlSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetIGCtrlSize();
                  }
                  else
                  {
                     // adjust the following for SOF Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetSOFSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetSOFSize();
                  }


                  PackHndlr->Pack(&refPacket, FillBufferPos, NULL);
                  BuffFillCnt[NMsgBuf] += Size;
                  FillBufferPos += Size;

               }
#ifndef CIGI_NO_EXCEPT
               else
                  throw CigiBufferOverrunException();
#endif

            }

         }

      }
      // if fill version is 1 or 2 sending to version 3
      else if((FillVer < 3) && (SendVer == 3))
      {

         // Get special Packet handlers
         CigiBasePacket * CPackHndlr = NULL;  // Celestial
         CigiBasePacket * APackHndlr = NULL;  // Atmosphere
         VJmp->GetDEnvPcktHndlr(&CPackHndlr,&APackHndlr);

         // Fill in Celestial

         Size = CPackHndlr->GetPacketSize();

         if( Size > 0 )
         {

            // Check room left in current buffer
            if((BufferSize - BuffFillCnt[CrntFillBuf]) >= Size)
            {
               CPackHndlr->Pack(&refPacket, FillBufferPos, NULL);
               BuffFillCnt[CrntFillBuf] += Size;
               FillBufferPos += Size;
            }
            else
            {

               // next message buffer
               int NMsgBuf = CrntFillBuf + 1;
               if(NMsgBuf >= BufferCount)
                  NMsgBuf = 0;

               if(!Data[NMsgBuf])
               {
                  CrntFillBuf = NMsgBuf;
                  Data[NMsgBuf] = true;
                  if(VJmp->GetJmpTbltype() ==
                     CigiVersionJumpTable::Host)
                  {
                     // adjust the following for IG Control Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetIGCtrlSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetIGCtrlSize();
                  }
                  else
                  {
                     // adjust the following for SOF Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetSOFSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetSOFSize();
                  }


                  CPackHndlr->Pack(&refPacket, FillBufferPos, NULL);
                  BuffFillCnt[NMsgBuf] += Size;
                  FillBufferPos += Size;

               }
#ifndef CIGI_NO_EXCEPT
               else
                  throw CigiBufferOverrunException();
#endif

            }

         }


         // Fill in Atmosphere

         Size = APackHndlr->GetPacketSize();

         if( Size > 0 )
         {

            // Check room left in current buffer
            if((BufferSize - BuffFillCnt[CrntFillBuf]) >= Size)
            {
               APackHndlr->Pack(&refPacket, FillBufferPos, NULL);
               BuffFillCnt[CrntFillBuf] += Size;
               FillBufferPos += Size;
            }
            else
            {

               // next message buffer
               int NMsgBuf = CrntFillBuf + 1;
               if(NMsgBuf >= BufferCount)
                  NMsgBuf = 0;

               if(!Data[NMsgBuf])
               {
                  CrntFillBuf = NMsgBuf;
                  Data[NMsgBuf] = true;
                  if(VJmp->GetJmpTbltype() ==
                     CigiVersionJumpTable::Host)
                  {
                     // adjust the following for IG Control Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetIGCtrlSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetIGCtrlSize();
                  }
                  else
                  {
                     // adjust the following for SOF Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetSOFSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetSOFSize();
                  }


                  APackHndlr->Pack(&refPacket, FillBufferPos, NULL);
                  BuffFillCnt[NMsgBuf] += Size;
                  FillBufferPos += Size;

               }
#ifndef CIGI_NO_EXCEPT
               else
                  throw CigiBufferOverrunException();
#endif

            }

         }

      }
      // otherwise fill version 3 to send version 1 or 2
      else
      {

         refPacket.FillHold(&EnvHoldObj);

         Size = PackHndlr->GetPacketSize();

         if( Size > 0 )
         {

            // Check room left in current buffer
            if((BufferSize - BuffFillCnt[CrntFillBuf]) >= Size)
            {
//               PackHndlr->Pack(&refPacket, FillBufferPos, (void *)&EnvHoldObj);
               PackHndlr->Pack(&EnvHoldObj, FillBufferPos,NULL);
               BuffFillCnt[CrntFillBuf] += Size;
               FillBufferPos += Size;
            }
            else
            {

               // next message buffer
               int NMsgBuf = CrntFillBuf + 1;
               if(NMsgBuf >= BufferCount)
                  NMsgBuf = 0;

               if(!Data[NMsgBuf])
               {
                  CrntFillBuf = NMsgBuf;
                  Data[NMsgBuf] = true;
                  if(VJmp->GetJmpTbltype() ==
                     CigiVersionJumpTable::Host)
                  {
                     // adjust the following for IG Control Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetIGCtrlSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetIGCtrlSize();
                  }
                  else
                  {
                     // adjust the following for SOF Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetSOFSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetSOFSize();
                  }


//                  PackHndlr->Pack(&refPacket, FillBufferPos, (void *)&EnvHoldObj);
                  PackHndlr->Pack(&EnvHoldObj, FillBufferPos,NULL);
                  BuffFillCnt[NMsgBuf] += Size;
                  FillBufferPos += Size;

               }
#ifndef CIGI_NO_EXCEPT
               else
                  throw CigiBufferOverrunException();
#endif

            }

         }

      }

   }

   return(*this);

}



// ================================================
// operator << - Most Packets
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg & CigiOutgoingMsg::operator <<(CigiBasePacket &refBasePacket)
{

   int pSize;

   if(!Active || Locked)
      return(*this);  // add exception coding here!

   unsigned char JTblNdx =
      VJmp->GetCnvtID(refBasePacket.GetPacketID(),refBasePacket.GetVersion());

   bool Valid = VJmp->GetSndVld(JTblNdx);

   if(Valid)
   {

      CigiBasePacket * PackHndlr = VJmp->GetPcktHndlr(JTblNdx);
    
      int Size = PackHndlr->GetPacketSize();

      if( Size > 0 )
      {

         // Check room left in current buffer
         if((BufferSize - BuffFillCnt[CrntFillBuf]) >= Size)
         {
            pSize = PackHndlr->Pack(&refBasePacket, FillBufferPos, NULL);
            BuffFillCnt[CrntFillBuf] += pSize;
            FillBufferPos += pSize;
         }
         else
         {

            // next message buffer
            int NMsgBuf = CrntFillBuf + 1;
            if(NMsgBuf >= BufferCount)
               NMsgBuf = 0;

            if(!Data[NMsgBuf])
            {
               CrntFillBuf = NMsgBuf;
               Data[NMsgBuf] = true;
               if(VJmp->GetJmpTbltype() ==
                         CigiVersionJumpTable::Host)
               {
                  // adjust the following for IG Control Packet
                  BuffFillCnt[NMsgBuf] = VJmp->GetIGCtrlSize();
                  FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetIGCtrlSize();
               }
               else
               {
                  // adjust the following for SOF Packet
                  BuffFillCnt[NMsgBuf] = VJmp->GetSOFSize();
                  FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetSOFSize();
               }


               pSize = PackHndlr->Pack(&refBasePacket, FillBufferPos, NULL);
               BuffFillCnt[NMsgBuf] += pSize;
               FillBufferPos += pSize;

            }
#ifndef CIGI_NO_EXCEPT
            else
               throw CigiBufferOverrunException();
#endif

         }

      }

   }

   return(*this);

}

// ================================================
// UpdateFrameCntr
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::UpdateFrameCntr()
{
   if(!ValidIGCtrlSOF)
   {
      if(VJmp->GetJmpTbltype() ==
            CigiVersionJumpTable::Host)
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiMissingIgControlException();
#endif
         return(CIGI_ERROR_MISSING_IG_CONTROL_PACKET);
      }
      else
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiMissingStartOfFrameException();
#endif
         return(CIGI_ERROR_MISSING_SOF_PACKET);
      }
   }

   Cigi_uint32 *buf = (Cigi_uint32 *)BasePtr[CrntMsgBuf];

   if((!VJmp->IsSynchronous())||
      (VJmp->GetJmpTbltype() == CigiVersionJumpTable::IG))
      VJmp->SetFrameCnt(VJmp->GetFrameCnt() + 1);


   if(VJmp->GetCigiVersion() == 3)
      buf[VJmp->GetOutFrameBufPos()] = VJmp->GetFrameCnt();
   else
   {
      Cigi_uint32 *pBufr = &buf[VJmp->GetOutFrameBufPos()];
      Cigi_uint32  tFrC  = VJmp->GetFrameCnt();
      CIGI_SCOPY4(pBufr,&tFrC);
   }


   return(CIGI_SUCCESS);

}


// ================================================
// UpdateFrameCntr
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::UpdateFrameCntr(unsigned char *OutgoingMsg)
{

   VJmp->SetFrameCnt(VJmp->GetFrameCnt() + 1);

   Cigi_uint32 Frame = 0;
   Cigi_uint32 *pBufr = NULL;


   pBufr = ((Cigi_uint32 *)OutgoingMsg) + VJmp->GetOutFrameBufPos();

   if(VJmp->GetCigiVersion() == 3)
      *pBufr = VJmp->GetFrameCnt();
   else
   {
      Frame = VJmp->GetFrameCnt();
      CIGI_SCOPY4(pBufr,&Frame);
   }


   return(CIGI_SUCCESS);

}


// ================================================
// UpdateIGCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::UpdateIGCtrl(unsigned char *OutgoingMsg, unsigned char *IncomingMsg)
{

   Cigi_uint32 Frame = 0;
   Cigi_uint32 *pBufr = NULL;
   char *OBufr = NULL;
   char *IBufr = NULL;


   // Note: For all current CIGI Versions in the
   //  IG Control and Start-Of-Frame packets:
   //  The Packet ID is in the same location in the packets.
   //  The version ID is in the same location in the packets.
   //  The database ID is in the same location in the packets.
   //  The frame counter is in the same location in the packets.

   // For Async operation, simply increment the frame counter
   if(!VJmp->IsSynchronous())
      VJmp->SetFrameCnt(VJmp->GetFrameCnt() + 1);
   else
   {
      // For synchronous host operation,
      //  get the frame number from the just received SOF packet
      //  and use that as the current frame number.
      if(*IncomingMsg == 101)
      {
         pBufr = ((Cigi_uint32 *)IncomingMsg) + 2;  // Frame counter location
         if(*(IncomingMsg + 2) >= 3)  // Cigi Version number
         {
            // Cigi Version 3 byte swap magic number
            if(*(((Cigi_uint16 *)IncomingMsg) + 3) == 0x8000)
               Frame = *pBufr;
            else
               CigiSwap4(&Frame,pBufr);
         }
         else
         {
            CIGI_SCOPY4(&Frame,pBufr);
         }
         VJmp->SetFrameCnt(Frame);

         // check and adjust the Database IDs
         OBufr = (char *)(OutgoingMsg + 3);
         if(OBufr > 0)
         {
            IBufr = (char *)(IncomingMsg + 3);
            if((*OBufr == *IBufr)||(*IBufr < 0))
               *OBufr = 0;
         }

      }
   }


   pBufr = ((Cigi_uint32 *)OutgoingMsg) + VJmp->GetOutFrameBufPos();

   if(VJmp->GetCigiVersion() == 3)
      *pBufr = VJmp->GetFrameCnt();
   else
   {
      Frame = VJmp->GetFrameCnt();
      CIGI_SCOPY4(pBufr,&Frame);
   }


   return(CIGI_SUCCESS);

}


// ================================================
// UpdateSOF
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::UpdateSOF(unsigned char *OutgoingMsg, unsigned char *LastIGCtrl)
{

   Cigi_uint32 Frame = 0;
   Cigi_uint32 *pBufr = NULL;


   // Note: For all current CIGI Versions in the
   //  IG Control and Start-Of-Frame packets:
   //  The Packet ID is in the same location in the packets.
   //  The version ID is in the same location in the packets.
   //  The frame counter is in the same location in the packets.

   // For Async operation or for IG operation,
   //   simply increment the frame counter


   VJmp->SetFrameCnt(VJmp->GetFrameCnt() + 1);


   pBufr = ((Cigi_uint32 *)OutgoingMsg) + VJmp->GetOutFrameBufPos();

   if(VJmp->GetCigiVersion() == 3)
      *pBufr = VJmp->GetFrameCnt();
   else
   {
      Frame = VJmp->GetFrameCnt();
      CIGI_SCOPY4(pBufr,&Frame);
   }


   return(CIGI_SUCCESS);

}


// ================================================
// LockMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::LockMsg()
{

   if(!ValidIGCtrlSOF)
   {
      if(VJmp->GetJmpTbltype() ==
            CigiVersionJumpTable::Host)
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiMissingIgControlException();
#endif
         return(CIGI_ERROR_MISSING_IG_CONTROL_PACKET);
      }
      else
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiMissingStartOfFrameException();
#endif
         return(CIGI_ERROR_MISSING_SOF_PACKET);
      }
   }

   if( !Active || Locked )
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiCalledOutOfSequenceException();
#endif
      return(CIGI_ERROR_CALLED_OUT_OF_SEQUENCE);
   }

   Locked = true;
   ValidIGCtrlSOF = false;

   return(CIGI_SUCCESS);

}

// ================================================
// GetMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
unsigned char * CigiOutgoingMsg::GetMsg(int &length)
{

   if(!Active)
      return(NULL);

   length = BuffFillCnt[CrntMsgBuf];

   return(BasePtr[CrntMsgBuf]);

}

// ================================================
// GetBuffer
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
unsigned char * CigiOutgoingMsg::GetBuffer()
{

   if(!Active)
      return(NULL);

   return(BasePtr[CrntMsgBuf]);

}

// ================================================
// GetMsgLength
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::GetMsgLength()
{

   if(!Active)
      return(0);

   return(BuffFillCnt[CrntMsgBuf]);

}

// ================================================
// UnlockMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::UnlockMsg()
{

   if(!Active || !Locked)
   {

#ifndef CIGI_NO_EXCEPT
      throw CigiCalledOutOfSequenceException();
#endif
      return(CIGI_ERROR_CALLED_OUT_OF_SEQUENCE);
   }

   Active = false;

   BuffFillCnt[CrntMsgBuf] = 0;
   Data[CrntMsgBuf] = false;

   int NextBuf = CrntMsgBuf + 1;
   if(NextBuf == BufferCount)
      NextBuf = 0;

   if(CrntFillBuf == CrntMsgBuf)
      CrntFillBuf = NextBuf;

   CrntMsgBuf = NextBuf;

   Locked = false;

   return(CIGI_SUCCESS);

}

// ================================================
// PackageMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::PackageMsg(unsigned char **Msg, int &length)
{

   *Msg = NULL;
   length = 0;

   if(!ValidIGCtrlSOF)
   {
      if(VJmp->GetJmpTbltype() ==
            CigiVersionJumpTable::Host)
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiMissingIgControlException();
#endif
         return(CIGI_ERROR_MISSING_IG_CONTROL_PACKET);
      }
      else
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiMissingStartOfFrameException();
#endif
         return(CIGI_ERROR_MISSING_SOF_PACKET);
      }
   }

   if( !Active || Locked )
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiCalledOutOfSequenceException();
#endif
      return(CIGI_ERROR_CALLED_OUT_OF_SEQUENCE);
   }

   Locked = true;
   ValidIGCtrlSOF = false;

   if(PackagedMsg >= 0)
   {
      Data[PackagedMsg] = false;
      BuffFillCnt[PackagedMsg] = 0;
      PackagedMsg = -1;
   }

   length = BuffFillCnt[CrntMsgBuf];
   *Msg = BasePtr[CrntMsgBuf];
   PackagedMsg = CrntMsgBuf;


   int NextBuf = CrntMsgBuf + 1;
   if(NextBuf == BufferCount)
      NextBuf = 0;

   if(CrntFillBuf == CrntMsgBuf)
   {

      if(!Data[NextBuf])
      {
         CrntFillBuf = NextBuf;

         Data[NextBuf] = true;
         if(VJmp->GetJmpTbltype() ==
            CigiVersionJumpTable::Host)
         {
            // adjust the following for IG Control Packet
            BuffFillCnt[NextBuf] = VJmp->GetIGCtrlSize();
            FillBufferPos = BasePtr[NextBuf] + VJmp->GetIGCtrlSize();
         }
         else
         {
            // adjust the following for SOF Packet
            BuffFillCnt[NextBuf] = VJmp->GetSOFSize();
            FillBufferPos = BasePtr[NextBuf] + VJmp->GetSOFSize();
         }

      }
      else
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiBufferOverrunException();
#endif
         return(CIGI_ERROR_BUFFER_OVERRUN);
      }

   }

   CrntMsgBuf = NextBuf;

   Locked = false;

   return(CIGI_SUCCESS);

}

// ================================================
// FreeMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::FreeMsg(void)
{
   if(PackagedMsg < 0)
   {

#ifndef CIGI_NO_EXCEPT
      throw CigiCalledOutOfSequenceException();
#endif
      return(CIGI_ERROR_CALLED_OUT_OF_SEQUENCE);
   }

   Data[PackagedMsg] = false;
   BuffFillCnt[PackagedMsg] = 0;

   PackagedMsg = -1;

   return(CIGI_SUCCESS);

}


