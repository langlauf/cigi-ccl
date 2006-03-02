# Microsoft Developer Studio Generated NMAKE File, Based on CigiExample.dsp
!IF "$(CFG)" == ""
CFG=CigiExample - Win32 dllDebug
!MESSAGE No configuration specified. Defaulting to CigiExample - Win32 dllDebug.
!ENDIF 

!IF "$(CFG)" != "CigiExample - Win32 Release" && "$(CFG)" != "CigiExample - Win32 Debug" && "$(CFG)" != "CigiExample - Win32 dllDebug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CigiExample.mak" CFG="CigiExample - Win32 dllDebug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CigiExample - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "CigiExample - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "CigiExample - Win32 dllDebug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CigiExample - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\CigiExample.exe" "$(OUTDIR)\CigiExample.pch"


CLEAN :
	-@erase "$(INTDIR)\Callbacks.obj"
	-@erase "$(INTDIR)\CigiExample.obj"
	-@erase "$(INTDIR)\CigiExample.pch"
	-@erase "$(INTDIR)\ExampleIO.obj"
	-@erase "$(INTDIR)\GenProc.obj"
	-@erase "$(INTDIR)\HostMan.obj"
	-@erase "$(INTDIR)\IGMan.obj"
	-@erase "$(INTDIR)\ParseLine.obj"
	-@erase "$(INTDIR)\ParseValue.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XAerosolResp.obj"
	-@erase "$(INTDIR)\XAnimationStop.obj"
	-@erase "$(INTDIR)\XArtPartCtrl.obj"
	-@erase "$(INTDIR)\XAtmosCtrl.obj"
	-@erase "$(INTDIR)\XCelestialCtrl.obj"
	-@erase "$(INTDIR)\XCollDetSegDef.obj"
	-@erase "$(INTDIR)\XCollDetSegResp.obj"
	-@erase "$(INTDIR)\XCollDetVolDef.obj"
	-@erase "$(INTDIR)\XCollDetVolResp.obj"
	-@erase "$(INTDIR)\XCompCtrl.obj"
	-@erase "$(INTDIR)\XConfClampEntityCtrl.obj"
	-@erase "$(INTDIR)\XEarthModelDef.obj"
	-@erase "$(INTDIR)\XEntityCtrl.obj"
	-@erase "$(INTDIR)\XEnvCondReq.obj"
	-@erase "$(INTDIR)\XEnvRgnCtrl.obj"
	-@erase "$(INTDIR)\XEventNotification.obj"
	-@erase "$(INTDIR)\XHatHotReq.obj"
	-@erase "$(INTDIR)\XHatHotResp.obj"
	-@erase "$(INTDIR)\XHatHotXResp.obj"
	-@erase "$(INTDIR)\XIGCtrl.obj"
	-@erase "$(INTDIR)\XIGMsg.obj"
	-@erase "$(INTDIR)\XLosResp.obj"
	-@erase "$(INTDIR)\XLosSegReq.obj"
	-@erase "$(INTDIR)\XLosVectReq.obj"
	-@erase "$(INTDIR)\XLosXResp.obj"
	-@erase "$(INTDIR)\XMaritimeSurfaceCtrl.obj"
	-@erase "$(INTDIR)\XMaritimeSurfaceResp.obj"
	-@erase "$(INTDIR)\XMotionTrackCtrl.obj"
	-@erase "$(INTDIR)\XPositionResp.obj"
	-@erase "$(INTDIR)\XPostionReq.obj"
	-@erase "$(INTDIR)\XRateCtrl.obj"
	-@erase "$(INTDIR)\XSensorCtrl.obj"
	-@erase "$(INTDIR)\XSensorResp.obj"
	-@erase "$(INTDIR)\XSensorXResp.obj"
	-@erase "$(INTDIR)\XShortArtPartCtrl.obj"
	-@erase "$(INTDIR)\XShortCompCtrl.obj"
	-@erase "$(INTDIR)\XSOF.obj"
	-@erase "$(INTDIR)\XTerrestrialSurfaceCtrl.obj"
	-@erase "$(INTDIR)\XTerrestrialSurfaceResp.obj"
	-@erase "$(INTDIR)\XTrajectory.obj"
	-@erase "$(INTDIR)\XViewCtrl.obj"
	-@erase "$(INTDIR)\XViewDef.obj"
	-@erase "$(INTDIR)\XWaveCtrl.obj"
	-@erase "$(INTDIR)\XWeatherCondResp.obj"
	-@erase "$(INTDIR)\XWeatherCtrl.obj"
	-@erase "$(OUTDIR)\CigiExample.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /I ".\\" /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CigiExample.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ccl_lib.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\CigiExample.pdb" /machine:I386 /nodefaultlib:"LIBCMT" /out:"$(OUTDIR)\CigiExample.exe" /libpath:"..\..\bin\libReleaseST" 
