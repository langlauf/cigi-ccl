// IGMan.cpp: implementation of the IGMan class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IGMan.h"
#include "Callbacks.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IGMan::IGMan(unsigned char *MsgXferBuf, int *MsgSz)
{

   MsgXfer = MsgXferBuf;
   pMsgSz = MsgSz;


   TstID = 0;

   // Get the outgoing msg manager
   CigiOutgoingMsg &Omsg = IGsn.GetOutgoingMsgMgr();

   // Get incoming message manager
   CigiIncomingMsg &Imsg = IGsn.GetIncomingMsgMgr();

   // Set up IO
   ExIO = new ExampleIO(Imsg,Omsg,MsgXfer,pMsgSz);

   // Set up cigi interface version
   IGsn.SetCigiVersion(3);

   // Set as synchronous
   IGsn.SetSynchronous(true);

   // Set up internal cigi version
   Imsg.SetReaderCigiVersion(3);

   // Turn off the iteration method.
   Imsg.UsingIteration(false);

   // Set up start of frame object
   SOF.SetDatabaseID(1,false);
   SOF.SetIGStatus(0,false);
   SOF.SetIGMode(CigiBaseSOF::Operate,false);
   SOF.SetEarthRefModel(CigiBaseSOF::WGS84,false);



   // Register all the Event processors
   Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_IGCtrl);
   Imsg.RegisterEventProcessor(CIGI_ENTITY_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_EntityCtrl);
   Imsg.RegisterEventProcessor(CIGI_CONF_CLAMP_ENTITY_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_ConfClampEntityCtrl);
   Imsg.RegisterEventProcessor(CIGI_COMP_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_CompCtrl);
   Imsg.RegisterEventProcessor(CIGI_SHORT_COMP_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_ShortCompCtrl);
   Imsg.RegisterEventProcessor(CIGI_ART_PART_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_ArtPartCtrl);
   Imsg.RegisterEventProcessor(CIGI_SHORT_ART_PART_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_ShortArtPartCtrl);
   Imsg.RegisterEventProcessor(CIGI_RATE_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_RateCtrl);
   Imsg.RegisterEventProcessor(CIGI_CELESTIAL_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_CelestialCtrl);
   Imsg.RegisterEventProcessor(CIGI_ATMOS_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_AtmosCtrl);
   Imsg.RegisterEventProcessor(CIGI_ENV_RGN_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_EnvRgnCtrl);
   Imsg.RegisterEventProcessor(CIGI_WEATHER_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_WeatherCtrl);
   Imsg.RegisterEventProcessor(CIGI_MARITIME_SURFACE_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_MaritimeSurfaceCtrl);
   Imsg.RegisterEventProcessor(CIGI_WAVE_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_WaveCtrl);
   Imsg.RegisterEventProcessor(CIGI_TERRESTRIAL_SURFACE_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_TerrestrialSurfaceCtrl);
   Imsg.RegisterEventProcessor(CIGI_VIEW_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_ViewCtrl);
   Imsg.RegisterEventProcessor(CIGI_SENSOR_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_SensorCtrl);
   Imsg.RegisterEventProcessor(CIGI_MOTION_TRACK_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_MotionTrackCtrl);
   Imsg.RegisterEventProcessor(CIGI_EARTH_MODEL_DEF_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_EarthModelDef);
   Imsg.RegisterEventProcessor(CIGI_TRAJECTORY_DEF_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_Trajectory);
   Imsg.RegisterEventProcessor(CIGI_VIEW_DEF_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_ViewDef);
   Imsg.RegisterEventProcessor(CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_CollDetSegDef);
   Imsg.RegisterEventProcessor(CIGI_COLL_DET_VOL_DEF_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_CollDetVolDef);
   Imsg.RegisterEventProcessor(CIGI_HAT_HOT_REQ_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_HatHotReq);
   Imsg.RegisterEventProcessor(CIGI_LOS_SEG_REQ_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_LosSegReq);
   Imsg.RegisterEventProcessor(CIGI_LOS_VECT_REQ_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_LosVectReq);
   Imsg.RegisterEventProcessor(CIGI_POSITION_REQ_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_PositionReq);
   Imsg.RegisterEventProcessor(CIGI_ENV_COND_REQ_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_EnvCondReq);

	Imsg.RegisterEventProcessor(0, (CigiBaseEventProcessor *) &AllProc);



   // Register all the callback processors

   Imsg.RegisterCallBack(CIGI_IG_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YIGCtrl);
   Imsg.RegisterCallBack(CIGI_ENTITY_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YEntityCtrl);
   Imsg.RegisterCallBack(CIGI_CONF_CLAMP_ENTITY_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YConfClampEntityCtrl);
   Imsg.RegisterCallBack(CIGI_COMP_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YCompCtrl);
   Imsg.RegisterCallBack(CIGI_SHORT_COMP_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YShortCompCtrl);
   Imsg.RegisterCallBack(CIGI_ART_PART_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YArtPartCtrl);
   Imsg.RegisterCallBack(CIGI_SHORT_ART_PART_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YShortArtPartCtrl);
   Imsg.RegisterCallBack(CIGI_RATE_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YRateCtrl);
   Imsg.RegisterCallBack(CIGI_CELESTIAL_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YCelestialCtrl);
   Imsg.RegisterCallBack(CIGI_ATMOS_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YAtmosCtrl);
   Imsg.RegisterCallBack(CIGI_ENV_RGN_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YEnvRgnCtrl);
   Imsg.RegisterCallBack(CIGI_WEATHER_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YWeatherCtrl);
   Imsg.RegisterCallBack(CIGI_MARITIME_SURFACE_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YMaritimeSurfaceCtrl);
   Imsg.RegisterCallBack(CIGI_WAVE_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YWaveCtrl);
   Imsg.RegisterCallBack(CIGI_TERRESTRIAL_SURFACE_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YTerrestrialSurfaceCtrl);
   Imsg.RegisterCallBack(CIGI_VIEW_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YViewCtrl);
   Imsg.RegisterCallBack(CIGI_SENSOR_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YSensorCtrl);
   Imsg.RegisterCallBack(CIGI_MOTION_TRACK_CTRL_PACKET_ID_V3,
                              (CigiCBProcessor) &YMotionTrackCtrl);
   Imsg.RegisterCallBack(CIGI_EARTH_MODEL_DEF_PACKET_ID_V3,
                              (CigiCBProcessor) &YEarthModelDef);
   Imsg.RegisterCallBack(CIGI_TRAJECTORY_DEF_PACKET_ID_V3,
                              (CigiCBProcessor) &YTrajectory);
   Imsg.RegisterCallBack(CIGI_VIEW_DEF_PACKET_ID_V3,
                              (CigiCBProcessor) &YViewDef);
   Imsg.RegisterCallBack(CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3,
                              (CigiCBProcessor) &YCollDetSegDef);
   Imsg.RegisterCallBack(CIGI_COLL_DET_VOL_DEF_PACKET_ID_V3,
                              (CigiCBProcessor) &YCollDetVolDef);
   Imsg.RegisterCallBack(CIGI_HAT_HOT_REQ_PACKET_ID_V3,
                              (CigiCBProcessor) &YHatHotReq);
   Imsg.RegisterCallBack(CIGI_LOS_SEG_REQ_PACKET_ID_V3,
                              (CigiCBProcessor) &YLosSegReq);
   Imsg.RegisterCallBack(CIGI_LOS_VECT_REQ_PACKET_ID_V3,
                              (CigiCBProcessor) &YLosVectReq);
   Imsg.RegisterCallBack(CIGI_POSITION_REQ_PACKET_ID_V3,
                              (CigiCBProcessor) &YPositionReq);
   Imsg.RegisterCallBack(CIGI_ENV_COND_REQ_PACKET_ID_V3,
                              (CigiCBProcessor) &YEnvCondReq);


   // Register the signal processor object
   Imsg.RegisterSignalProcessor(&SigProc);


}

