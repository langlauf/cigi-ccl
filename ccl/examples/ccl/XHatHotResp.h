// XHatHotResp.h: interface for the XHatHotResp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHatHotResp_INCLUDED_)
#define _PROC_XHatHotResp_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHatHotRespV3.h"

class XHatHotResp : public CigiBaseEventProcessor
{
public:
   XHatHotResp();
   virtual ~XHatHotResp();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHatHotRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHatHotRespV3 *TPckt;

};

#endif // _PROC_XHatHotResp_INCLUDED_