LINK32_OBJS= \
	"$(INTDIR)\Callbacks.obj" \
	"$(INTDIR)\CigiExample.obj" \
	"$(INTDIR)\ExampleIO.obj" \
	"$(INTDIR)\GenProc.obj" \
	"$(INTDIR)\HostMan.obj" \
	"$(INTDIR)\IGMan.obj" \
	"$(INTDIR)\ParseLine.obj" \
	"$(INTDIR)\ParseValue.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\XAerosolResp.obj" \
	"$(INTDIR)\XAnimationStop.obj" \
	"$(INTDIR)\XArtPartCtrl.obj" \
	"$(INTDIR)\XAtmosCtrl.obj" \
	"$(INTDIR)\XCelestialCtrl.obj" \
	"$(INTDIR)\XCollDetSegDef.obj" \
	"$(INTDIR)\XCollDetSegResp.obj" \
	"$(INTDIR)\XCollDetVolDef.obj" \
	"$(INTDIR)\XCollDetVolResp.obj" \
	"$(INTDIR)\XCompCtrl.obj" \
	"$(INTDIR)\XConfClampEntityCtrl.obj" \
	"$(INTDIR)\XEarthModelDef.obj" \
	"$(INTDIR)\XEntityCtrl.obj" \
	"$(INTDIR)\XEnvCondReq.obj" \
	"$(INTDIR)\XEnvRgnCtrl.obj" \
	"$(INTDIR)\XEventNotification.obj" \
	"$(INTDIR)\XHatHotReq.obj" \
	"$(INTDIR)\XHatHotResp.obj" \
	"$(INTDIR)\XHatHotXResp.obj" \
	"$(INTDIR)\XIGCtrl.obj" \
	"$(INTDIR)\XIGMsg.obj" \
	"$(INTDIR)\XLosResp.obj" \
	"$(INTDIR)\XLosSegReq.obj" \
	"$(INTDIR)\XLosVectReq.obj" \
	"$(INTDIR)\XLosXResp.obj" \
	"$(INTDIR)\XMaritimeSurfaceCtrl.obj" \
	"$(INTDIR)\XMaritimeSurfaceResp.obj" \
	"$(INTDIR)\XMotionTrackCtrl.obj" \
	"$(INTDIR)\XPositionResp.obj" \
	"$(INTDIR)\XPostionReq.obj" \
	"$(INTDIR)\XRateCtrl.obj" \
	"$(INTDIR)\XSensorCtrl.obj" \
	"$(INTDIR)\XSensorResp.obj" \
	"$(INTDIR)\XSensorXResp.obj" \
	"$(INTDIR)\XShortArtPartCtrl.obj" \
	"$(INTDIR)\XShortCompCtrl.obj" \
	"$(INTDIR)\XSOF.obj" \
	"$(INTDIR)\XTerrestrialSurfaceCtrl.obj" \
	"$(INTDIR)\XTerrestrialSurfaceResp.obj" \
	"$(INTDIR)\XTrajectory.obj" \
	"$(INTDIR)\XViewCtrl.obj" \
	"$(INTDIR)\XViewDef.obj" \
	"$(INTDIR)\XWaveCtrl.obj" \
	"$(INTDIR)\XWeatherCondResp.obj" \
	"$(INTDIR)\XWeatherCtrl.obj"