IGMan::~IGMan()
{

}

void IGMan::Out(ParseLine &PrsLn)
{


   // Get the outgoing msg manager
   CigiOutgoingMsg &Omsg = IGsn.GetOutgoingMsgMgr();

   TstID++;
   printf("\n\n========IG==========\n#Test No. %d\n",TstID);

   ParseValue *pPV = PrsLn.Get1stVal();

   int Pckt = DeterminePckt(pPV);

   if(Pckt != 0)
   {



      Omsg << SOF;

//    Process the line and data
//    and pack i.e. "Omsg << Entity"

      switch(Pckt)
      {
      case CIGI_AEROSOL_RESP_PACKET_ID_V3:
         Proc_AerosolResp(pPV);
         Omsg << Om_AerosolResp;
         break;
      case CIGI_ANIMATION_STOP_PACKET_ID_V3:
         Proc_AnimationStop(pPV);
         Omsg << Om_AnimationStop;
         break;
      case CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3:
         Proc_CollDetSegResp(pPV);
         Omsg << Om_CollDetSegResp;
         break;
      case 4:
         Proc_CollDetVolResp(pPV);
         Omsg << Om_CollDetVolResp;
         break;
      case CIGI_EVENT_NOTIFICATION_PACKET_ID_V3:
         Proc_EventNotification(pPV);
         Omsg << Om_EventNotification;
         break;
      case CIGI_HAT_HOT_RESP_PACKET_ID_V3:
         Proc_HatHotResp(pPV);
         Omsg << Om_HatHotResp;
         break;
      case CIGI_IG_MSG_PACKET_ID_V3:
         Proc_IGMsg(pPV);
         Omsg << Om_IGMsg;
         break;
      case CIGI_LOS_RESP_PACKET_ID_V3:
         Proc_LosResp(pPV);
         Omsg << Om_LosResp;
         break;
      case CIGI_LOS_XRESP_PACKET_ID_V3:
         Proc_LosXResp(pPV);
         Omsg << Om_LosXResp;
         break;
      case CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3:
         Proc_MaritimeSurfaceResp(pPV);
         Omsg << Om_MaritimeSurfaceResp;
         break;
      case CIGI_POSITION_RESP_PACKET_ID_V3:
         Proc_PositionResp(pPV);
         Omsg << Om_PositionResp;
         break;
      case CIGI_SOF_PACKET_ID_V3:
         Proc_SOF(pPV);
         Omsg << SOF;
         break;
      case CIGI_SENSOR_RESP_PACKET_ID_V3:
         Proc_SensorResp(pPV);
         Omsg << Om_SensorResp;
         break;
      case CIGI_SENSOR_XRESP_PACKET_ID_V3:
         Proc_SensorXResp(pPV);
         Omsg << Om_SensorXResp;
         break;
      case CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3:
         Proc_TerrestrialSurfaceResp(pPV);
         Omsg << Om_TerrestrialSurfaceResp;
         break;
      case CIGI_WEATHER_COND_RESP_PACKET_ID_V3:
         Proc_WeatherCondResp(pPV);
         Omsg << Om_WeatherCondResp;
         break;
      case CIGI_HAT_HOT_XRESP_PACKET_ID_V3:
         Proc_HatHotXResp(pPV);
         Omsg << Om_HatHotXResp;
         break;
      }

      try
      {
         ExIO->Send();
      }
      catch(CigiCalledOutOfSequenceException CCOOSE)
      {
         if(CCOOSE.HasMessage())
            printf("%s\n",CCOOSE.what());
      }
      catch(CigiImproperPacketException CIPE)
      {
         if(CIPE.HasMessage())
            printf("%s\n",CIPE.what());
      }
      catch(CigiBufferOverrunException CBOE)
      {
         if(CBOE.HasMessage())
            printf("%s\n",CBOE.what());
      }
      catch(CigiMissingStartOfFrameException CMSOFE)
      {
         if(CMSOFE.HasMessage())
            printf("%s\n",CMSOFE.what());
      }


   }

}

