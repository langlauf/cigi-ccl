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
 *  FILENAME:   CigiSession.h
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
 *  Added the CIGI_SPEC modifier to the class declaration for exporting the 
 *  class in a Windows DLL.
 *  
 *  02/20/2006 Greg Basler                       Version 1.6.0
 *  Added the PackageMsg, GetCurrentlyPackagedMsg, and FreeMsg methods to
 *  better update the frame the frame counter in the IG_Ctrl packet for hosts
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.6.0
 */

#if !defined(_CIGI_OUTGOING_MESSAGE_INCLUDED_)
#define _CIGI_OUTGOING_MESSAGE_INCLUDED_


#include "CigiMessage.h"
#include "CigiBasePacket.h"
#include "CigiBaseEntityCtrl.h"
#include "CigiBaseIGCtrl.h"
#include "CigiBaseSOF.h"


class CigiOutgoingMsg;



//=========================================================
//! The class for the outgoing message
//!
class CIGI_SPEC CigiOutgoingMsg : public CigiMessage  
{
public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiOutgoingMsg();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiOutgoingMsg();





   //==> Buffer Packing Operators

   //=========================================================
   //! Packs the buffer with the specifed IG Control packet.  
   //! \param refPacket - A reference to an IG Control packet.
   //!
   //! \return This returns a reference to this CigiOutgoingMsg object
   CigiOutgoingMsg & operator <<(CigiBaseIGCtrl &refPacket);

   //=========================================================
   //! Packs the buffer with the specifed Start Of Frame packet.  
   //! \param refPacket - A reference to an Start Of Frame packet.
   //!
   //! \return This returns a reference to this CigiOutgoingMsg object
   CigiOutgoingMsg & operator <<(CigiBaseSOF &refPacket);

   //=========================================================
   //! Packs the buffer with the specifed Entity Control packet.  
   //! \param refPacket - A reference to an Entity Control packet.
   //!
   //! \return This returns a reference to this CigiOutgoingMsg object
   CigiOutgoingMsg & operator <<(CigiBaseEntityCtrl &refPacket);

   //=========================================================
   //! Packs the buffer with the specifed packet.  
   //! \param refPacket - A reference to an Enviroment type
   //!    Control packet.  This includes Celestial and Atmosphere Ctrl
   //!
   //! \return This returns a reference to this CigiOutgoingMsg object
   CigiOutgoingMsg & operator <<(CigiBaseEnvCtrl &refPacket);

   //=========================================================
   //! Packs the buffer with the pointer to the specifed packet.  
   //! \param refBasePacket - A reference to a base packet.
   //!
   //! \return This returns a reference to this CigiOutgoingMsg object
   CigiOutgoingMsg & operator <<(CigiBasePacket &refBasePacket);

   //=========================================================
   //! Packs the buffer with the pointer to the specifed IG Control packet.  
   //! \param refPacket - A reference to an IG Control packet.
   //!
   //! \return This returns a reference to this CigiOutgoingMsg object
   CigiOutgoingMsg & operator <<(CigiBaseIGCtrl *refPacket)
   {
      return(operator<<(*refPacket));
   }

   //=========================================================
   //! Packs the buffer with the pointer to the specifed Start Of Frame packet.  
   //! \param refPacket - A reference to an Start Of Frame packet.
   //!
   //! \return This returns a reference to this CigiOutgoingMsg object
   CigiOutgoingMsg & operator <<(CigiBaseSOF *refPacket)
   {
      return(operator<<(*refPacket));
   }

   //=========================================================
   //! Packs the buffer with the pointer to the specifed Entity Control packet.  
   //! \param refPacket - A reference to an Entity Control packet.
   //!
   //! \return This returns a reference to this CigiOutgoingMsg object
   CigiOutgoingMsg & operator <<(CigiBaseEntityCtrl *refPacket)
   {
      return(operator<<(*refPacket));
   }