"$(OUTDIR)\CigiExample.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CigiExample - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\CigiExample.exe" "$(OUTDIR)\CigiExample.pch"


CLEAN :
	-@erase "$(INTDIR)\Callbacks.obj"
	-@erase "$(INTDIR)\CigiExample.obj"
	-@erase "$(INTDIR)\CigiExample.pch"
	-@erase "$(INTDIR)\ExampleIO.obj"
	-@erase "$(INTDIR)\GenProc.obj"
	-@erase "$(INTDIR)\HostMan.obj"
	-@erase "$(INTDIR)\IGMan.obj"
	-@erase "$(INTDIR)\ParseLine.obj"
	-@erase "$(INTDIR)\ParseValue.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XAerosolResp.obj"
	-@erase "$(INTDIR)\XAnimationStop.obj"
	-@erase "$(INTDIR)\XArtPartCtrl.obj"
	-@erase "$(INTDIR)\XAtmosCtrl.obj"
	-@erase "$(INTDIR)\XCelestialCtrl.obj"
	-@erase "$(INTDIR)\XCollDetSegDef.obj"
	-@erase "$(INTDIR)\XCollDetSegResp.obj"
	-@erase "$(INTDIR)\XCollDetVolDef.obj"
	-@erase "$(INTDIR)\XCollDetVolResp.obj"
	-@erase "$(INTDIR)\XCompCtrl.obj"
	-@erase "$(INTDIR)\XConfClampEntityCtrl.obj"
	-@erase "$(INTDIR)\XEarthModelDef.obj"
	-@erase "$(INTDIR)\XEntityCtrl.obj"
	-@erase "$(INTDIR)\XEnvCondReq.obj"
	-@erase "$(INTDIR)\XEnvRgnCtrl.obj"
	-@erase "$(INTDIR)\XEventNotification.obj"
	-@erase "$(INTDIR)\XHatHotReq.obj"
	-@erase "$(INTDIR)\XHatHotResp.obj"
	-@erase "$(INTDIR)\XHatHotXResp.obj"
	-@erase "$(INTDIR)\XIGCtrl.obj"
	-@erase "$(INTDIR)\XIGMsg.obj"
	-@erase "$(INTDIR)\XLosResp.obj"
	-@erase "$(INTDIR)\XLosSegReq.obj"
	-@erase "$(INTDIR)\XLosVectReq.obj"
	-@erase "$(INTDIR)\XLosXResp.obj"
	-@erase "$(INTDIR)\XMaritimeSurfaceCtrl.obj"
	-@erase "$(INTDIR)\XMaritimeSurfaceResp.obj"
	-@erase "$(INTDIR)\XMotionTrackCtrl.obj"
	-@erase "$(INTDIR)\XPositionResp.obj"
	-@erase "$(INTDIR)\XPostionReq.obj"
	-@erase "$(INTDIR)\XRateCtrl.obj"
	-@erase "$(INTDIR)\XSensorCtrl.obj"
	-@erase "$(INTDIR)\XSensorResp.obj"
	-@erase "$(INTDIR)\XSensorXResp.obj"
	-@erase "$(INTDIR)\XShortArtPartCtrl.obj"
	-@erase "$(INTDIR)\XShortCompCtrl.obj"
	-@erase "$(INTDIR)\XSOF.obj"
	-@erase "$(INTDIR)\XTerrestrialSurfaceCtrl.obj"
	-@erase "$(INTDIR)\XTerrestrialSurfaceResp.obj"
	-@erase "$(INTDIR)\XTrajectory.obj"
	-@erase "$(INTDIR)\XViewCtrl.obj"
	-@erase "$(INTDIR)\XViewDef.obj"
	-@erase "$(INTDIR)\XWaveCtrl.obj"
	-@erase "$(INTDIR)\XWeatherCondResp.obj"
	-@erase "$(INTDIR)\XWeatherCtrl.obj"
	-@erase "$(OUTDIR)\CigiExample.exe"
	-@erase "$(OUTDIR)\CigiExample.ilk"
	-@erase "$(OUTDIR)\CigiExample.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CigiExample.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ccl_lib.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\CigiExample.pdb" /debug /machine:I386 /nodefaultlib:"LIBCMT" /out:"$(OUTDIR)\CigiExample.exe" /pdbtype:sept /libpath:"..\..\bin\libDebugST" 
