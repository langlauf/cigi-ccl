// GenProc.h: interface for the GenProc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GENPROC_H__C6E9A219_D13E_47D4_BC21_A43A7EA61468__INCLUDED_)
#define AFX_GENPROC_H__C6E9A219_D13E_47D4_BC21_A43A7EA61468__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CigiBaseEventProcessor.h"

class GenProc : public CigiBaseEventProcessor  
{
public:
	GenProc();
	virtual ~GenProc();


   virtual void OnPacketReceived(CigiBasePacket *Packet);

};

#endif // !defined(AFX_GENPROC_H__C6E9A219_D13E_47D4_BC21_A43A7EA61468__INCLUDED_)
