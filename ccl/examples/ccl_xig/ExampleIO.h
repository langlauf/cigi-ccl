// ExampleIO.h: interface for the ExampleIO class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXAMPLEIO_H__46775CCB_06FA_4DD9_9902_BFD4A52580FA__INCLUDED_)
#define AFX_EXAMPLEIO_H__46775CCB_06FA_4DD9_9902_BFD4A52580FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AllCigi.h"

#include "Network.h"


class ExampleIO : public CigiIO  
{
public:
	ExampleIO(CigiIncomingMsg &InMsg, CigiOutgoingMsg &OutMsg, unsigned char *Buffer, int *MessageLength);
	virtual ~ExampleIO();



protected:

   virtual int Write(unsigned char * Buffer, int Length);
   virtual int Read(unsigned char * Buffer, int MaxLength);

   unsigned char *buf;
   int *MsgLen;

   Network CComm;

};

#endif // !defined(AFX_EXAMPLEIO_H__46775CCB_06FA_4DD9_9902_BFD4A52580FA__INCLUDED_)
