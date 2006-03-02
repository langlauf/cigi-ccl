// XTerrestrialSurfaceCtrl.cpp: Body of the XTerrestrialSurfaceCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XTerrestrialSurfaceCtrl.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XTerrestrialSurfaceCtrl::XTerrestrialSurfaceCtrl()
{

}

XTerrestrialSurfaceCtrl::~XTerrestrialSurfaceCtrl()
{

}


void XTerrestrialSurfaceCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiTerrestrialSurfaceCtrlV3 *InPckt = (CigiTerrestrialSurfaceCtrlV3 *)Packet;

   printf("EntityRgnID ==> %d\n",InPckt->GetEntityRgnID());
   printf("SurfaceCondID ==> %d\n",InPckt->GetSurfaceCondID());
   printf("SurfaceCondEn ==> %d\n",InPckt->GetSurfaceCondEn());
   printf("Scope ==> %d\n",InPckt->GetScope());
   printf("Severity ==> %d\n",InPckt->GetSeverity());
   printf("Coverage ==> %d\n",InPckt->GetCoverage());


}