LINK32_OBJS= \
	"$(INTDIR)\Callbacks.obj" \
	"$(INTDIR)\CigiExample.obj" \
	"$(INTDIR)\ExampleIO.obj" \
	"$(INTDIR)\GenProc.obj" \
	"$(INTDIR)\HostMan.obj" \
	"$(INTDIR)\IGMan.obj" \
	"$(INTDIR)\ParseLine.obj" \
	"$(INTDIR)\ParseValue.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\XAerosolResp.obj" \
	"$(INTDIR)\XAnimationStop.obj" \
	"$(INTDIR)\XArtPartCtrl.obj" \
	"$(INTDIR)\XAtmosCtrl.obj" \
	"$(INTDIR)\XCelestialCtrl.obj" \
	"$(INTDIR)\XCollDetSegDef.obj" \
	"$(INTDIR)\XCollDetSegResp.obj" \
	"$(INTDIR)\XCollDetVolDef.obj" \
	"$(INTDIR)\XCollDetVolResp.obj" \
	"$(INTDIR)\XCompCtrl.obj" \
	"$(INTDIR)\XConfClampEntityCtrl.obj" \
	"$(INTDIR)\XEarthModelDef.obj" \
	"$(INTDIR)\XEntityCtrl.obj" \
	"$(INTDIR)\XEnvCondReq.obj" \
	"$(INTDIR)\XEnvRgnCtrl.obj" \
	"$(INTDIR)\XEventNotification.obj" \
	"$(INTDIR)\XHatHotReq.obj" \
	"$(INTDIR)\XHatHotResp.obj" \
	"$(INTDIR)\XHatHotXResp.obj" \
	"$(INTDIR)\XIGCtrl.obj" \
	"$(INTDIR)\XIGMsg.obj" \
	"$(INTDIR)\XLosResp.obj" \
	"$(INTDIR)\XLosSegReq.obj" \
	"$(INTDIR)\XLosVectReq.obj" \
	"$(INTDIR)\XLosXResp.obj" \
	"$(INTDIR)\XMaritimeSurfaceCtrl.obj" \
	"$(INTDIR)\XMaritimeSurfaceResp.obj" \
	"$(INTDIR)\XMotionTrackCtrl.obj" \
	"$(INTDIR)\XPositionResp.obj" \
	"$(INTDIR)\XPostionReq.obj" \
	"$(INTDIR)\XRateCtrl.obj" \
	"$(INTDIR)\XSensorCtrl.obj" \
	"$(INTDIR)\XSensorResp.obj" \
	"$(INTDIR)\XSensorXResp.obj" \
	"$(INTDIR)\XShortArtPartCtrl.obj" \
	"$(INTDIR)\XShortCompCtrl.obj" \
	"$(INTDIR)\XSOF.obj" \
	"$(INTDIR)\XTerrestrialSurfaceCtrl.obj" \
	"$(INTDIR)\XTerrestrialSurfaceResp.obj" \
	"$(INTDIR)\XTrajectory.obj" \
	"$(INTDIR)\XViewCtrl.obj" \
	"$(INTDIR)\XViewDef.obj" \
	"$(INTDIR)\XWaveCtrl.obj" \
	"$(INTDIR)\XWeatherCondResp.obj" \
	"$(INTDIR)\XWeatherCtrl.obj"

"$(OUTDIR)\CigiExample.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CigiExample - Win32 dllDebug"

OUTDIR=.\dllDebug
INTDIR=.\dllDebug
# Begin Custom Macros
OutDir=.\dllDebug
# End Custom Macros

ALL : "$(OUTDIR)\CigiExample.exe" "$(OUTDIR)\CigiExample.pch"


