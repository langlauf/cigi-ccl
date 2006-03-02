// IGMan.h: interface for the IGMan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IGMAN_H__9394F78C_FD84_40D7_B80E_37F2A90EBDC3__INCLUDED_)
#define AFX_IGMAN_H__9394F78C_FD84_40D7_B80E_37F2A90EBDC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "AllCigi.h"
#include "ParseLine.h"
#include "ParseValue.h"
#include "ExampleIO.h"

#include "XIGCtrl.h"
#include "XEntityCtrl.h"
#include "XConfClampEntityCtrl.h"
#include "XCompCtrl.h"
#include "XShortCompCtrl.h"
#include "XArtPartCtrl.h"
#include "XShortArtPartCtrl.h"
#include "XRateCtrl.h"
#include "XCelestialCtrl.h"
#include "XAtmosCtrl.h"
#include "XEnvRgnCtrl.h"
#include "XWeatherCtrl.h"
#include "XMaritimeSurfaceCtrl.h"
#include "XWaveCtrl.h"
#include "XTerrestrialSurfaceCtrl.h"
#include "XViewCtrl.h"
#include "XSensorCtrl.h"
#include "XMotionTrackCtrl.h"
#include "XEarthModelDef.h"
#include "XTrajectory.h"
#include "XViewDef.h"
#include "XCollDetSegDef.h"
#include "XCollDetVolDef.h"
#include "XHatHotReq.h"
#include "XLosSegReq.h"
#include "XLosVectReq.h"
#include "XPostionReq.h"
#include "XEnvCondReq.h"

#include "GenProc.h"

#include "SignalProcessing.h"

class IGMan  
{
public:
	IGMan(unsigned char *MsgXferBuf, int *MsgSz);
	virtual ~IGMan();

	void In(void);
	void Out(ParseLine &PrsLn);




protected:
	unsigned char * MsgXfer;
   int * pMsgSz;
   ExampleIO *ExIO;


   CigiSOFV3 SOF;

   // routine to determine the current packet from csv data
	int DeterminePckt(ParseValue *pPV);

   CigiIGSession IGsn;

   SignalProcessing SigProc;

   int TstID;

   char *DefHex;

   //Event classes to work with incoming packets
   XIGCtrl Pr_IGCtrl;
   XEntityCtrl Pr_EntityCtrl;
   XConfClampEntityCtrl Pr_ConfClampEntityCtrl;
   XCompCtrl Pr_CompCtrl;
   XShortCompCtrl Pr_ShortCompCtrl;
   XArtPartCtrl Pr_ArtPartCtrl;
   XShortArtPartCtrl Pr_ShortArtPartCtrl;
   XRateCtrl Pr_RateCtrl;
   XCelestialCtrl Pr_CelestialCtrl;
   XAtmosCtrl Pr_AtmosCtrl;
   XEnvRgnCtrl Pr_EnvRgnCtrl;
   XWeatherCtrl Pr_WeatherCtrl;
   XMaritimeSurfaceCtrl Pr_MaritimeSurfaceCtrl;
   XWaveCtrl Pr_WaveCtrl;
   XTerrestrialSurfaceCtrl Pr_TerrestrialSurfaceCtrl;
   XViewCtrl Pr_ViewCtrl;
   XSensorCtrl Pr_SensorCtrl;
   XMotionTrackCtrl Pr_MotionTrackCtrl;
   XEarthModelDef Pr_EarthModelDef;
   XTrajectory Pr_Trajectory;
   XViewDef Pr_ViewDef;
   XCollDetSegDef Pr_CollDetSegDef;
   XCollDetVolDef Pr_CollDetVolDef;
   XHatHotReq Pr_HatHotReq;
   XLosSegReq Pr_LosSegReq;
   XLosVectReq Pr_LosVectReq;
   XPositionReq Pr_PositionReq;
   XEnvCondReq Pr_EnvCondReq;

   GenProc AllProc;  // Generic processor



   // Cigi objects used to send packets
   CigiCollDetSegRespV3 Om_CollDetSegResp;
   CigiSensorRespV3 Om_SensorResp;
   CigiSensorXRespV3 Om_SensorXResp;
   CigiLosRespV3 Om_LosResp;
   CigiLosXRespV3 Om_LosXResp;
   CigiHatHotRespV3 Om_HatHotResp;
   CigiHatHotXRespV3 Om_HatHotXResp;
   CigiCollDetVolRespV3 Om_CollDetVolResp;
   CigiPositionRespV3 Om_PositionResp;
   CigiWeatherCondRespV3 Om_WeatherCondResp;
   CigiAerosolRespV3 Om_AerosolResp;
   CigiMaritimeSurfaceRespV3 Om_MaritimeSurfaceResp;
   CigiTerrestrialSurfaceRespV3 Om_TerrestrialSurfaceResp;
   CigiAnimationStopV3 Om_AnimationStop;
   CigiEventNotificationV3 Om_EventNotification;
   CigiIGMsgV3 Om_IGMsg;



   // parsing routines to fill in packets
   void Proc_SOF(ParseValue *pPV);
   void Proc_CollDetSegResp(ParseValue *pPV);
   void Proc_SensorResp(ParseValue *pPV);
   void Proc_SensorXResp(ParseValue *pPV);
   void Proc_LosResp(ParseValue *pPV);
   void Proc_LosXResp(ParseValue *pPV);
   void Proc_HatHotResp(ParseValue *pPV);
   void Proc_HatHotXResp(ParseValue *pPV);
   void Proc_CollDetVolResp(ParseValue *pPV);
   void Proc_PositionResp(ParseValue *pPV);
   void Proc_WeatherCondResp(ParseValue *pPV);
   void Proc_AerosolResp(ParseValue *pPV);
   void Proc_MaritimeSurfaceResp(ParseValue *pPV);
   void Proc_TerrestrialSurfaceResp(ParseValue *pPV);
   void Proc_AnimationStop(ParseValue *pPV);
   void Proc_EventNotification(ParseValue *pPV);
   void Proc_IGMsg(ParseValue *pPV);



};

#endif // !defined(AFX_IGMAN_H__9394F78C_FD84_40D7_B80E_37F2A90EBDC3__INCLUDED_)
