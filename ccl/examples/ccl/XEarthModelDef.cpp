// XEarthModelDef.cpp: Body of the XEarthModelDef class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XEarthModelDef.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEarthModelDef::XEarthModelDef()
{

}

XEarthModelDef::~XEarthModelDef()
{

}


void XEarthModelDef::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiEarthModelDefV3 *InPckt = (CigiEarthModelDefV3 *)Packet;

   bool ok = true;

   printf("CustomERMEn ==> %d\n",InPckt->GetCustomERMEn());
   printf("EquatorialRadius ==> %f\n",InPckt->GetEquatorialRadius());
   printf("Flattening ==> %f\n",InPckt->GetFlattening());

}