CLEAN :
	-@erase "$(INTDIR)\Callbacks.obj"
	-@erase "$(INTDIR)\CigiExample.obj"
	-@erase "$(INTDIR)\CigiExample.pch"
	-@erase "$(INTDIR)\ExampleIO.obj"
	-@erase "$(INTDIR)\GenProc.obj"
	-@erase "$(INTDIR)\HostMan.obj"
	-@erase "$(INTDIR)\IGMan.obj"
	-@erase "$(INTDIR)\ParseLine.obj"
	-@erase "$(INTDIR)\ParseValue.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XAerosolResp.obj"
	-@erase "$(INTDIR)\XAnimationStop.obj"
	-@erase "$(INTDIR)\XArtPartCtrl.obj"
	-@erase "$(INTDIR)\XAtmosCtrl.obj"
	-@erase "$(INTDIR)\XCelestialCtrl.obj"
	-@erase "$(INTDIR)\XCollDetSegDef.obj"
	-@erase "$(INTDIR)\XCollDetSegResp.obj"
	-@erase "$(INTDIR)\XCollDetVolDef.obj"
	-@erase "$(INTDIR)\XCollDetVolResp.obj"
	-@erase "$(INTDIR)\XCompCtrl.obj"
	-@erase "$(INTDIR)\XConfClampEntityCtrl.obj"
	-@erase "$(INTDIR)\XEarthModelDef.obj"
	-@erase "$(INTDIR)\XEntityCtrl.obj"
	-@erase "$(INTDIR)\XEnvCondReq.obj"
	-@erase "$(INTDIR)\XEnvRgnCtrl.obj"
	-@erase "$(INTDIR)\XEventNotification.obj"
	-@erase "$(INTDIR)\XHatHotReq.obj"
	-@erase "$(INTDIR)\XHatHotResp.obj"
	-@erase "$(INTDIR)\XHatHotXResp.obj"
	-@erase "$(INTDIR)\XIGCtrl.obj"
	-@erase "$(INTDIR)\XIGMsg.obj"
	-@erase "$(INTDIR)\XLosResp.obj"
	-@erase "$(INTDIR)\XLosSegReq.obj"
	-@erase "$(INTDIR)\XLosVectReq.obj"
	-@erase "$(INTDIR)\XLosXResp.obj"
	-@erase "$(INTDIR)\XMaritimeSurfaceCtrl.obj"
	-@erase "$(INTDIR)\XMaritimeSurfaceResp.obj"
	-@erase "$(INTDIR)\XMotionTrackCtrl.obj"
	-@erase "$(INTDIR)\XPositionResp.obj"
	-@erase "$(INTDIR)\XPostionReq.obj"
	-@erase "$(INTDIR)\XRateCtrl.obj"
	-@erase "$(INTDIR)\XSensorCtrl.obj"
	-@erase "$(INTDIR)\XSensorResp.obj"
	-@erase "$(INTDIR)\XSensorXResp.obj"
	-@erase "$(INTDIR)\XShortArtPartCtrl.obj"
	-@erase "$(INTDIR)\XShortCompCtrl.obj"
	-@erase "$(INTDIR)\XSOF.obj"
	-@erase "$(INTDIR)\XTerrestrialSurfaceCtrl.obj"
	-@erase "$(INTDIR)\XTerrestrialSurfaceResp.obj"
	-@erase "$(INTDIR)\XTrajectory.obj"
	-@erase "$(INTDIR)\XViewCtrl.obj"
	-@erase "$(INTDIR)\XViewDef.obj"
	-@erase "$(INTDIR)\XWaveCtrl.obj"
	-@erase "$(INTDIR)\XWeatherCondResp.obj"
	-@erase "$(INTDIR)\XWeatherCtrl.obj"
	-@erase "$(OUTDIR)\CigiExample.exe"
	-@erase "$(OUTDIR)\CigiExample.ilk"
	-@erase "$(OUTDIR)\CigiExample.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /D "CCL_DLL" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CigiExample.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ccl_dll.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\CigiExample.pdb" /debug /machine:I386 /out:"$(OUTDIR)\CigiExample.exe" /pdbtype:sept /libpath:"..\..\bin\dllDebugMT_DLL" 
