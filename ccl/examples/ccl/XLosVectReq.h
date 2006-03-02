// XLosVectReq.h: interface for the XLosVectReq class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLosVectReq_INCLUDED_)
#define _PROC_XLosVectReq_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosVectReqV3.h"

class XLosVectReq : public CigiBaseEventProcessor
{
public:
   XLosVectReq();
   virtual ~XLosVectReq();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosVectReqV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosVectReqV3 *TPckt;

};

#endif // _PROC_XLosVectReq_INCLUDED_
