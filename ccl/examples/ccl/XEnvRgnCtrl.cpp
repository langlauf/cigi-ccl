// XEnvRgnCtrl.cpp: Body of the XEnvRgnCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XEnvRgnCtrl.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEnvRgnCtrl::XEnvRgnCtrl()
{

}

XEnvRgnCtrl::~XEnvRgnCtrl()
{

}


void XEnvRgnCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiEnvRgnCtrlV3 *InPckt = (CigiEnvRgnCtrlV3 *)Packet;

   printf("RegionID ==> %d\n",InPckt->GetRegionID());
   printf("RgnState ==> %d\n",InPckt->GetRgnState());
   printf("WeatherProp ==> %d\n",InPckt->GetWeatherProp());
   printf("Aerosol ==> %d\n",InPckt->GetAerosol());
   printf("MaritimeSurface ==> %d\n",InPckt->GetMaritimeSurface());
   printf("TerrestrialSurface ==> %d\n",InPckt->GetTerrestrialSurface());
   printf("Lat ==> %f\n",InPckt->GetLat());
   printf("Lon ==> %f\n",InPckt->GetLon());
   printf("XSize ==> %f\n",InPckt->GetXSize());
   printf("YSize ==> %f\n",InPckt->GetYSize());
   printf("CornerRadius ==> %f\n",InPckt->GetCornerRadius());
   printf("Rotation ==> %f\n",InPckt->GetRotation());
   printf("Transition ==> %f\n",InPckt->GetTransition());


}
