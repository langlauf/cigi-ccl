// HostMan.cpp: implementation of the HostMan class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "HostMan.h"

#include "Callbacks.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HostMan::HostMan(unsigned char *MsgXferBuf, int *MsgSz)
{

   MsgXfer = MsgXferBuf;
   pMsgSz = MsgSz;



   TstID = 0;

   // Get the outgoing msg manager
   CigiOutgoingMsg &Omsg = Hsn.GetOutgoingMsgMgr();

   // Get incoming message manager
   CigiIncomingMsg &Imsg = Hsn.GetIncomingMsgMgr();

   // Set up IO
   ExIO = new ExampleIO(Imsg,Omsg,MsgXfer,pMsgSz);

   // Set up cigi interface version
   Hsn.SetCigiVersion(3);

   // Set as synchronous
   Hsn.SetSynchronous(true);

   Imsg.SetReaderCigiVersion(3);

   Imsg.UsingIteration(false);

   // Set up IGCtrl & SOF
   try
   {
      IGCtrl.SetDatabaseID(1,false);
      IGCtrl.SetIGMode(CigiBaseIGCtrl::Operate,false);
   }
   catch(CigiValueOutOfRangeException ORX)
   {
      if(ORX.HasMessage())
         printf("%s\n",ORX.what());
   }


   // Register all the Event processors
   Imsg.RegisterEventProcessor(CIGI_SOF_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_SOF);
   Imsg.RegisterEventProcessor(CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_CollDetSegResp);
   Imsg.RegisterEventProcessor(CIGI_SENSOR_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_SensorResp);
   Imsg.RegisterEventProcessor(CIGI_SENSOR_XRESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_SensorXResp);
   Imsg.RegisterEventProcessor(CIGI_LOS_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_LosResp);
   Imsg.RegisterEventProcessor(CIGI_LOS_XRESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_LosXResp);
   Imsg.RegisterEventProcessor(CIGI_HAT_HOT_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_HatHotResp);
   Imsg.RegisterEventProcessor(CIGI_HAT_HOT_XRESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_HatHotXResp);
   Imsg.RegisterEventProcessor(CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_CollDetVolResp);
   Imsg.RegisterEventProcessor(CIGI_POSITION_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_PositionResp);
   Imsg.RegisterEventProcessor(CIGI_WEATHER_COND_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_WeatherCondResp);
   Imsg.RegisterEventProcessor(CIGI_AEROSOL_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_AerosolResp);
   Imsg.RegisterEventProcessor(CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_MaritimeSurfaceResp);
   Imsg.RegisterEventProcessor(CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_TerrestrialSurfaceResp);
   Imsg.RegisterEventProcessor(CIGI_ANIMATION_STOP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_AnimationStop);
   Imsg.RegisterEventProcessor(CIGI_EVENT_NOTIFICATION_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_EventNotification);
   Imsg.RegisterEventProcessor(CIGI_IG_MSG_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_IGMsg);

	Imsg.RegisterEventProcessor(0, (CigiBaseEventProcessor *) &AllProc);



   // Register all the callback processors
   Imsg.RegisterCallBack(CIGI_SOF_PACKET_ID_V3,
                              (CigiCBProcessor) &YSOF);
   Imsg.RegisterCallBack(CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YCollDetSegResp);
   Imsg.RegisterCallBack(CIGI_SENSOR_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YSensorResp);
   Imsg.RegisterCallBack(CIGI_SENSOR_XRESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YSensorXResp);
   Imsg.RegisterCallBack(CIGI_LOS_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YLosResp);
   Imsg.RegisterCallBack(CIGI_LOS_XRESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YLosXResp);
   Imsg.RegisterCallBack(CIGI_HAT_HOT_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YHatHotResp);
   Imsg.RegisterCallBack(CIGI_HAT_HOT_XRESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YHatHotXResp);
   Imsg.RegisterCallBack(CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YCollDetVolResp);
   Imsg.RegisterCallBack(CIGI_POSITION_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YPositionResp);
   Imsg.RegisterCallBack(CIGI_WEATHER_COND_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YWeatherCondResp);
   Imsg.RegisterCallBack(CIGI_AEROSOL_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YAerosolResp);
   Imsg.RegisterCallBack(CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YMaritimeSurfaceResp);
   Imsg.RegisterCallBack(CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YTerrestrialSurfaceResp);
   Imsg.RegisterCallBack(CIGI_ANIMATION_STOP_PACKET_ID_V3,
                              (CigiCBProcessor) &YAnimationStop);
   Imsg.RegisterCallBack(CIGI_EVENT_NOTIFICATION_PACKET_ID_V3,
                              (CigiCBProcessor) &YEventNotification);
   Imsg.RegisterCallBack(CIGI_IG_MSG_PACKET_ID_V3,
                              (CigiCBProcessor) &YIGMsg);

	Imsg.RegisterCallBack(0, (CigiCBProcessor) &YDeflt);



   // Register the signal processor object
   Imsg.RegisterSignalProcessor(&SigProc);


}

HostMan::~HostMan()
{

}