LINK32_OBJS= \
	"$(INTDIR)\Callbacks.obj" \
	"$(INTDIR)\CigiExample.obj" \
	"$(INTDIR)\ExampleIO.obj" \
	"$(INTDIR)\GenProc.obj" \
	"$(INTDIR)\HostMan.obj" \
	"$(INTDIR)\IGMan.obj" \
	"$(INTDIR)\ParseLine.obj" \
	"$(INTDIR)\ParseValue.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\XAerosolResp.obj" \
	"$(INTDIR)\XAnimationStop.obj" \
	"$(INTDIR)\XArtPartCtrl.obj" \
	"$(INTDIR)\XAtmosCtrl.obj" \
	"$(INTDIR)\XCelestialCtrl.obj" \
	"$(INTDIR)\XCollDetSegDef.obj" \
	"$(INTDIR)\XCollDetSegResp.obj" \
	"$(INTDIR)\XCollDetVolDef.obj" \
	"$(INTDIR)\XCollDetVolResp.obj" \
	"$(INTDIR)\XCompCtrl.obj" \
	"$(INTDIR)\XConfClampEntityCtrl.obj" \
	"$(INTDIR)\XEarthModelDef.obj" \
	"$(INTDIR)\XEntityCtrl.obj" \
	"$(INTDIR)\XEnvCondReq.obj" \
	"$(INTDIR)\XEnvRgnCtrl.obj" \
	"$(INTDIR)\XEventNotification.obj" \
	"$(INTDIR)\XHatHotReq.obj" \
	"$(INTDIR)\XHatHotResp.obj" \
	"$(INTDIR)\XHatHotXResp.obj" \
	"$(INTDIR)\XIGCtrl.obj" \
	"$(INTDIR)\XIGMsg.obj" \
	"$(INTDIR)\XLosResp.obj" \
	"$(INTDIR)\XLosSegReq.obj" \
	"$(INTDIR)\XLosVectReq.obj" \
	"$(INTDIR)\XLosXResp.obj" \
	"$(INTDIR)\XMaritimeSurfaceCtrl.obj" \
	"$(INTDIR)\XMaritimeSurfaceResp.obj" \
	"$(INTDIR)\XMotionTrackCtrl.obj" \
	"$(INTDIR)\XPositionResp.obj" \
	"$(INTDIR)\XPostionReq.obj" \
	"$(INTDIR)\XRateCtrl.obj" \
	"$(INTDIR)\XSensorCtrl.obj" \
	"$(INTDIR)\XSensorResp.obj" \
	"$(INTDIR)\XSensorXResp.obj" \
	"$(INTDIR)\XShortArtPartCtrl.obj" \
	"$(INTDIR)\XShortCompCtrl.obj" \
	"$(INTDIR)\XSOF.obj" \
	"$(INTDIR)\XTerrestrialSurfaceCtrl.obj" \
	"$(INTDIR)\XTerrestrialSurfaceResp.obj" \
	"$(INTDIR)\XTrajectory.obj" \
	"$(INTDIR)\XViewCtrl.obj" \
	"$(INTDIR)\XViewDef.obj" \
	"$(INTDIR)\XWaveCtrl.obj" \
	"$(INTDIR)\XWeatherCondResp.obj" \
	"$(INTDIR)\XWeatherCtrl.obj"

"$(OUTDIR)\CigiExample.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("CigiExample.dep")
!INCLUDE "CigiExample.dep"
!ELSE 
!MESSAGE Warning: cannot find "CigiExample.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "CigiExample - Win32 Release" || "$(CFG)" == "CigiExample - Win32 Debug" || "$(CFG)" == "CigiExample - Win32 dllDebug"
SOURCE=.\Callbacks.cpp

"$(INTDIR)\Callbacks.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\CigiExample.cpp

"$(INTDIR)\CigiExample.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ExampleIO.cpp

"$(INTDIR)\ExampleIO.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\GenProc.cpp

"$(INTDIR)\GenProc.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\HostMan.cpp

"$(INTDIR)\HostMan.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\IGMan.cpp

"$(INTDIR)\IGMan.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ParseLine.cpp

