// XSensorCtrl.cpp: Body of the XSensorCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XSensorCtrl.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSensorCtrl::XSensorCtrl()
{

}

XSensorCtrl::~XSensorCtrl()
{

}


void XSensorCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSensorCtrlV3 *InPckt = (CigiSensorCtrlV3 *)Packet;

   bool ok = true;

   printf("ViewID ==> %d\n",InPckt->GetViewID());
   printf("SensorID ==> %d\n",InPckt->GetSensorID());
   printf("SensorOn ==> %d\n",InPckt->GetSensorOn());
   printf("Polarity ==> %d\n",InPckt->GetPolarity());
   printf("LineDropEn ==> %d\n",InPckt->GetLineDropEn());
   printf("AutoGainEn ==> %d\n",InPckt->GetAutoGainEn());
   printf("TrackPolarity ==> %d\n",InPckt->GetTrackPolarity());
   printf("ResponseType ==> %d\n",InPckt->GetResponseType());
   printf("Gain ==> %f\n",InPckt->GetGain());
   printf("Level ==> %f\n",InPckt->GetLevel());
   printf("ACCoupling ==> %f\n",InPckt->GetACCoupling());
   printf("Noise ==> %f\n",InPckt->GetNoise());


}
