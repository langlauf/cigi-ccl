// XAnimationStop.cpp: Body of the XAnimationStop class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XAnimationStop.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XAnimationStop::XAnimationStop()
{

}

XAnimationStop::~XAnimationStop()
{

}


void XAnimationStop::OnPacketReceived(CigiBasePacket *Packet)
{
CigiAnimationStopV3 *InPckt = (CigiAnimationStopV3 *)Packet;

   bool ok = true;

   printf("EntityID ==> %d\n",InPckt->GetEntityID());


}
