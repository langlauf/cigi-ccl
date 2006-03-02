// XIGCtrl.cpp: Body of the XIGCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "XIGCtrl.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XIGCtrl::XIGCtrl()
{

}

XIGCtrl::~XIGCtrl()
{

}


void XIGCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiIGCtrlV3 *InPckt = (CigiIGCtrlV3 *)Packet;

   bool ok = true;

   printf("===> IGCtrl <===\n");

   printf("Version ==> %d\n",InPckt->GetVersion());
   printf("DatabaseID ==> %d\n",InPckt->GetDatabaseID());
   printf("IGMode ==> %d\n",InPckt->GetIGMode());
   printf("TimestampValid ==> %d\n",InPckt->GetTimeStampValid());
   printf("FrameCntr ==> %d\n",InPckt->GetFrameCntr());
   printf("TimeStampV3 ==> %d\n",InPckt->GetTimeStamp());


}
