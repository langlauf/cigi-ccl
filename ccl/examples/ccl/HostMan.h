// HostMan.h: interface for the HostMan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOSTMAN_H__0291733E_2058_4BA7_91D5_E7D14AAFC1CA__INCLUDED_)
#define AFX_HOSTMAN_H__0291733E_2058_4BA7_91D5_E7D14AAFC1CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "AllCigi.h"
#include "ParseLine.h"
#include "ParseValue.h"
#include "ExampleIO.h"


#include "XSOF.h"
#include "XCollDetSegResp.h"
#include "XSensorResp.h"
#include "XSensorXResp.h"
#include "XLosResp.h"
#include "XLosXResp.h"
#include "XHatHotResp.h"
#include "XHatHotXResp.h"
#include "XCollDetVolResp.h"
#include "XPositionResp.h"
#include "XWeatherCondResp.h"
#include "XAerosolResp.h"
#include "XMaritimeSurfaceResp.h"
#include "XTerrestrialSurfaceResp.h"
#include "XAnimationStop.h"
#include "XEventNotification.h"
#include "XIGMsg.h"

#include "GenProc.h"

#include "SignalProcessing.h"



class HostMan  
{
public:
	HostMan(unsigned char *MsgXferBuf, int *MsgSz);
	virtual ~HostMan();


	void In(void);
	void Out(ParseLine &PrsLn);



protected:
	unsigned char * MsgXfer;
   int * pMsgSz;
   ExampleIO *ExIO;



   CigiIGCtrlV3 IGCtrl;


	int DeterminePckt(ParseValue *pPV);

   CigiHostSession Hsn;

   SignalProcessing SigProc;

   int TstID;

   char *DefHex;

   // Cigi objects used to send packets
   CigiEntityCtrlV3 Om_EntityCtrl;
   CigiConfClampEntityCtrlV3 Om_ConfClampEntityCtrl;
   CigiCompCtrlV3 Om_CompCtrl;
   CigiShortCompCtrlV3 Om_ShortCompCtrl;
   CigiArtPartCtrlV3 Om_ArtPartCtrl;
   CigiShortArtPartCtrlV3 Om_ShortArtPartCtrl;
   CigiRateCtrlV3 Om_RateCtrl;
   CigiCelestialCtrlV3 Om_CelestialCtrl;
   CigiAtmosCtrlV3 Om_AtmosCtrl;
   CigiEnvRgnCtrlV3 Om_EnvRgnCtrl;
   CigiWeatherCtrlV3 Om_WeatherCtrl;
   CigiMaritimeSurfaceCtrlV3 Om_MaritimeSurfaceCtrl;
   CigiWaveCtrlV3 Om_WaveCtrl;
   CigiTerrestrialSurfaceCtrlV3 Om_TerrestrialSurfaceCtrl;
   CigiViewCtrlV3 Om_ViewCtrl;
   CigiSensorCtrlV3 Om_SensorCtrl;
   CigiMotionTrackCtrlV3 Om_MotionTrackCtrl;
   CigiEarthModelDefV3 Om_EarthModelDef;
   CigiTrajectoryDefV3 Om_Trajectory;
   CigiViewDefV3 Om_ViewDef;
   CigiCollDetSegDefV3 Om_CollDetSegDef;
   CigiCollDetVolDefV3 Om_CollDetVolDef;
   CigiHatHotReqV3 Om_HatHotReq;
   CigiLosSegReqV3 Om_LosSegReq;
   CigiLosVectReqV3 Om_LosVectReq;
   CigiPositionReqV3 Om_PositionReq;
   CigiEnvCondReqV3 Om_EnvCondReq;



   // parsing routines to fill in packets
   void Proc_IGCtrl(ParseValue *pPV);
   void Proc_EntityCtrl(ParseValue *pPV);
   void Proc_ConfClampEntityCtrl(ParseValue *pPV);
   void Proc_CompCtrl(ParseValue *pPV);
   void Proc_ShortCompCtrl(ParseValue *pPV);
   void Proc_ArtPartCtrl(ParseValue *pPV);
   void Proc_ShortArtPartCtrl(ParseValue *pPV);
   void Proc_RateCtrl(ParseValue *pPV);
   void Proc_CelestialCtrl(ParseValue *pPV);
   void Proc_AtmosCtrl(ParseValue *pPV);
   void Proc_EnvRgnCtrl(ParseValue *pPV);
   void Proc_WeatherCtrl(ParseValue *pPV);
   void Proc_MaritimeSurfaceCtrl(ParseValue *pPV);
   void Proc_WaveCtrl(ParseValue *pPV);
   void Proc_TerrestrialSurfaceCtrl(ParseValue *pPV);
   void Proc_ViewCtrl(ParseValue *pPV);
   void Proc_SensorCtrl(ParseValue *pPV);
   void Proc_MotionTrackCtrl(ParseValue *pPV);
   void Proc_EarthModelDef(ParseValue *pPV);
   void Proc_Trajectory(ParseValue *pPV);
   void Proc_ViewDef(ParseValue *pPV);
   void Proc_CollDetSegDef(ParseValue *pPV);
   void Proc_CollDetVolDef(ParseValue *pPV);
   void Proc_HatHotReq(ParseValue *pPV);
   void Proc_LosSegReq(ParseValue *pPV);
   void Proc_LosVectReq(ParseValue *pPV);
   void Proc_PostionReq(ParseValue *pPV);
   void Proc_EnvCondReq(ParseValue *pPV);


   //Event classes to work with incoming packets
   XSOF Pr_SOF;
   XCollDetSegResp Pr_CollDetSegResp;
   XSensorResp Pr_SensorResp;
   XSensorXResp Pr_SensorXResp;
   XLosResp Pr_LosResp;
   XLosXResp Pr_LosXResp;
   XHatHotResp Pr_HatHotResp;
   XHatHotXResp Pr_HatHotXResp;
   XCollDetVolResp Pr_CollDetVolResp;
   XPositionResp Pr_PositionResp;
   XWeatherCondResp Pr_WeatherCondResp;
   XAerosolResp Pr_AerosolResp;
   XMaritimeSurfaceResp Pr_MaritimeSurfaceResp;
   XTerrestrialSurfaceResp Pr_TerrestrialSurfaceResp;
   XAnimationStop Pr_AnimationStop;
   XEventNotification Pr_EventNotification;
   XIGMsg Pr_IGMsg;

   GenProc AllProc;


};

#endif // !defined(AFX_HOSTMAN_H__0291733E_2058_4BA7_91D5_E7D14AAFC1CA__INCLUDED_)
