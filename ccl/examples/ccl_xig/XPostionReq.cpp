// XPostionReq.cpp: Body of the XPostionReq class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XPostionReq.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XPositionReq::XPositionReq()
{

}

XPositionReq::~XPositionReq()
{

}


void XPositionReq::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiPositionReqV3 *InPckt = (CigiPositionReqV3 *)Packet;

   bool ok = true;

   printf("ObjectID ==> %d\n",InPckt->GetObjectID());
   printf("ArtPartID ==> %d\n",InPckt->GetArtPartID());
   printf("UpdateMode ==> %d\n",InPckt->GetUpdateMode());
   printf("ObjectClass ==> %d\n",InPckt->GetObjectClass());
   printf("CoordSys ==> %d\n",InPckt->GetCoordSys());


}
