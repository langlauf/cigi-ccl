// XEnvCondReq.cpp: Body of the XEnvCondReq class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XEnvCondReq.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEnvCondReq::XEnvCondReq()
{

}

XEnvCondReq::~XEnvCondReq()
{

}


void XEnvCondReq::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiEnvCondReqV3 *InPckt = (CigiEnvCondReqV3 *)Packet;

   bool ok = true;

   printf("ReqType ==> %d\n",InPckt->GetReqType());
   printf("Lat ==> %f\n",InPckt->GetLat());
   printf("Lon ==> %f\n",InPckt->GetLon());
   printf("Alt ==> %f\n",InPckt->GetAlt());


}
