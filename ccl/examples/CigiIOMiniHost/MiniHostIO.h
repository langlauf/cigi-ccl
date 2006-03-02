/** <pre>
 *  The SDK is used to create and format CIGI compliant messages.
 *  Copyright (c) 2001-2003 The Boeing Company
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
 *  FILENAME:   MiniHostIO.h
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
 *  10/27/2005 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 *  
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.5.4
 */

#if !defined(_MINIHOST_IO_INCLUDED_)
#define _MINIHOST_IO_INCLUDED_


#include <CigiIO.h>
#include "Network.h"  // network includes winsock2.h which must be included before windows.h


//=========================================================
//! The base class for Cigi IO.<br>
//! This class must be inherited.
//!
class CIGI_SPEC MiniHostIO : public CigiIO  
{
public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   MiniHostIO(CigiIncomingMsg &InMsg, CigiOutgoingMsg &OutMsg);

   //=========================================================
   //! General Destructor
   //!
	virtual ~MiniHostIO();


   //=========================================================
   //! Opens a network communication socket
   //! \param ip - The "to" internet address
   //! \param port_send - The port on which the messages are being sent
   //! \param port_rcv - the port on which messages are being received
   //!
   //! \return Success or Failure
   //!
	bool openSocket( const char * ip, const int port_send, const int port_rcv )
   {
      return(network.openSocket(ip, port_send, port_rcv));
   }

   //=========================================================
   //! Closes the socket
   //!
	void closeSocket()
   {
      network.closeSocket();
   }



protected:

   //==> Member variables

   //=========================================================
   //! Networking class/object<br>
   //!
   Network network;



   //==> Member protected functions

   //=========================================================
   //! A virtual function to output the data.<br>
   //! \param Buffer - A pointer to the buffer to write
   //! \param Length - The length of the message in bytes.
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Write(unsigned char * Buffer, int Length);

   //=========================================================
   //! A virtual function to input the data.<br>
   //! \param Buffer - A pointer to the buffer to fill.
   //! \param MaxLength - The maximum length allowed for the message in bytes.
   //! \return This returns the number of bytes in the message
   //!
   virtual int Read(unsigned char * Buffer, int MaxLength);



};

#endif // !defined(_MINIHOST_IO_INCLUDED_)
