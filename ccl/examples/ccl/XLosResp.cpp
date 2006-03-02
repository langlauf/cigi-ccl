// XLosResp.cpp: Body of the XLosResp class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XLosResp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosResp::XLosResp()
{

}

XLosResp::~XLosResp()
{

}


void XLosResp::OnPacketReceived(CigiBasePacket *Packet)
{
CigiLosRespV3 *InPckt = (CigiLosRespV3 *)Packet;

   printf("LosID ==> %d\n",InPckt->GetLosID());
   printf("Valid ==> %d\n",InPckt->GetValid());
   printf("EntityIDValid ==> %d\n",InPckt->GetEntityIDValid());
   printf("Visible ==> %d\n",InPckt->GetVisible());
   printf("RespCount ==> %d\n",InPckt->GetRespCount());
   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("Range ==> %f\n",InPckt->GetRange());


}