"$(INTDIR)\ParseLine.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ParseValue.cpp

"$(INTDIR)\ParseValue.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "CigiExample - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GX /O2 /I ".\\" /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\CigiExample.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CigiExample.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CigiExample - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /Fp"$(INTDIR)\CigiExample.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CigiExample.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CigiExample - Win32 dllDebug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /D "CCL_DLL" /Fp"$(INTDIR)\CigiExample.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CigiExample.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\XAerosolResp.cpp

"$(INTDIR)\XAerosolResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XAnimationStop.cpp

"$(INTDIR)\XAnimationStop.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XArtPartCtrl.cpp

"$(INTDIR)\XArtPartCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XAtmosCtrl.cpp

"$(INTDIR)\XAtmosCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XCelestialCtrl.cpp

"$(INTDIR)\XCelestialCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XCollDetSegDef.cpp

"$(INTDIR)\XCollDetSegDef.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XCollDetSegResp.cpp

"$(INTDIR)\XCollDetSegResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XCollDetVolDef.cpp

"$(INTDIR)\XCollDetVolDef.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XCollDetVolResp.cpp

"$(INTDIR)\XCollDetVolResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XCompCtrl.cpp

"$(INTDIR)\XCompCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XConfClampEntityCtrl.cpp

"$(INTDIR)\XConfClampEntityCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XEarthModelDef.cpp

"$(INTDIR)\XEarthModelDef.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XEntityCtrl.cpp

"$(INTDIR)\XEntityCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XEnvCondReq.cpp

"$(INTDIR)\XEnvCondReq.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XEnvRgnCtrl.cpp

"$(INTDIR)\XEnvRgnCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XEventNotification.cpp

"$(INTDIR)\XEventNotification.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XHatHotReq.cpp

"$(INTDIR)\XHatHotReq.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XHatHotResp.cpp

"$(INTDIR)\XHatHotResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XHatHotXResp.cpp

"$(INTDIR)\XHatHotXResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XIGCtrl.cpp

"$(INTDIR)\XIGCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XIGMsg.cpp

"$(INTDIR)\XIGMsg.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XLosResp.cpp

"$(INTDIR)\XLosResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XLosSegReq.cpp

"$(INTDIR)\XLosSegReq.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XLosVectReq.cpp

"$(INTDIR)\XLosVectReq.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XLosXResp.cpp

"$(INTDIR)\XLosXResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XMaritimeSurfaceCtrl.cpp

"$(INTDIR)\XMaritimeSurfaceCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XMaritimeSurfaceResp.cpp

"$(INTDIR)\XMaritimeSurfaceResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XMotionTrackCtrl.cpp

"$(INTDIR)\XMotionTrackCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XPositionResp.cpp

"$(INTDIR)\XPositionResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XPostionReq.cpp

"$(INTDIR)\XPostionReq.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XRateCtrl.cpp

"$(INTDIR)\XRateCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XSensorCtrl.cpp

"$(INTDIR)\XSensorCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XSensorResp.cpp

"$(INTDIR)\XSensorResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XSensorXResp.cpp

"$(INTDIR)\XSensorXResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XShortArtPartCtrl.cpp

"$(INTDIR)\XShortArtPartCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XShortCompCtrl.cpp

"$(INTDIR)\XShortCompCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XSOF.cpp

"$(INTDIR)\XSOF.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XTerrestrialSurfaceCtrl.cpp

"$(INTDIR)\XTerrestrialSurfaceCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XTerrestrialSurfaceResp.cpp

"$(INTDIR)\XTerrestrialSurfaceResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XTrajectory.cpp

"$(INTDIR)\XTrajectory.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XViewCtrl.cpp

"$(INTDIR)\XViewCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XViewDef.cpp

"$(INTDIR)\XViewDef.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XWaveCtrl.cpp

"$(INTDIR)\XWaveCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XWeatherCondResp.cpp

"$(INTDIR)\XWeatherCondResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XWeatherCtrl.cpp

"$(INTDIR)\XWeatherCtrl.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