void IGMan::In()
{

   try
   {
      ExIO->Receive();
   }
   catch(CigiMissingIgControlException CMICE)
   {
      if(CMICE.HasMessage())
         printf("%s\n",CMICE.what());
   }

}






int IGMan::DeterminePckt(ParseValue *pPV)
{
   int Pckt = 0;

   char ltr = *pPV->GetStr();

   switch(ltr)
   {
   case 'A':
      if(strcmp(pPV->GetStr(),"AerosolResp") == 0)
         Pckt = CIGI_AEROSOL_RESP_PACKET_ID_V3;
      else if(strcmp(pPV->GetStr(),"AnimationStop") == 0)
         Pckt = CIGI_ANIMATION_STOP_PACKET_ID_V3;
      break;
   case 'C':
      if(strcmp(pPV->GetStr(),"CollDetSegResp") == 0)
         Pckt = CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3;
      else if(strcmp(pPV->GetStr(),"CollDetVolResp") == 0)
         Pckt = CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3;
      break;
   case 'E':
      if(strcmp(pPV->GetStr(),"EventNotification") == 0)
         Pckt = CIGI_EVENT_NOTIFICATION_PACKET_ID_V3;
      break;
   case 'H':
      if(strcmp(pPV->GetStr(),"HatHotResp") == 0)
         Pckt = CIGI_HAT_HOT_RESP_PACKET_ID_V3;
      else if(strcmp(pPV->GetStr(),"HatHotXResp") == 0)
         Pckt = CIGI_HAT_HOT_XRESP_PACKET_ID_V3;
      break;
   case 'I':
      if(strcmp(pPV->GetStr(),"IGMsg") == 0)
         Pckt = CIGI_IG_MSG_PACKET_ID_V3;
      break;
   case 'L':
      if(strcmp(pPV->GetStr(),"LosResp") == 0)
         Pckt = CIGI_LOS_RESP_PACKET_ID_V3;
      else if(strcmp(pPV->GetStr(),"LosXResp") == 0)
         Pckt = CIGI_LOS_XRESP_PACKET_ID_V3;
      break;
   case 'M':
      if(strcmp(pPV->GetStr(),"MaritimeSurfaceResp") == 0)
         Pckt = CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3;
      break;
   case 'P':
      if(strcmp(pPV->GetStr(),"PositionResp") == 0)
         Pckt = CIGI_POSITION_RESP_PACKET_ID_V3;
      break;
   case 'S':
      if(strcmp(pPV->GetStr(),"SOF") == 0)
         Pckt = CIGI_SOF_PACKET_ID_V3;
      else if(strcmp(pPV->GetStr(),"SensorResp") == 0)
         Pckt = CIGI_SENSOR_RESP_PACKET_ID_V3;
      else if(strcmp(pPV->GetStr(),"SensorXResp") == 0)
         Pckt = CIGI_SENSOR_XRESP_PACKET_ID_V3;
      break;
   case 'T':
      if(strcmp(pPV->GetStr(),"TerrestrialSurfaceResp") == 0)
         Pckt = CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3;
      break;
   case 'W':
      if(strcmp(pPV->GetStr(),"WeatherCondResp") == 0)
         Pckt = CIGI_WEATHER_COND_RESP_PACKET_ID_V3;
         break;
   }

   return(Pckt);

}



