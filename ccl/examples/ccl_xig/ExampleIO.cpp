// ExampleIO.cpp: implementation of the ExampleIO class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "memory.h"
#include "ExampleIO.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ExampleIO::ExampleIO(CigiIncomingMsg &InMsg, CigiOutgoingMsg &OutMsg, unsigned char *Buffer, int *MessageLength)
          : CigiIO(InMsg,OutMsg), buf(Buffer), MsgLen(MessageLength)
{
   CComm.openSocket("127.0.0.1",8001,8000);   // Local Machine
//   CComm.openSocket("TEST_HOST_IP",8001,8000);   // Test Host Machine
}

ExampleIO::~ExampleIO()
{
   CComm.closeSocket();
}



int ExampleIO::Write(unsigned char * Buffer, int Length)
{


   int tlen = (Length < 32767) ? Length : 32762;

   CComm.send(Buffer,tlen);

   *MsgLen = tlen;

   return(CIGI_SUCCESS);

}


int ExampleIO::Read(unsigned char * Buffer, int MaxLength)
{
   int tlen = 0;
   int pscnt = 0;
   bool rcvd = false;

   while(!rcvd)
   {
      tlen = CComm.recv(Buffer,MaxLength);

      if(tlen > 0)
         rcvd = true;
      else if(pscnt > 1000000)
         rcvd = true;
      else
         pscnt++;

   }


   return(tlen);

}


