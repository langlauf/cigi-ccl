/** <pre>
 *  The Multi-Purpose Viewer
 *  Copyright (c) 2004 The Boeing Company
 *  
 *  
 *  FILENAME:   Network.h
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Multi-Purpose Viewer
 *  
 *  PROGRAM DESCRIPTION: 
 *  This class contains the data and methods necessary to
 *   handle the network interface.
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  03/29/2004 Andrew Sampson                       MPV_CR_DR_1
 *  Initial Release.
 * </pre>
 *  The Boeing Company
 *  1.0
 */

#ifndef _MPV_NETWORK_INTERFACE_INCLUDED_
#define _MPV_NETWORK_INTERFACE_INCLUDED_

#ifdef WIN32
#include <winsock.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif


//=========================================================
//! The class encapsulating the network interface.
//!
class Network
{
public:


   //==> Management

   //=========================================================
   //! General Constructor
   //!
	Network();

   //=========================================================
   //! General Destructor
   //!
	~Network();


   //==> Networking methods


   //=========================================================
   //! Opens a network communication socket
   //! \param ip - The "to" internet address
   //! \param port_send - The port on which the messages are being sent
   //! \param port_rcv - the port on which messages are being received
   //!
   //! \return Success or Failure
   //!
	bool openSocket( const char * ip, const int port_send, const int port_rcv ) ;

   //=========================================================
   //! Closes the socket
   //!
	void closeSocket() ;

   //=========================================================
   //! Sends a message
   //! \param sendbuff - A pointer to the buffer containing the
   //!    message to be sent.
   //! \param sendsize - The size of the message
   //!
   //! \return The number of bytes sent
   //!
	int send( unsigned char * sendbuff, int sendsize ) ;

   //=========================================================
   //! Receive a message
   //! \param rcvbuff - A pointer to the buffer to place the
   //!    incoming message.
   //! \param recvsize - The maximum size of the received message.
   //!
   //! \return The number of bytes recieved
   //!
	int recv( unsigned char * rcvbuff, int recvsize ) ;



private:

   //=========================================================
   //! Initializes the communication
   //! \param ipaddr - The "to" internet address
   //! \param sndport - The port on which the messages are being sent
   //! \param rcvport - the port on which messages are being received
   //!
	void InitializeComm(const char *ipaddr, const int sndport, const int rcvport);

	// Berkeley Sockets stuff

   //=========================================================
   //! The send socket
   //!
	int sndsock;

   //=========================================================
   //! The receive socket
   //!
	int rcvsock;

   //=========================================================
   //! The sending socket address
   //!
	struct sockaddr_in saddr;

   //=========================================================
   //! The receiving socket address
   //!
	struct sockaddr_in raddr;
	

   //=========================================================
   //! The Valid flag
   //!
	bool valid;
	
};

#endif    //  _MPV_NETWORK_INTERFACE_INCLUDED_