void IGMan::Proc_SOF(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         SOF.SetDatabaseID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         SOF.SetIGStatus(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         if(strcmp("Reset",pPV->GetStr()) == 0)
         {
            SOF.SetIGMode(CigiBaseSOF::Reset,true);
         }
         else if(strcmp("Standby",pPV->GetStr()) == 0)
         {
            SOF.SetIGMode(CigiBaseSOF::Standby,true);
         }
         else if(strcmp("Operate",pPV->GetStr()) == 0)
         {
            SOF.SetIGMode(CigiBaseSOF::Operate,true);
         }
         else if(strcmp("debug",pPV->GetStr()) == 0)
         {
            SOF.SetIGMode(CigiBaseSOF::debug,true);
         }
         else if(strcmp("OfflineMaint",pPV->GetStr()) == 0)
         {
            SOF.SetIGMode(CigiBaseSOF::OfflineMaint,true);
         }
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         SOF.SetTimeStampValid(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         SOF.SetFrameCntr(pPV->GetULong(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         SOF.SetTimeStamp(pPV->GetULong(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_CollDetSegResp(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetSegResp.SetEntityID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetSegResp.SetSegID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         if(strcmp("NonEntity",pPV->GetStr()) == 0)
         {
            Om_CollDetSegResp.SetCollType(CigiBaseCollDetSegResp::NonEntity,true);
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_CollDetSegResp.SetCollType(CigiBaseCollDetSegResp::Entity,true);
         }
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetSegResp.SetCollEntityID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetSegResp.SetMaterial(pPV->GetULong(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetSegResp.SetIntersectDist(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_SensorResp(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_SensorResp.SetViewID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorResp.SetSensorID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         if(strcmp("Searching",pPV->GetStr()) == 0)
         {
            Om_SensorResp.SetSensorStat(CigiBaseSensorResp::Searching,true);
         }
         else if(strcmp("Tracking",pPV->GetStr()) == 0)
         {
            Om_SensorResp.SetSensorStat(CigiBaseSensorResp::Tracking,true);
         }
         else if(strcmp("NearBrakeLock",pPV->GetStr()) == 0)
         {
            Om_SensorResp.SetSensorStat(CigiBaseSensorResp::NearBrakeLock,true);
         }
         else if(strcmp("BrakeLock",pPV->GetStr()) == 0)
         {
            Om_SensorResp.SetSensorStat(CigiBaseSensorResp::BrakeLock,true);
         }
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorResp.SetGateSzX(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorResp.SetGateSzY(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorResp.SetGateXoff(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorResp.SetGateYoff(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorResp.SetFrameCntr(pPV->GetULong(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_SensorXResp(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_SensorXResp.SetViewID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorXResp.SetSensorID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         if(strcmp("Searching",pPV->GetStr()) == 0)
         {
            Om_SensorXResp.SetSensorStat(CigiBaseSensorResp::Searching,true);
         }
         else if(strcmp("Tracking",pPV->GetStr()) == 0)
         {
            Om_SensorXResp.SetSensorStat(CigiBaseSensorResp::Tracking,true);
         }
         else if(strcmp("NearBrakeLock",pPV->GetStr()) == 0)
         {
            Om_SensorXResp.SetSensorStat(CigiBaseSensorResp::NearBrakeLock,true);
         }
         else if(strcmp("BrakeLock",pPV->GetStr()) == 0)
         {
            Om_SensorXResp.SetSensorStat(CigiBaseSensorResp::BrakeLock,true);
         }
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorXResp.SetEntityTgt(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorXResp.SetEntityID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorXResp.SetGateSzX(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorXResp.SetGateSzY(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorXResp.SetGateXoff(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorXResp.SetGateYoff(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorXResp.SetFrameCntr(pPV->GetULong(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorXResp.SetTrackPntLat(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorXResp.SetTrackPntLon(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SensorXResp.SetTrackPntAlt(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_LosResp(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_LosResp.SetLosID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosResp.SetValid(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosResp.SetEntityIDValid(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosResp.SetVisible(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosResp.SetRespCount(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosResp.SetEntityID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosResp.SetRange(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_LosXResp(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetLosID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetValid(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetEntityIDValid(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetRangeValid(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetVisible(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         if(strcmp("Geodetic",pPV->GetStr()) == 0)
         {
            Om_LosXResp.SetIntersectionCoordSys(CigiBaseLosResp::Geodetic,true);
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_LosXResp.SetIntersectionCoordSys(CigiBaseLosResp::Entity,true);
         }
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetRespCount(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetEntityID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetRange(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetXoff(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetYoff(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetZoff(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetRed(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetGreen(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetBlue(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetAlpha(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetMaterial(pPV->GetULong(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetNormalAz(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_LosXResp.SetNormalEl(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_HatHotResp(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_HatHotResp.SetHatHotID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_HatHotResp.SetValid(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         if(strcmp("HAT",pPV->GetStr()) == 0)
         {
            Om_HatHotResp.SetReqType(CigiBaseHatHotResp::HAT,true);
         }
         else if(strcmp("HOT",pPV->GetStr()) == 0)
         {
            Om_HatHotResp.SetReqType(CigiBaseHatHotResp::HOT,true);
         }
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_HatHotResp.SetHat(pPV->Getdouble(),true);
         Om_HatHotResp.SetHot(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_HatHotXResp(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_HatHotXResp.SetHatHotID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_HatHotXResp.SetValid(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_HatHotXResp.SetHat(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_HatHotXResp.SetHot(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_HatHotXResp.SetMaterial(pPV->GetULong(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_HatHotXResp.SetNormAz(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_HatHotXResp.SetNormEl(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_CollDetVolResp(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolResp.SetEntityID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolResp.SetVolID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         if(strcmp("NonEntity",pPV->GetStr()) == 0)
         {
            Om_CollDetVolResp.SetCollType(CigiBaseCollDetVolResp::NonEntity,true);
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_CollDetVolResp.SetCollType(CigiBaseCollDetVolResp::Entity,true);
         }
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolResp.SetCollEntityID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolResp.SetCollVolID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_PositionResp(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_PositionResp.SetObjectID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_PositionResp.SetArtPartID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_PositionResp.SetObjectClass(CigiBasePositionResp::Entity,true);
         }
         else if(strcmp("ArtPart",pPV->GetStr()) == 0)
         {
            Om_PositionResp.SetObjectClass(CigiBasePositionResp::ArtPart,true);
         }
         else if(strcmp("View",pPV->GetStr()) == 0)
         {
            Om_PositionResp.SetObjectClass(CigiBasePositionResp::View,true);
         }
         else if(strcmp("ViewGrp",pPV->GetStr()) == 0)
         {
            Om_PositionResp.SetObjectClass(CigiBasePositionResp::ViewGrp,true);
         }
         else if(strcmp("MotionTracker",pPV->GetStr()) == 0)
         {
            Om_PositionResp.SetObjectClass(CigiBasePositionResp::MotionTracker,true);
         }
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         if(strcmp("Geodetic",pPV->GetStr()) == 0)
         {
            Om_PositionResp.SetCoordSys(CigiBasePositionResp::Geodetic,true);
         }
         else if(strcmp("ParentEntity",pPV->GetStr()) == 0)
         {
            Om_PositionResp.SetCoordSys(CigiBasePositionResp::ParentEntity,true);
         }
         else if(strcmp("Submodel",pPV->GetStr()) == 0)
         {
            Om_PositionResp.SetCoordSys(CigiBasePositionResp::Submodel,true);
         }
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_PositionResp.SetLatOrXoff(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_PositionResp.SetLonOrYoff(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_PositionResp.SetAltOrZoff(pPV->Getdouble(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_PositionResp.SetRoll(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_PositionResp.SetPitch(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_PositionResp.SetYaw(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_WeatherCondResp(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_WeatherCondResp.SetRequestID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_WeatherCondResp.SetHumidity(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_WeatherCondResp.SetAirTemp(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_WeatherCondResp.SetVisibility(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_WeatherCondResp.SetHorizWindSp(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_WeatherCondResp.SetVertWindSp(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_WeatherCondResp.SetWindDir(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_WeatherCondResp.SetBaroPress(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_AerosolResp(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_AerosolResp.SetRequestID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_AerosolResp.SetLayerID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_AerosolResp.SetAerosolConcentration(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_MaritimeSurfaceResp(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_MaritimeSurfaceResp.SetRequestID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_MaritimeSurfaceResp.SetSurfaceHeight(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_MaritimeSurfaceResp.SetWaterTemp(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_MaritimeSurfaceResp.SetClarity(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_TerrestrialSurfaceResp(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_TerrestrialSurfaceResp.SetRequestID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_TerrestrialSurfaceResp.SetSurfaceConditionID(pPV->GetULong(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_AnimationStop(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_AnimationStop.SetEntityID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_EventNotification(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_EventNotification.SetEventID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_EventNotification.SetEventData(pPV->GetULong(),0,true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_EventNotification.SetEventData(pPV->GetULong(),1,true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_EventNotification.SetEventData(pPV->GetULong(),2,true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}

void IGMan::Proc_IGMsg(ParseValue *pPV)
{
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_IGMsg.SetMsgID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_IGMsg.SetMsg(pPV->GetStr(),true);
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();

}
