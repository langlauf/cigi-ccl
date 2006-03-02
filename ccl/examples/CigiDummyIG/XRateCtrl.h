// XRateCtrl.h: interface for the XRateCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XRateCtrl_INCLUDED_)
#define _PROC_XRateCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiRateCtrlV3.h"

class XRateCtrl : public CigiBaseEventProcessor
{
public:
   XRateCtrl();
   virtual ~XRateCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiRateCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiRateCtrlV3 *TPckt;

};

#endif // _PROC_XRateCtrl_INCLUDED_
