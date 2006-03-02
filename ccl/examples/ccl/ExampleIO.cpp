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

}

ExampleIO::~ExampleIO()
{

}



int ExampleIO::Write(unsigned char * Buffer, int Length)
{

   int tlen = (Length < 32767) ? Length : 32762;

   memcpy(buf,Buffer,tlen);
   *MsgLen = tlen;

   return(CIGI_SUCCESS);
}


int ExampleIO::Read(unsigned char * Buffer, int MaxLength)
{

   int tlen = (*MsgLen < MaxLength) ? *MsgLen : MaxLength;

   memcpy(Buffer,buf,tlen);

   return(tlen);

}