void HostMan::Out(ParseLine &PrsLn)
{


   // Get the outgoing msg manager
   CigiOutgoingMsg &Omsg = Hsn.GetOutgoingMsgMgr();

   TstID++;
   printf("\n\n=======HOST=========\n#Test No. %d\n",TstID);

   ParseValue *pPV = PrsLn.Get1stVal();

   int Pckt = DeterminePckt(pPV);




   if(Pckt != 0)
   {

      Omsg << IGCtrl;

//    Process the line and data
//    and pack i.e. "Omsg << Entity"


      switch(Pckt)
      {
      case 1:
         Proc_ArtPartCtrl(pPV);
         Omsg << Om_ArtPartCtrl;
         break;
      case 2:
         Proc_AtmosCtrl(pPV);
         Omsg << Om_AtmosCtrl;
         break;
      case 3:
         Proc_CelestialCtrl(pPV);
         Omsg << Om_CelestialCtrl;
         break;
      case 4:
         Proc_CollDetSegDef(pPV);
         Omsg << Om_CollDetSegDef;
         break;
      case 5:
         Proc_CollDetVolDef(pPV);
         Omsg << Om_CollDetVolDef;
         break;
      case 6:
         Proc_CompCtrl(pPV);
         Omsg << Om_CompCtrl;
         break;
      case 7:
         Proc_ConfClampEntityCtrl(pPV);
         Omsg << Om_ConfClampEntityCtrl;
         break;
      case 8:
         Proc_EarthModelDef(pPV);
         Omsg << Om_EarthModelDef;
         break;
      case 9:
         Proc_EntityCtrl(pPV);
         Omsg << Om_EntityCtrl;
         break;
      case 10:
         Proc_EnvCondReq(pPV);
         Omsg << Om_EnvCondReq;
         break;
      case 11:
         Proc_EnvRgnCtrl(pPV);
         Omsg << Om_EnvRgnCtrl;
         break;
      case 12:
         Proc_HatHotReq(pPV);
         Omsg << Om_HatHotReq;
         break;
      case 13:
         break;
      case 14:
         Proc_LosSegReq(pPV);
         Omsg << Om_LosSegReq;
         break;
      case 15:
         Proc_LosVectReq(pPV);
         Omsg << Om_LosVectReq;
         break;
      case 16:
         Proc_MaritimeSurfaceCtrl(pPV);
         Omsg << Om_MaritimeSurfaceCtrl;
         break;
      case 17:
         Proc_MotionTrackCtrl(pPV);
         Omsg << Om_MotionTrackCtrl;
         break;
      case 18:
         Proc_PostionReq(pPV);
         Omsg << Om_PositionReq;
         break;
      case 19:
         Proc_RateCtrl(pPV);
         Omsg << Om_RateCtrl;
         break;
      case 20:
         Proc_SensorCtrl(pPV);
         Omsg << Om_SensorCtrl;
         break;
      case 21:
         Proc_ShortArtPartCtrl(pPV);
         Omsg << Om_ShortArtPartCtrl;
         break;
      case 22:
         Proc_ShortCompCtrl(pPV);
         Omsg << Om_ShortCompCtrl;
         break;
      case 23:
         Proc_TerrestrialSurfaceCtrl(pPV);
         Omsg << Om_TerrestrialSurfaceCtrl;
         break;
      case 24:
         Proc_Trajectory(pPV);
         Omsg << Om_Trajectory;
         break;
      case 25:
         Proc_ViewCtrl(pPV);
         Omsg << Om_ViewCtrl;
         break;
      case 26:
         Proc_ViewDef(pPV);
         Omsg << Om_ViewDef;
         break;
      case 27:
         Proc_WaveCtrl(pPV);
         Omsg << Om_WaveCtrl;
         break;
      case 28:
         Proc_WeatherCtrl(pPV);
         Omsg << Om_WeatherCtrl;
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

void HostMan::In()
{

   try
   {
      ExIO->Receive();
   }
   catch(CigiMissingStartOfFrameException CMSOFE)
   {
      if(CMSOFE.HasMessage())
         printf("%s\n",CMSOFE.what());
   }

}



int HostMan::DeterminePckt(ParseValue *pPV)
{
   int Pckt = 0;

   char ltr = *pPV->GetStr();

   switch(ltr)
   {
   case 'A':
      if(strcmp(pPV->GetStr(),"ArtPartCtrl") == 0)
         Pckt = 1;
      else if(strcmp(pPV->GetStr(),"AtmosCtrl") == 0)
         Pckt = 2;
      break;
   case 'C':
      if(strcmp(pPV->GetStr(),"CelestialCtrl") == 0)
         Pckt = 3;
      else if(strcmp(pPV->GetStr(),"CollDetSegDef") == 0)
         Pckt = 4;
      else if(strcmp(pPV->GetStr(),"CollDetVolDef") == 0)
         Pckt = 5;
      else if(strcmp(pPV->GetStr(),"CompCtrl") == 0)
         Pckt = 6;
      else if(strcmp(pPV->GetStr(),"ConfClampEntityCtrl") == 0)
         Pckt = 7;
      break;
   case 'E':
      if(strcmp(pPV->GetStr(),"EarthModelDef") == 0)
         Pckt = 8;
      else if(strcmp(pPV->GetStr(),"EntityCtrl") == 0)
         Pckt = 9;
      else if(strcmp(pPV->GetStr(),"EnvCondReq") == 0)
         Pckt = 10;
      else if(strcmp(pPV->GetStr(),"EnvRgnCtrl") == 0)
         Pckt = 11;
      break;
   case 'H':
      if(strcmp(pPV->GetStr(),"HatHotReq") == 0)
         Pckt = 12;
      break;
   case 'I':
      if(strcmp(pPV->GetStr(),"IGCtrl") == 0)
         Pckt = 13;
      break;
   case 'L':
      if(strcmp(pPV->GetStr(),"LosSegReq") == 0)
         Pckt = 14;
      else if(strcmp(pPV->GetStr(),"LosVectReq") == 0)
         Pckt = 15;
      break;
   case 'M':
      if(strcmp(pPV->GetStr(),"MaritimeSurfaceCtrl") == 0)
         Pckt = 16;
      else if(strcmp(pPV->GetStr(),"MotionTrackCtrl") == 0)
         Pckt = 17;
      break;
   case 'P':
      if(strcmp(pPV->GetStr(),"PostionReq") == 0)
         Pckt = 18;
      break;
   case 'R':
      if(strcmp(pPV->GetStr(),"RateCtrl") == 0)
         Pckt = 19;
      break;
   case 'S':
      if(strcmp(pPV->GetStr(),"SensorCtrl") == 0)
         Pckt = 20;
      else if(strcmp(pPV->GetStr(),"ShortArtPartCtrl") == 0)
         Pckt = 21;
      else if(strcmp(pPV->GetStr(),"ShortCompCtrl") == 0)
         Pckt = 22;
      break;
   case 'T':
      if(strcmp(pPV->GetStr(),"TerrestrialSurfaceCtrl") == 0)
         Pckt = 23;
      else if(strcmp(pPV->GetStr(),"Trajectory") == 0)
         Pckt = 24;
      break;
   case 'V':
      if(strcmp(pPV->GetStr(),"ViewCtrl") == 0)
         Pckt = 25;
      else if(strcmp(pPV->GetStr(),"ViewDef") == 0)
         Pckt = 26;
      break;
   case 'W':
      if(strcmp(pPV->GetStr(),"WaveCtrl") == 0)
         Pckt = 27;
      else if(strcmp(pPV->GetStr(),"WeatherCtrl") == 0)
         Pckt = 28;
         break;
   }

   return(Pckt);

}



void HostMan::Proc_EntityCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_EntityCtrl.SetEntityID(pPV->GetUShort(),true);
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
         if(strcmp("Standby",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEntityState(CigiBaseEntityCtrl::Standby,true);
         }
         else if(strcmp("Active",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEntityState(CigiBaseEntityCtrl::Active,true);
         }
         else if(strcmp("Remove",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEntityState(CigiBaseEntityCtrl::Remove,true);
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
         if(strcmp("Detach",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAttachState(CigiBaseEntityCtrl::Detach,true);
         }
         else if(strcmp("Attach",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAttachState(CigiBaseEntityCtrl::Attach,true);
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
         if(strcmp("Disable",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetCollisionDetectEn(CigiBaseEntityCtrl::Disable,true);
         }
         else if(strcmp("Enable",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetCollisionDetectEn(CigiBaseEntityCtrl::Enable,true);
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
         if(strcmp("NoInherit",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetInheritAlpha(CigiBaseEntityCtrl::NoInherit,true);
         }
         else if(strcmp("Inherit",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetInheritAlpha(CigiBaseEntityCtrl::Inherit,true);
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
         if(strcmp("NoClamp",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetGrndClamp(CigiBaseEntityCtrl::NoClamp,true);
         }
         else if(strcmp("AltClamp",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetGrndClamp(CigiBaseEntityCtrl::AltClamp,true);
         }
         else if(strcmp("AltAttClamp",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetGrndClamp(CigiBaseEntityCtrl::AltAttClamp,true);
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
         if(strcmp("Forward",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationDir(CigiBaseEntityCtrl::Forward,true);
         }
         else if(strcmp("Backward",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationDir(CigiBaseEntityCtrl::Backward,true);
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
         if(strcmp("OneShot",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationLoopMode(CigiBaseEntityCtrl::OneShot,true);
         }
         else if(strcmp("Continuous",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationLoopMode(CigiBaseEntityCtrl::Continuous,true);
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
         if(strcmp("Stop",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Stop,true);
         }
         else if(strcmp("Pause",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Pause,true);
         }
         else if(strcmp("Play",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Play,true);
         }
         else if(strcmp("Continue",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Continue,true);
         }
         else if(strcmp("NoAction",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::NoAction,true);
         }
         else if(strcmp("Load",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Load,true);
         }
         else if(strcmp("LoadActivate",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::LoadActivate,true);
         }
         else if(strcmp("Activate",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Activate,true);
         }
         else if(strcmp("Deactivate",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Deactivate,true);
         }
         else if(strcmp("DeactivateUnload",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::DeactivateUnload,true);
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
         Om_EntityCtrl.SetAlpha(pPV->GetUChar(),true);
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
         Om_EntityCtrl.SetEntityType(pPV->GetUShort(),true);
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
         Om_EntityCtrl.SetParentID(pPV->GetUShort(),true);
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
         Om_EntityCtrl.SetRoll(pPV->Getfloat(),true);
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
         Om_EntityCtrl.SetPitch(pPV->Getfloat(),true);
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
         Om_EntityCtrl.SetYaw(pPV->Getfloat(),true);
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
         Om_EntityCtrl.SetXoff(pPV->Getdouble(),true);
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
         Om_EntityCtrl.SetYoff(pPV->Getdouble(),true);
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
         Om_EntityCtrl.SetZoff(pPV->Getdouble(),true);
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

void HostMan::Proc_ConfClampEntityCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_ConfClampEntityCtrl.SetEntityID(pPV->GetUShort(),true);
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
         Om_ConfClampEntityCtrl.SetYaw(pPV->Getfloat(),true);
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
         Om_ConfClampEntityCtrl.SetLat(pPV->Getdouble(),true);
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
         Om_ConfClampEntityCtrl.SetLon(pPV->Getdouble(),true);
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

void HostMan::Proc_CompCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_CompCtrl.SetCompID(pPV->GetUShort(),true);
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
         Om_CompCtrl.SetInstanceID(pPV->GetUShort(),true);
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
         if(strcmp("EntityV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::EntityV3,true);
         }
         else if(strcmp("ViewV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::ViewV3,true);
         }
         else if(strcmp("ViewGrpV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::ViewGrpV3,true);
         }
         else if(strcmp("SensorV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::SensorV3,true);
         }
         else if(strcmp("RegionalSeaSurfaceV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::RegionalSeaSurfaceV3,true);
         }
         else if(strcmp("RegionalTerrainSurfaceV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::RegionalTerrainSurfaceV3,true);
         }
         else if(strcmp("RegionalLayeredWeatherV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::RegionalLayeredWeatherV3,true);
         }
         else if(strcmp("GlobalSeaSurfaceV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::GlobalSeaSurfaceV3,true);
         }
         else if(strcmp("GlobalTerrainSurfaceV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::GlobalTerrainSurfaceV3,true);
         }
         else if(strcmp("GlobalLayeredWeatherV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::GlobalLayeredWeatherV3,true);
         }
         else if(strcmp("AtmosphereV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::AtmosphereV3,true);
         }
         else if(strcmp("CelestialSphereV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::CelestialSphereV3,true);
         }
         else if(strcmp("EventV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::EventV3,true);
         }
         else if(strcmp("SystemV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::SystemV3,true);
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
         Om_CompCtrl.SetCompState(pPV->GetUShort(),true);
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
         Om_CompCtrl.SetCompData(pPV->GetULong(),0,true);
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
         Om_CompCtrl.SetCompData(pPV->GetULong(),1,true);
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
         Om_CompCtrl.SetCompData(pPV->GetULong(),2,true);
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
         Om_CompCtrl.SetCompData(pPV->GetULong(),3,true);
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
         Om_CompCtrl.SetCompData(pPV->GetULong(),4,true);
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
         Om_CompCtrl.SetCompData(pPV->GetULong(),5,true);
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

void HostMan::Proc_ShortCompCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_ShortCompCtrl.SetCompID(pPV->GetUShort(),true);
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
         Om_ShortCompCtrl.SetInstanceID(pPV->GetUShort(),true);
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
         if(strcmp("EntityV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::EntityV3,true);
         }
         else if(strcmp("ViewV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::ViewV3,true);
         }
         else if(strcmp("ViewGrpV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::ViewGrpV3,true);
         }
         else if(strcmp("SensorV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::SensorV3,true);
         }
         else if(strcmp("RegionalSeaSurfaceV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::RegionalSeaSurfaceV3,true);
         }
         else if(strcmp("RegionalTerrainSurfaceV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::RegionalTerrainSurfaceV3,true);
         }
         else if(strcmp("RegionalLayeredWeatherV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::RegionalLayeredWeatherV3,true);
         }
         else if(strcmp("GlobalSeaSurfaceV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::GlobalSeaSurfaceV3,true);
         }
         else if(strcmp("GlobalTerrainSurfaceV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::GlobalTerrainSurfaceV3,true);
         }
         else if(strcmp("GlobalLayeredWeatherV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::GlobalLayeredWeatherV3,true);
         }
         else if(strcmp("AtmosphereV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::AtmosphereV3,true);
         }
         else if(strcmp("CelestialSphereV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::CelestialSphereV3,true);
         }
         else if(strcmp("EventV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::EventV3,true);
         }
         else if(strcmp("SystemV3",pPV->GetStr()) == 0)
         {
            Om_ShortCompCtrl.SetCompClassV3(CigiBaseCompCtrl::SystemV3,true);
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
         Om_ShortCompCtrl.SetCompState(pPV->GetUShort(),true);
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
         Om_ShortCompCtrl.SetCompData(pPV->GetULong(),0,true);
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
         Om_ShortCompCtrl.SetCompData(pPV->GetULong(),1,true);
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

void HostMan::Proc_ArtPartCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_ArtPartCtrl.SetEntityID(pPV->GetUShort(),true);
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
         Om_ArtPartCtrl.SetArtPartID(pPV->GetUChar(),true);
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
         Om_ArtPartCtrl.SetArtPartEn(pPV->GetBool(),true);
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
         Om_ArtPartCtrl.SetXOffEn(pPV->GetBool(),true);
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
         Om_ArtPartCtrl.SetYOffEn(pPV->GetBool(),true);
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
         Om_ArtPartCtrl.SetZOffEn(pPV->GetBool(),true);
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
         Om_ArtPartCtrl.SetRollEn(pPV->GetBool(),true);
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
         Om_ArtPartCtrl.SetPitchEn(pPV->GetBool(),true);
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
         Om_ArtPartCtrl.SetYawEn(pPV->GetBool(),true);
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
         Om_ArtPartCtrl.SetXOff(pPV->Getfloat(),true);
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
         Om_ArtPartCtrl.SetYOff(pPV->Getfloat(),true);
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
         Om_ArtPartCtrl.SetZOff(pPV->Getfloat(),true);
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
         Om_ArtPartCtrl.SetRoll(pPV->Getfloat(),true);
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
         Om_ArtPartCtrl.SetPitch(pPV->Getfloat(),true);
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
         Om_ArtPartCtrl.SetYaw(pPV->Getfloat(),true);
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

void HostMan::Proc_ShortArtPartCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_ShortArtPartCtrl.SetEntityID(pPV->GetUShort(),true);
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
         Om_ShortArtPartCtrl.SetArtPart1(pPV->GetUChar(),true);
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
         Om_ShortArtPartCtrl.SetArtPart2(pPV->GetUChar(),true);
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
         if(strcmp("NotUsed",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::NotUsed,true);
         }
         else if(strcmp("Xoff",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::Xoff,true);
         }
         else if(strcmp("Yoff",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::Yoff,true);
         }
         else if(strcmp("Zoff",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::Zoff,true);
         }
         else if(strcmp("Yaw",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::Yaw,true);
         }
         else if(strcmp("Pitch",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::Pitch,true);
         }
         else if(strcmp("Roll",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::Roll,true);
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
         if(strcmp("NotUsed",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::NotUsed,true);
         }
         else if(strcmp("Xoff",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::Xoff,true);
         }
         else if(strcmp("Yoff",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::Yoff,true);
         }
         else if(strcmp("Zoff",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::Zoff,true);
         }
         else if(strcmp("Yaw",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::Yaw,true);
         }
         else if(strcmp("Pitch",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::Pitch,true);
         }
         else if(strcmp("Roll",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::Roll,true);
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
         Om_ShortArtPartCtrl.SetArtPart1En(pPV->GetBool(),true);
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
         Om_ShortArtPartCtrl.SetArtPart2En(pPV->GetBool(),true);
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
         Om_ShortArtPartCtrl.SetDof1(pPV->Getfloat(),true);
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
         Om_ShortArtPartCtrl.SetDof2(pPV->Getfloat(),true);
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

void HostMan::Proc_RateCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_RateCtrl.SetEntityID(pPV->GetUShort(),true);
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
         Om_RateCtrl.SetArtPartID(pPV->GetUChar(),true);
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
         Om_RateCtrl.SetApplyToArtPart(pPV->GetBool(),true);
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
         Om_RateCtrl.SetXRate(pPV->Getfloat(),true);
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
         Om_RateCtrl.SetYRate(pPV->Getfloat(),true);
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
         Om_RateCtrl.SetZRate(pPV->Getfloat(),true);
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
         Om_RateCtrl.SetRollRate(pPV->Getfloat(),true);
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
         Om_RateCtrl.SetPitchRate(pPV->Getfloat(),true);
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
         Om_RateCtrl.SetYawRate(pPV->Getfloat(),true);
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

void HostMan::Proc_CelestialCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_CelestialCtrl.SetHour(pPV->GetUChar(),true);
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
         Om_CelestialCtrl.SetMinute(pPV->GetUChar(),true);
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
         Om_CelestialCtrl.SetEphemerisEn(pPV->GetBool(),true);
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
         Om_CelestialCtrl.SetSunEn(pPV->GetBool(),true);
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
         Om_CelestialCtrl.SetMoonEn(pPV->GetBool(),true);
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
         Om_CelestialCtrl.SetStarEn(pPV->GetBool(),true);
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
         Om_CelestialCtrl.SetDateVld(pPV->GetBool(),true);
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
         Om_CelestialCtrl.SetMonth(pPV->GetUChar(),true);
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
         Om_CelestialCtrl.SetDay(pPV->GetUChar(),true);
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
         Om_CelestialCtrl.SetYear(pPV->GetUShort(),true);
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
         Om_CelestialCtrl.SetStarInt(pPV->Getfloat(),true);
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

void HostMan::Proc_AtmosCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_AtmosCtrl.SetAtmosEn(pPV->GetBool(),true);
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
         Om_AtmosCtrl.SetHumidity(pPV->GetUChar(),true);
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
         Om_AtmosCtrl.SetAirTemp(pPV->Getfloat(),true);
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
         Om_AtmosCtrl.SetVisibility(pPV->Getfloat(),true);
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
         Om_AtmosCtrl.SetHorizWindSp(pPV->Getfloat(),true);
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
         Om_AtmosCtrl.SetVertWindSp(pPV->Getfloat(),true);
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
         Om_AtmosCtrl.SetWindDir(pPV->Getfloat(),true);
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
         Om_AtmosCtrl.SetBaroPress(pPV->Getfloat(),true);
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

void HostMan::Proc_EnvRgnCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_EnvRgnCtrl.SetRegionID(pPV->GetUShort(),true);
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
         if(strcmp("Inactive",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetRgnState(CigiBaseEnvRgnCtrl::Inactive,true);
         }
         else if(strcmp("Active",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetRgnState(CigiBaseEnvRgnCtrl::Active,true);
         }
         else if(strcmp("Destroyed",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetRgnState(CigiBaseEnvRgnCtrl::Destroyed,true);
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
         if(strcmp("UseLast",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetWeatherProp(CigiBaseEnvRgnCtrl::UseLast,true);
         }
         else if(strcmp("Merge",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetWeatherProp(CigiBaseEnvRgnCtrl::Merge,true);
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
         if(strcmp("UseLast",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetAerosol(CigiBaseEnvRgnCtrl::UseLast,true);
         }
         else if(strcmp("Merge",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetAerosol(CigiBaseEnvRgnCtrl::Merge,true);
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
         if(strcmp("UseLast",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetMaritimeSurface(CigiBaseEnvRgnCtrl::UseLast,true);
         }
         else if(strcmp("Merge",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetMaritimeSurface(CigiBaseEnvRgnCtrl::Merge,true);
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
         if(strcmp("UseLast",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetTerrestrialSurface(CigiBaseEnvRgnCtrl::UseLast,true);
         }
         else if(strcmp("Merge",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetTerrestrialSurface(CigiBaseEnvRgnCtrl::Merge,true);
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
         Om_EnvRgnCtrl.SetLat(pPV->Getdouble(),true);
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
         Om_EnvRgnCtrl.SetLon(pPV->Getdouble(),true);
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
         Om_EnvRgnCtrl.SetXSize(pPV->Getfloat(),true);
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
         Om_EnvRgnCtrl.SetYSize(pPV->Getfloat(),true);
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
         Om_EnvRgnCtrl.SetCornerRadius(pPV->Getfloat(),true);
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
         Om_EnvRgnCtrl.SetRotation(pPV->Getfloat(),true);
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
         Om_EnvRgnCtrl.SetTransition(pPV->Getfloat(),true);
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

void HostMan::Proc_WeatherCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         unsigned short ts = pPV->GetUShort();
         Om_WeatherCtrl.SetEntityID(ts,true);
         Om_WeatherCtrl.SetRegionID(ts,true);
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
         Om_WeatherCtrl.SetLayerID(pPV->GetUChar(),true);
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
         Om_WeatherCtrl.SetHumidity(pPV->GetUChar(),true);
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
         Om_WeatherCtrl.SetWeatherEn(pPV->GetBool(),true);
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
         Om_WeatherCtrl.SetScudEn(pPV->GetBool(),true);
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
         Om_WeatherCtrl.SetRandomWindsEn(pPV->GetBool(),true);
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
         Om_WeatherCtrl.SetRandomLightningEn(pPV->GetBool(),true);
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
         if(strcmp("None",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::None,true);
         }
         else if(strcmp("Altocumulus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Altocumulus,true);
         }
         else if(strcmp("Altostratus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Altostratus,true);
         }
         else if(strcmp("Cirrocumulus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Cirrocumulus,true);
         }
         else if(strcmp("Cirrostratus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Cirrostratus,true);
         }
         else if(strcmp("Cirrus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Cirrus,true);
         }
         else if(strcmp("Cumulonimbus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Cumulonimbus,true);
         }
         else if(strcmp("Cumulus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Cumulus,true);
         }
         else if(strcmp("Nimbostratus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Nimbostratus,true);
         }
         else if(strcmp("Stratocumulus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Stratocumulus,true);
         }
         else if(strcmp("Stratus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Stratus,true);
         }
         else if(strcmp("DefA",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::DefA,true);
         }
         else if(strcmp("DefB",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::DefB,true);
         }
         else if(strcmp("DefC",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::DefC,true);
         }
         else if(strcmp("DefD",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::DefD,true);
         }
         else if(strcmp("DefE",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::DefE,true);
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
         if(strcmp("Global",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetScope(CigiBaseWeatherCtrl::Global,true);
         }
         else if(strcmp("Regional",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetScope(CigiBaseWeatherCtrl::Regional,true);
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetScope(CigiBaseWeatherCtrl::Entity,true);
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
         Om_WeatherCtrl.SetSeverity(pPV->GetUChar(),true);
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
         Om_WeatherCtrl.SetAirTemp(pPV->Getfloat(),true);
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
         Om_WeatherCtrl.SetVisibilityRng(pPV->Getfloat(),true);
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
         Om_WeatherCtrl.SetScudFreq(pPV->Getfloat(),true);
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
         Om_WeatherCtrl.SetCoverage(pPV->Getfloat(),true);
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
         Om_WeatherCtrl.SetBaseElev(pPV->Getfloat(),true);
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
         Om_WeatherCtrl.SetThickness(pPV->Getfloat(),true);
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
         Om_WeatherCtrl.SetTransition(pPV->Getfloat(),true);
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
         Om_WeatherCtrl.SetHorizWindSp(pPV->Getfloat(),true);
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
         Om_WeatherCtrl.SetVertWindSp(pPV->Getfloat(),true);
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
         Om_WeatherCtrl.SetWindDir(pPV->Getfloat(),true);
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
         Om_WeatherCtrl.SetBaroPress(pPV->Getfloat(),true);
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
         Om_WeatherCtrl.SetAerosol(pPV->Getfloat(),true);
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

void HostMan::Proc_MaritimeSurfaceCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_MaritimeSurfaceCtrl.SetEntityRgnID(pPV->GetUShort(),true);
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
         Om_MaritimeSurfaceCtrl.SetSurfaceCondEn(pPV->GetBool(),true);
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
         Om_MaritimeSurfaceCtrl.SetWhitecapEn(pPV->GetBool(),true);
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
         if(strcmp("Global",pPV->GetStr()) == 0)
         {
            Om_MaritimeSurfaceCtrl.SetScope(CigiBaseMaritimeSurfaceCtrl::Global,true);
         }
         else if(strcmp("Regional",pPV->GetStr()) == 0)
         {
            Om_MaritimeSurfaceCtrl.SetScope(CigiBaseMaritimeSurfaceCtrl::Regional,true);
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_MaritimeSurfaceCtrl.SetScope(CigiBaseMaritimeSurfaceCtrl::Entity,true);
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
         Om_MaritimeSurfaceCtrl.SetSurfaceHeight(pPV->Getfloat(),true);
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
         Om_MaritimeSurfaceCtrl.SetWaterTemp(pPV->Getfloat(),true);
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
         Om_MaritimeSurfaceCtrl.SetClarity(pPV->Getfloat(),true);
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

void HostMan::Proc_WaveCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_WaveCtrl.SetEntityRgnID(pPV->GetUShort(),true);
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
         Om_WaveCtrl.SetWaveID(pPV->GetUChar(),true);
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
         Om_WaveCtrl.SetWaveEn(pPV->GetBool(),true);
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
         if(strcmp("Global",pPV->GetStr()) == 0)
         {
            Om_WaveCtrl.SetScope(CigiBaseWaveCtrl::Global,true);
         }
         else if(strcmp("Regional",pPV->GetStr()) == 0)
         {
            Om_WaveCtrl.SetScope(CigiBaseWaveCtrl::Regional,true);
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_WaveCtrl.SetScope(CigiBaseWaveCtrl::Entity,true);
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
         if(strcmp("Plunging",pPV->GetStr()) == 0)
         {
            Om_WaveCtrl.SetBreaker(CigiBaseWaveCtrl::Plunging,true);
         }
         else if(strcmp("Spilling",pPV->GetStr()) == 0)
         {
            Om_WaveCtrl.SetBreaker(CigiBaseWaveCtrl::Spilling,true);
         }
         else if(strcmp("Surging",pPV->GetStr()) == 0)
         {
            Om_WaveCtrl.SetBreaker(CigiBaseWaveCtrl::Surging,true);
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
         Om_WaveCtrl.SetWaveHt(pPV->Getfloat(),true);
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
         Om_WaveCtrl.SetWaveLen(pPV->Getfloat(),true);
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
         Om_WaveCtrl.SetPeriod(pPV->Getfloat(),true);
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
         Om_WaveCtrl.SetDirection(pPV->Getfloat(),true);
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
         Om_WaveCtrl.SetPhaseOff(pPV->Getfloat(),true);
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
         Om_WaveCtrl.SetLeading(pPV->Getfloat(),true);
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

void HostMan::Proc_TerrestrialSurfaceCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_TerrestrialSurfaceCtrl.SetEntityRgnID(pPV->GetUShort(),true);
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
         Om_TerrestrialSurfaceCtrl.SetSurfaceCondID(pPV->GetUShort(),true);
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
         Om_TerrestrialSurfaceCtrl.SetSurfaceCondEn(pPV->GetBool(),true);
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
         if(strcmp("Global",pPV->GetStr()) == 0)
         {
            Om_TerrestrialSurfaceCtrl.SetScope(CigiBaseTerrestrialSurfaceCtrl::Global,true);
         }
         else if(strcmp("Regional",pPV->GetStr()) == 0)
         {
            Om_TerrestrialSurfaceCtrl.SetScope(CigiBaseTerrestrialSurfaceCtrl::Regional,true);
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_TerrestrialSurfaceCtrl.SetScope(CigiBaseTerrestrialSurfaceCtrl::Entity,true);
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
         Om_TerrestrialSurfaceCtrl.SetSeverity(pPV->GetUChar(),true);
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
         Om_TerrestrialSurfaceCtrl.SetCoverage(pPV->GetUChar(),true);
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

void HostMan::Proc_ViewCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetViewID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX) {}

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetGroupID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetXOffEn(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetYOffEn(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetZOffEn(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetRollEn(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetPitchEn(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetYawEn(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetEntityID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetXOff(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetYOff(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetZOff(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetRoll(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetPitch(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_ViewCtrl.SetYaw(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();


}

void HostMan::Proc_SensorCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_SensorCtrl.SetViewID(pPV->GetUShort(),true);
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
         Om_SensorCtrl.SetSensorID(pPV->GetUChar(),true);
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
         Om_SensorCtrl.SetSensorOn(pPV->GetBool(),true);
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
         if(strcmp("WhiteHot",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetPolarity(CigiBaseSensorCtrl::WhiteHot,true);
         }
         else if(strcmp("BlackHot",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetPolarity(CigiBaseSensorCtrl::BlackHot,true);
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
         Om_SensorCtrl.SetLineDropEn(pPV->GetBool(),true);
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
         Om_SensorCtrl.SetAutoGainEn(pPV->GetBool(),true);
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
         if(strcmp("TrackWhite",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackPolarity(CigiBaseSensorCtrl::TrackWhite,true);
         }
         else if(strcmp("TrackBlack",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackPolarity(CigiBaseSensorCtrl::TrackBlack,true);
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
         if(strcmp("GatePos",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetResponseType(CigiBaseSensorCtrl::GatePos,true);
         }
         else if(strcmp("GateAndTargetPos",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetResponseType(CigiBaseSensorCtrl::GateAndTargetPos,true);
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
         if(strcmp("TrackOff",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::TrackOff,true);
         }
         else if(strcmp("ForceCorrelate",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::ForceCorrelate,true);
         }
         else if(strcmp("Scene",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::Scene,true);
         }
         else if(strcmp("Target",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::Target,true);
         }
         else if(strcmp("Ship",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::Ship,true);
         }
         else if(strcmp("TMDefA",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::TMDefA,true);
         }
         else if(strcmp("TMDefB",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::TMDefB,true);
         }
         else if(strcmp("TMDefC",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::TMDefC,true);
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
         Om_SensorCtrl.SetGain(pPV->Getfloat(),true);
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
         Om_SensorCtrl.SetLevel(pPV->Getfloat(),true);
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
         Om_SensorCtrl.SetACCoupling(pPV->Getfloat(),true);
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
         Om_SensorCtrl.SetNoise(pPV->Getfloat(),true);
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

void HostMan::Proc_MotionTrackCtrl(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_MotionTrackCtrl.SetViewID(pPV->GetUShort(),true);
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
         Om_MotionTrackCtrl.SetTrackerID(pPV->GetUChar(),true);
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
         Om_MotionTrackCtrl.SetTrackerEn(pPV->GetBool(),true);
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
         Om_MotionTrackCtrl.SetBoresightEn(pPV->GetBool(),true);
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
         Om_MotionTrackCtrl.SetXEn(pPV->GetBool(),true);
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
         Om_MotionTrackCtrl.SetYEn(pPV->GetBool(),true);
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
         Om_MotionTrackCtrl.SetZEn(pPV->GetBool(),true);
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
         Om_MotionTrackCtrl.SetRollEn(pPV->GetBool(),true);
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
         Om_MotionTrackCtrl.SetPitchEn(pPV->GetBool(),true);
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
         Om_MotionTrackCtrl.SetYawEn(pPV->GetBool(),true);
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
         if(strcmp("View",pPV->GetStr()) == 0)
         {
            Om_MotionTrackCtrl.SetScope(CigiBaseMotionTrackCtrl::View,true);
         }
         else if(strcmp("ViewGrp",pPV->GetStr()) == 0)
         {
            Om_MotionTrackCtrl.SetScope(CigiBaseMotionTrackCtrl::ViewGrp,true);
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
      DefHex = pPV->GetStr();

}

void HostMan::Proc_EarthModelDef(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_EarthModelDef.SetCustomERMEn(pPV->GetBool(),true);
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
         Om_EarthModelDef.SetEquatorialRadius(pPV->Getdouble(),true);
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
         Om_EarthModelDef.SetFlattening(pPV->Getdouble(),true);
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

void HostMan::Proc_Trajectory(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_Trajectory.SetEntityID(pPV->GetUShort(),true);
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
         Om_Trajectory.SetAccelX(pPV->Getfloat(),true);
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
         Om_Trajectory.SetAccelY(pPV->Getfloat(),true);
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
         Om_Trajectory.SetAccelZ(pPV->Getfloat(),true);
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
         Om_Trajectory.SetRetardationRate(pPV->Getfloat(),true);
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
         Om_Trajectory.SetTermVel(pPV->Getfloat(),true);
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

void HostMan::Proc_ViewDef(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_ViewDef.SetViewID(pPV->GetUShort(),true);
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
         Om_ViewDef.SetGroupID(pPV->GetUChar(),true);
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
         Om_ViewDef.SetFOVNearEn(pPV->GetBool(),true);
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
         Om_ViewDef.SetFOVFarEn(pPV->GetBool(),true);
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
         Om_ViewDef.SetFOVLeftEn(pPV->GetBool(),true);
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
         Om_ViewDef.SetFOVRightEn(pPV->GetBool(),true);
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
         Om_ViewDef.SetFOVTopEn(pPV->GetBool(),true);
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
         Om_ViewDef.SetFOVBottomEn(pPV->GetBool(),true);
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
         if(strcmp("MirrorNone",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetMirrorMode(CigiBaseViewDef::MirrorNone,true);
         }
         else if(strcmp("Horizontal",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetMirrorMode(CigiBaseViewDef::Horizontal,true);
         }
         else if(strcmp("Vertical",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetMirrorMode(CigiBaseViewDef::Vertical,true);
         }
         else if(strcmp("Horiz_Vert",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetMirrorMode(CigiBaseViewDef::Horiz_Vert,true);
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
         if(strcmp("ReplicateNone",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::ReplicateNone,true);
         }
         else if(strcmp("Replicate1x2",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::Replicate1x2,true);
         }
         else if(strcmp("Replicate2x1",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::Replicate2x1,true);
         }
         else if(strcmp("Replicate2x2",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::Replicate2x2,true);
         }
         else if(strcmp("ReplicateDefA",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::ReplicateDefA,true);
         }
         else if(strcmp("ReplicateDefB",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::ReplicateDefB,true);
         }
         else if(strcmp("ReplicateDefC",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::ReplicateDefC,true);
         }
         else if(strcmp("ReplicateDefD",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::ReplicateDefD,true);
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
         if(strcmp("Perspective",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetProjectionType(CigiBaseViewDef::Perspective,true);
         }
         else if(strcmp("Orthographic",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetProjectionType(CigiBaseViewDef::Orthographic,true);
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
         Om_ViewDef.SetReorder(pPV->GetBool(),true);
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
         Om_ViewDef.SetViewType(pPV->GetUChar(),true);
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
         Om_ViewDef.SetFOVNear(pPV->Getfloat(),true);
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
         Om_ViewDef.SetFOVFar(pPV->Getfloat(),true);
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
         Om_ViewDef.SetFOVLeft(pPV->Getfloat(),true);
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
         Om_ViewDef.SetFOVRight(pPV->Getfloat(),true);
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
         Om_ViewDef.SetFOVTop(pPV->Getfloat(),true);
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
         Om_ViewDef.SetFOVBottom(pPV->Getfloat(),true);
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

void HostMan::Proc_CollDetSegDef(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetSegDef.SetEntityID(pPV->GetUShort(),true);
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
         Om_CollDetSegDef.SetSegmentID(pPV->GetUChar(),true);
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
         Om_CollDetSegDef.SetSegmentEn(pPV->GetBool(),true);
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
         Om_CollDetSegDef.SetX1(pPV->Getfloat(),true);
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
         Om_CollDetSegDef.SetY1(pPV->Getfloat(),true);
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
         Om_CollDetSegDef.SetZ1(pPV->Getfloat(),true);
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
         Om_CollDetSegDef.SetX2(pPV->Getfloat(),true);
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
         Om_CollDetSegDef.SetY2(pPV->Getfloat(),true);
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
         Om_CollDetSegDef.SetZ2(pPV->Getfloat(),true);
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
         Om_CollDetSegDef.SetMask(pPV->GetULong(),true);
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

void HostMan::Proc_CollDetVolDef(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolDef.SetEntityID(pPV->GetUShort(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolDef.SetVolID(pPV->GetUChar(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolDef.SetVolEn(pPV->GetBool(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         if(strcmp("Sphere",pPV->GetStr()) == 0)
         {
            Om_CollDetVolDef.SetVolType(CigiBaseCollDetVolDef::Sphere,true);
         }
         else if(strcmp("Cuboid",pPV->GetStr()) == 0)
         {
            Om_CollDetVolDef.SetVolType(CigiBaseCollDetVolDef::Cuboid,true);
         }
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolDef.SetXoff(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolDef.SetYoff(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolDef.SetZoff(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolDef.SetHeightOrRadius(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolDef.SetWidth(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolDef.SetDepth(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolDef.SetRoll(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolDef.SetPitch(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }
   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolDef.SetYaw(pPV->Getfloat(),true);
      }
      catch(CigiValueOutOfRangeException ORX) { }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
      DefHex = pPV->GetStr();


}

void HostMan::Proc_HatHotReq(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_HatHotReq.SetHatHotID(pPV->GetUShort(),true);
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
            Om_HatHotReq.SetReqType(CigiBaseHatHotReq::HAT,true);
         }
         else if(strcmp("HOT",pPV->GetStr()) == 0)
         {
            Om_HatHotReq.SetReqType(CigiBaseHatHotReq::HOT,true);
         }
         else if(strcmp("Extended",pPV->GetStr()) == 0)
         {
            Om_HatHotReq.SetReqType(CigiBaseHatHotReq::Extended,true);
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
            Om_HatHotReq.SetSrcCoordSys(CigiBaseHatHotReq::Geodetic,true);
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_HatHotReq.SetSrcCoordSys(CigiBaseHatHotReq::Entity,true);
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
         Om_HatHotReq.SetEntityID(pPV->GetUShort(),true);
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
         Om_HatHotReq.SetXoff(pPV->Getdouble(),true);
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
         Om_HatHotReq.SetYoff(pPV->Getdouble(),true);
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
         Om_HatHotReq.SetZoff(pPV->Getdouble(),true);
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

void HostMan::Proc_LosSegReq(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_LosSegReq.SetLosID(pPV->GetUShort(),true);
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
         if(strcmp("Basic",pPV->GetStr()) == 0)
         {
            Om_LosSegReq.SetReqType(CigiBaseLosSegReq::Basic,true);
         }
         else if(strcmp("Extended",pPV->GetStr()) == 0)
         {
            Om_LosSegReq.SetReqType(CigiBaseLosSegReq::Extended,true);
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
            Om_LosSegReq.SetSrcCoordSys(CigiBaseLosSegReq::Geodetic,true);
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_LosSegReq.SetSrcCoordSys(CigiBaseLosSegReq::Entity,true);
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
            Om_LosSegReq.SetDstCoordSys(CigiBaseLosSegReq::Geodetic,true);
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_LosSegReq.SetDstCoordSys(CigiBaseLosSegReq::Entity,true);
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
            Om_LosSegReq.SetResponseCoordSys(CigiBaseLosSegReq::Geodetic,true);
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_LosSegReq.SetResponseCoordSys(CigiBaseLosSegReq::Entity,true);
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
         Om_LosSegReq.SetAlphaThresh(pPV->GetUChar(),true);
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
         Om_LosSegReq.SetEntityID(pPV->GetUShort(),true);
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
         Om_LosSegReq.SetSrcXoff(pPV->Getdouble(),true);
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
         Om_LosSegReq.SetSrcYoff(pPV->Getdouble(),true);
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
         Om_LosSegReq.SetSrcZoff(pPV->Getdouble(),true);
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
         Om_LosSegReq.SetDstXoff(pPV->Getdouble(),true);
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
         Om_LosSegReq.SetDstYoff(pPV->Getdouble(),true);
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
         Om_LosSegReq.SetDstZoff(pPV->Getdouble(),true);
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
         Om_LosSegReq.SetMask(pPV->GetULong(),true);
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

void HostMan::Proc_LosVectReq(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_LosVectReq.SetLosID(pPV->GetUShort(),true);
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
         if(strcmp("Basic",pPV->GetStr()) == 0)
         {
            Om_LosVectReq.SetReqType(CigiBaseLosVectReq::Basic,true);
         }
         else if(strcmp("Extended",pPV->GetStr()) == 0)
         {
            Om_LosVectReq.SetReqType(CigiBaseLosVectReq::Extended,true);
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
            Om_LosVectReq.SetSrcCoordSys(CigiBaseLosVectReq::Geodetic,true);
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_LosVectReq.SetSrcCoordSys(CigiBaseLosVectReq::Entity,true);
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
            Om_LosVectReq.SetResponseCoordSys(CigiBaseLosVectReq::Geodetic,true);
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_LosVectReq.SetResponseCoordSys(CigiBaseLosVectReq::Entity,true);
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
         Om_LosVectReq.SetAlphaThresh(pPV->GetUChar(),true);
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
         Om_LosVectReq.SetEntityID(pPV->GetUShort(),true);
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
         Om_LosVectReq.SetVectAz(pPV->Getfloat(),true);
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
         Om_LosVectReq.SetVectEl(pPV->Getfloat(),true);
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
         Om_LosVectReq.SetMinRange(pPV->Getfloat(),true);
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
         Om_LosVectReq.SetMaxRange(pPV->Getfloat(),true);
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
         Om_LosVectReq.SetSrcXoff(pPV->Getdouble(),true);
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
         Om_LosVectReq.SetSrcYoff(pPV->Getdouble(),true);
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
         Om_LosVectReq.SetSrcZoff(pPV->Getdouble(),true);
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
         Om_LosVectReq.SetMask(pPV->GetULong(),true);
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

void HostMan::Proc_PostionReq(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_PositionReq.SetObjectID(pPV->GetUShort(),true);
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
         Om_PositionReq.SetArtPartID(pPV->GetUChar(),true);
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
         if(strcmp("OneShot",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetUpdateMode(CigiBasePositionReq::OneShot,true);
         }
         else if(strcmp("Continuous",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetUpdateMode(CigiBasePositionReq::Continuous,true);
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
         if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetObjectClass(CigiBasePositionReq::Entity,true);
         }
         else if(strcmp("ArtPart",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetObjectClass(CigiBasePositionReq::ArtPart,true);
         }
         else if(strcmp("View",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetObjectClass(CigiBasePositionReq::View,true);
         }
         else if(strcmp("ViewGrp",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetObjectClass(CigiBasePositionReq::ViewGrp,true);
         }
         else if(strcmp("MotionTracker",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetObjectClass(CigiBasePositionReq::MotionTracker,true);
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
            Om_PositionReq.SetCoordSys(CigiBasePositionReq::Geodetic,true);
         }
         else if(strcmp("ParentEntity",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetCoordSys(CigiBasePositionReq::ParentEntity,true);
         }
         else if(strcmp("Submodel",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetCoordSys(CigiBasePositionReq::Submodel,true);
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
      DefHex = pPV->GetStr();

}

void HostMan::Proc_EnvCondReq(ParseValue *pPV)
{

   pPV = pPV->nxt();  // skip the cmd name

   unsigned char tReqType = 0;

   if(pPV != NULL)
   {
      if(strcmp("Maritime",pPV->GetStr()) == 0)
      {
         tReqType = (unsigned char)CigiBaseEnvCondReq::Maritime;
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      if(strcmp("Terrestrial",pPV->GetStr()) == 0)
      {
         tReqType |= (unsigned char)CigiBaseEnvCondReq::Terrestrial;
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      if(strcmp("Weather",pPV->GetStr()) == 0)
      {
         tReqType |= (unsigned char)CigiBaseEnvCondReq::Weather;
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      if(strcmp("Aerosol",pPV->GetStr()) == 0)
      {
         tReqType |= (unsigned char)CigiBaseEnvCondReq::Aerosol;
      }

      pPV = pPV->nxt();
   }

   try
   {
      Om_EnvCondReq.SetReqType(tReqType,true);
   }
   catch(CigiValueOutOfRangeException ORX)
   {
      if(ORX.HasMessage())
         printf("%s\n",ORX.what());
   }


   if(pPV != NULL)
   {
      try
      {
         Om_EnvCondReq.SetLat(pPV->Getdouble(),true);
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
         Om_EnvCondReq.SetLon(pPV->Getdouble(),true);
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
         Om_EnvCondReq.SetAlt(pPV->Getdouble(),true);
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