   //=========================================================
   //! Packs the buffer with the pointer to the specifed packet.  
   //! \param refPacket - A reference to an Enviroment type
   //!    Control packet.  This includes Celestial and Atmosphere Ctrl
   //!
   //! \return This returns a reference to this CigiOutgoingMsg object
   CigiOutgoingMsg & operator <<(CigiBaseEnvCtrl *refPacket)
   {
      return(operator<<(*refPacket));
   }

   //=========================================================
   //! Packs the buffer with the pointer to the specifed packet.  
   //! \param refBasePacket - A reference to a base packet.
   //!
   //! \return This returns a reference to this CigiOutgoingMsg object
   CigiOutgoingMsg & operator <<(CigiBasePacket *refBasePacket)
   {
      return(operator<<(*refBasePacket));
   }



   //==> Buffer Packing Managers

   //=========================================================
   //! Alerts the system that a message is being started.  
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int BeginMsg(void);

   //=========================================================
   //! Updates the Frame Counter in the IG Control or SOF packet
   //!   of the current message.  
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int UpdateFrameCntr(void);

   //=========================================================
   //! Increments the Frame Counter in the IG Control or SOF packet
   //!   of the current message.  
   //! \param OutgoingMsg - A pointer to the outgoing msg buffer
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int UpdateFrameCntr(unsigned char *OutgoingMsg);

   //=========================================================
   //! Updates the IG Control's Frame Counter and Database ID if needed
   //! \param OutgoingMsg - A pointer to the outgoing msg buffer
   //! \param IncomingMsg - A pointer to the incoming msg buffer
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int UpdateIGCtrl(unsigned char *OutgoingMsg, unsigned char *IncomingMsg);

   //=========================================================
   //! Updates SOF's Frame Counter
   //! \param OutgoingMsg - A pointer to the outgoing msg buffer
   //! \param LastIGCtrl - A pointer to the buffer containing the
   //!   last IG Ctrl packet received
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int UpdateSOF(unsigned char *OutgoingMsg, unsigned char *LastIGCtrl);

   //=========================================================
   //! Locks the message for sending
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int LockMsg(void);

   //=========================================================
   //! Gets a pointer to the beginning of the message and
   //!   the length of the message
   //! \param length - A reference to place the length of
   //!    the message.

   //! \return Message - A pointer to the beginning of the message.
   //!
	unsigned char * GetMsg(int &length);

   //=========================================================
   //! Gets a pointer to the beginning of the buffer.
   //! \return Buffer - A pointer to the beginning of the buffer.
   //!
   unsigned char * GetBuffer(void);

   //=========================================================
   //! Gets the length of the message in bytes. 
   //!
   //! \return The length of the message in bytes.
   //!
   int GetMsgLength(void);

   //=========================================================
   //! Unlocks the message after sending
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int UnlockMsg(void);

   //=========================================================
   //! Packages the current message.
   //! Sets up the next buffer for packing.
   //! and returns a pointer to the message to be sent and the length.
   //! \param length - A reference to place the length of
   //!    the message.
   //! \param Msg - A pointer to a pointer to the beginning of the message.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int PackageMsg(unsigned char **Msg, int &length);

   //=========================================================
   //! Gets the currently Packaged message.
   //! Sets up the next buffer for packing.
   //! and returns a pointer to the message to be sent and the length.
   //! \param length - A reference to place the length of
   //!    the message.
   //! \param Msg - A pointer to a pointer to the beginning of the message.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int GetCurrentlyPackagedMsg(unsigned char **Msg, int &length)
   {
      if(PackagedMsg >= 0)
      {
         *Msg = BasePtr[PackagedMsg];
         length = BuffFillCnt[PackagedMsg];
         return(true);
      }
      else
      {
         *Msg = (unsigned char *)0;  // equivalent to NULL
         length = 0;
         return(false);
      }
   }

   //=========================================================
   //! Frees the last packaged message buffer for use.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int FreeMsg(void);


};

#endif // !defined(_CIGI_OUTGOING_MESSAGE_INCLUDED_)
