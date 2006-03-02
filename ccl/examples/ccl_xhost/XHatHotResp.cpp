// XHatHotResp.cpp: Body of the XHatHotResp class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XHatHotResp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHatHotResp::XHatHotResp()
{

}

XHatHotResp::~XHatHotResp()
{

}


void XHatHotResp::OnPacketReceived(CigiBasePacket *Packet)
{
CigiHatHotRespV3 *InPckt = (CigiHatHotRespV3 *)Packet;

   printf("HatHotID ==> %d\n",InPckt->GetHatHotID());
   printf("Valid ==> %d\n",InPckt->GetValid());
   printf("ReqType ==> %d\n",InPckt->GetReqType());
   printf("Hat ==> %f  :::  Hot ==> %f\n",InPckt->GetHat(),InPckt->GetHot());


}
