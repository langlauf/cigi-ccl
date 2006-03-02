// XConfClampEntityCtrl.cpp: Body of the XConfClampEntityCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XConfClampEntityCtrl.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XConfClampEntityCtrl::XConfClampEntityCtrl()
{

}

XConfClampEntityCtrl::~XConfClampEntityCtrl()
{

}


void XConfClampEntityCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiConfClampEntityCtrlV3 *InPckt = (CigiConfClampEntityCtrlV3 *)Packet;

   bool ok = true;

   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("Yaw ==> %f\n",InPckt->GetYaw());
   printf("Lat ==> %f\n",InPckt->GetLat());
   printf("Lon ==> %f\n",InPckt->GetLon());

}
