/** <pre>
 *  The Multi-Purpose Viewer
 *  Copyright (c) 2004 The Boeing Company
 *  
 *  
 *  FILENAME:   Network.cpp
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

#include "StdAfx.h"
#include "Network.h"

#include <stdio.h>
#include <fcntl.h>

// ================================================
// Network
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Network::Network()
{
	valid = false;
}

// ================================================
// ~Network
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Network::~Network()
{
	closeSocket();
}

// ================================================
// openSocket
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
bool Network::openSocket( const char * ip, const int port_send, const int port_rcv )
{
	// Initialize communications.
	InitializeComm(ip, port_send, port_rcv);
	
	return valid;
}


// ================================================
// closeSocket
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void Network::closeSocket()
{
	if( !valid ) return;


#ifdef WIN32
	// Clean up the sockets.
	closesocket(sndsock);
	closesocket(rcvsock);

   // Clean up WinSock.  Again, this is not needed for non-Windows platforms.
	WSACleanup();
#else

	// Clean up the sockets.
	close(sndsock);
	close(rcvsock);

#endif

	valid = false;
}


// ================================================
// send
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int Network::send( unsigned char * sendbuff, int sendsize )
{
	if( !valid ) return -1;
	return sendto(sndsock, (const char *)sendbuff, sendsize, 0, (struct sockaddr *)&saddr,
			sizeof(struct sockaddr));

}

// ================================================
// recv
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int Network::recv( unsigned char * rcvbuff, int recvsize )
{
	if( !valid ) return -1;
	return recvfrom(rcvsock, (char *)rcvbuff, recvsize, 0, NULL, 0);
}



// ================================================
// InitializeComm
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void Network::InitializeComm(const char *ipaddr, const int sndport, const int rcvport)
{
	int status;
	
#ifdef WIN32
	// Initialize winsock.  If you are using Berkeley sockets on a
	// non-Win32 platform, you can leave out these first two lines.
	WSADATA wsainfo;
	WSAStartup(MAKEWORD(1, 1), &wsainfo);
#endif

	// Open the connection for sending.
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(sndport);	// Use whatever port your host listens on
	saddr.sin_addr.s_addr = inet_addr(ipaddr);	// IP address of host
	
	sndsock = socket(AF_INET, SOCK_DGRAM, 0);
	if( sndsock < 0 ) {
		// socket could not be created
		valid = false;
		return;
	}

	// Open the connection for receiving.
	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(rcvport);	// Use whatever port your host sends to
	raddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	rcvsock = socket(AF_INET, SOCK_DGRAM, 0);
	if( rcvsock < 0 ) {
		// socket could not be created
		valid = false;
		return;
	}

	// Make the address reusable.
	int sockparam = 1; /* TRUE; */
	setsockopt(rcvsock, SOL_SOCKET, SO_REUSEADDR, (const char *)&sockparam, sizeof(int));
	
	// Make the socket non-blocking.
#ifdef WIN32
	// This is how sockets are put in non-blocking mode on Windows.
	unsigned long arg = 1L;
	ioctlsocket(rcvsock, FIONBIO, &arg);
#else
	// This is how sockets are put in non-blocking mode on non-Windows operating systems (and Cygwin).
	fcntl( rcvsock, F_SETFL, O_NONBLOCK );
#endif

	// Bind the socket to the local address.
	status = 
		bind(rcvsock, (struct sockaddr *)&raddr, sizeof(struct sockaddr));
	if( status != 0 ) {
		// socket could not be bound
		valid = false;
		return;
	}
	
	
	// FIXME - more error checking
	valid = true;
}


