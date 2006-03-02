# Microsoft Developer Studio Generated NMAKE File, Based on CigiExample.dsp
!IF "$(CFG)" == ""
CFG=CigiExample - Win32 Debug
!MESSAGE No configuration specified. Defaulting to CigiExample - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CigiExample - Win32 Release" && "$(CFG)" != "CigiExample - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CigiExample.mak" CFG="CigiExample - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CigiExample - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "CigiExample - Win32 Debug" (based on "Win32 (x86) Console Application")
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

ALL : "$(OUTDIR)\ccl_xig.exe" "$(OUTDIR)\CigiExample.pch"


CLEAN :
	-@erase "$(INTDIR)\Callbacks.obj"
	-@erase "$(INTDIR)\CigiExample.obj"
	-@erase "$(INTDIR)\CigiExample.pch"
	-@erase "$(INTDIR)\ExampleIO.obj"
	-@erase "$(INTDIR)\GenProc.obj"
	-@erase "$(INTDIR)\IGMan.obj"
	-@erase "$(INTDIR)\Network.obj"
	-@erase "$(INTDIR)\ParseLine.obj"
	-@erase "$(INTDIR)\ParseValue.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XArtPartCtrl.obj"
	-@erase "$(INTDIR)\XAtmosCtrl.obj"
	-@erase "$(INTDIR)\XCelestialCtrl.obj"
	-@erase "$(INTDIR)\XCollDetSegDef.obj"
	-@erase "$(INTDIR)\XCollDetVolDef.obj"
	-@erase "$(INTDIR)\XCompCtrl.obj"
	-@erase "$(INTDIR)\XConfClampEntityCtrl.obj"
	-@erase "$(INTDIR)\XEarthModelDef.obj"
	-@erase "$(INTDIR)\XEntityCtrl.obj"
	-@erase "$(INTDIR)\XEnvCondReq.obj"
	-@erase "$(INTDIR)\XEnvRgnCtrl.obj"
	-@erase "$(INTDIR)\XEventNotification.obj"
	-@erase "$(INTDIR)\XHatHotReq.obj"
	-@erase "$(INTDIR)\XIGCtrl.obj"
	-@erase "$(INTDIR)\XLosSegReq.obj"
	-@erase "$(INTDIR)\XLosVectReq.obj"
	-@erase "$(INTDIR)\XMaritimeSurfaceCtrl.obj"
	-@erase "$(INTDIR)\XMotionTrackCtrl.obj"
	-@erase "$(INTDIR)\XPostionReq.obj"
	-@erase "$(INTDIR)\XRateCtrl.obj"
	-@erase "$(INTDIR)\XSensorCtrl.obj"
	-@erase "$(INTDIR)\XShortArtPartCtrl.obj"
	-@erase "$(INTDIR)\XShortCompCtrl.obj"
	-@erase "$(INTDIR)\XTerrestrialSurfaceCtrl.obj"
	-@erase "$(INTDIR)\XTrajectory.obj"
	-@erase "$(INTDIR)\XViewCtrl.obj"
	-@erase "$(INTDIR)\XViewDef.obj"
	-@erase "$(INTDIR)\XWaveCtrl.obj"
	-@erase "$(INTDIR)\XWeatherCtrl.obj"
	-@erase "$(OUTDIR)\ccl_xig.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /I ".\\" /I "..\..\src" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CigiExample.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WSock32.lib Cigi.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\ccl_xig.pdb" /machine:I386 /nodefaultlib:"LIBCMT.lib" /out:"$(OUTDIR)\ccl_xig.exe" /libpath:"..\..\lib\Win32\Release\SingleThreaded" 
LINK32_OBJS= \
	"$(INTDIR)\Callbacks.obj" \
	"$(INTDIR)\CigiExample.obj" \
	"$(INTDIR)\ExampleIO.obj" \
	"$(INTDIR)\GenProc.obj" \
	"$(INTDIR)\IGMan.obj" \
	"$(INTDIR)\Network.obj" \
	"$(INTDIR)\ParseLine.obj" \
	"$(INTDIR)\ParseValue.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\XArtPartCtrl.obj" \
	"$(INTDIR)\XAtmosCtrl.obj" \
	"$(INTDIR)\XCelestialCtrl.obj" \
	"$(INTDIR)\XCollDetSegDef.obj" \
	"$(INTDIR)\XCollDetVolDef.obj" \
	"$(INTDIR)\XCompCtrl.obj" \
	"$(INTDIR)\XConfClampEntityCtrl.obj" \
	"$(INTDIR)\XEarthModelDef.obj" \
	"$(INTDIR)\XEntityCtrl.obj" \
	"$(INTDIR)\XEnvCondReq.obj" \
	"$(INTDIR)\XEnvRgnCtrl.obj" \
	"$(INTDIR)\XEventNotification.obj" \
	"$(INTDIR)\XHatHotReq.obj" \
	"$(INTDIR)\XIGCtrl.obj" \
	"$(INTDIR)\XLosSegReq.obj" \
	"$(INTDIR)\XLosVectReq.obj" \
	"$(INTDIR)\XMaritimeSurfaceCtrl.obj" \
	"$(INTDIR)\XMotionTrackCtrl.obj" \
	"$(INTDIR)\XPostionReq.obj" \
	"$(INTDIR)\XRateCtrl.obj" \
	"$(INTDIR)\XSensorCtrl.obj" \
	"$(INTDIR)\XShortArtPartCtrl.obj" \
	"$(INTDIR)\XShortCompCtrl.obj" \
	"$(INTDIR)\XTerrestrialSurfaceCtrl.obj" \
	"$(INTDIR)\XTrajectory.obj" \
	"$(INTDIR)\XViewCtrl.obj" \
	"$(INTDIR)\XViewDef.obj" \
	"$(INTDIR)\XWaveCtrl.obj" \
	"$(INTDIR)\XWeatherCtrl.obj"

"$(OUTDIR)\ccl_xig.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CigiExample - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ccl_xig.exe" "$(OUTDIR)\CigiExample.pch"


CLEAN :
	-@erase "$(INTDIR)\Callbacks.obj"
	-@erase "$(INTDIR)\CigiExample.obj"
	-@erase "$(INTDIR)\CigiExample.pch"
	-@erase "$(INTDIR)\ExampleIO.obj"
	-@erase "$(INTDIR)\GenProc.obj"
	-@erase "$(INTDIR)\IGMan.obj"
	-@erase "$(INTDIR)\Network.obj"
	-@erase "$(INTDIR)\ParseLine.obj"
	-@erase "$(INTDIR)\ParseValue.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XArtPartCtrl.obj"
	-@erase "$(INTDIR)\XAtmosCtrl.obj"
	-@erase "$(INTDIR)\XCelestialCtrl.obj"
	-@erase "$(INTDIR)\XCollDetSegDef.obj"
	-@erase "$(INTDIR)\XCollDetVolDef.obj"
	-@erase "$(INTDIR)\XCompCtrl.obj"
	-@erase "$(INTDIR)\XConfClampEntityCtrl.obj"
	-@erase "$(INTDIR)\XEarthModelDef.obj"
	-@erase "$(INTDIR)\XEntityCtrl.obj"
	-@erase "$(INTDIR)\XEnvCondReq.obj"
	-@erase "$(INTDIR)\XEnvRgnCtrl.obj"
	-@erase "$(INTDIR)\XEventNotification.obj"
	-@erase "$(INTDIR)\XHatHotReq.obj"
	-@erase "$(INTDIR)\XIGCtrl.obj"
	-@erase "$(INTDIR)\XLosSegReq.obj"
	-@erase "$(INTDIR)\XLosVectReq.obj"
	-@erase "$(INTDIR)\XMaritimeSurfaceCtrl.obj"
	-@erase "$(INTDIR)\XMotionTrackCtrl.obj"
	-@erase "$(INTDIR)\XPostionReq.obj"
	-@erase "$(INTDIR)\XRateCtrl.obj"
	-@erase "$(INTDIR)\XSensorCtrl.obj"
	-@erase "$(INTDIR)\XShortArtPartCtrl.obj"
	-@erase "$(INTDIR)\XShortCompCtrl.obj"
	-@erase "$(INTDIR)\XTerrestrialSurfaceCtrl.obj"
	-@erase "$(INTDIR)\XTrajectory.obj"
	-@erase "$(INTDIR)\XViewCtrl.obj"
	-@erase "$(INTDIR)\XViewDef.obj"
	-@erase "$(INTDIR)\XWaveCtrl.obj"
	-@erase "$(INTDIR)\XWeatherCtrl.obj"
	-@erase "$(OUTDIR)\ccl_xig.exe"
	-@erase "$(OUTDIR)\ccl_xig.ilk"
	-@erase "$(OUTDIR)\ccl_xig.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\src" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CigiExample.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WSock32.lib Cigi.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\ccl_xig.pdb" /debug /machine:I386 /nodefaultlib:"LIBCMT.lib" /out:"$(OUTDIR)\ccl_xig.exe" /pdbtype:sept /libpath:"..\..\lib\Win32\Debug\SingleThreaded" 
LINK32_OBJS= \
	"$(INTDIR)\Callbacks.obj" \
	"$(INTDIR)\CigiExample.obj" \
	"$(INTDIR)\ExampleIO.obj" \
	"$(INTDIR)\GenProc.obj" \
	"$(INTDIR)\IGMan.obj" \
	"$(INTDIR)\Network.obj" \
	"$(INTDIR)\ParseLine.obj" \
	"$(INTDIR)\ParseValue.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\XArtPartCtrl.obj" \
	"$(INTDIR)\XAtmosCtrl.obj" \
	"$(INTDIR)\XCelestialCtrl.obj" \
	"$(INTDIR)\XCollDetSegDef.obj" \
	"$(INTDIR)\XCollDetVolDef.obj" \
	"$(INTDIR)\XCompCtrl.obj" \
	"$(INTDIR)\XConfClampEntityCtrl.obj" \
	"$(INTDIR)\XEarthModelDef.obj" \
	"$(INTDIR)\XEntityCtrl.obj" \
	"$(INTDIR)\XEnvCondReq.obj" \
	"$(INTDIR)\XEnvRgnCtrl.obj" \
	"$(INTDIR)\XEventNotification.obj" \
	"$(INTDIR)\XHatHotReq.obj" \
	"$(INTDIR)\XIGCtrl.obj" \
	"$(INTDIR)\XLosSegReq.obj" \
	"$(INTDIR)\XLosVectReq.obj" \
	"$(INTDIR)\XMaritimeSurfaceCtrl.obj" \
	"$(INTDIR)\XMotionTrackCtrl.obj" \
	"$(INTDIR)\XPostionReq.obj" \
	"$(INTDIR)\XRateCtrl.obj" \
	"$(INTDIR)\XSensorCtrl.obj" \
	"$(INTDIR)\XShortArtPartCtrl.obj" \
	"$(INTDIR)\XShortCompCtrl.obj" \
	"$(INTDIR)\XTerrestrialSurfaceCtrl.obj" \
	"$(INTDIR)\XTrajectory.obj" \
	"$(INTDIR)\XViewCtrl.obj" \
	"$(INTDIR)\XViewDef.obj" \
	"$(INTDIR)\XWaveCtrl.obj" \
	"$(INTDIR)\XWeatherCtrl.obj"

"$(OUTDIR)\ccl_xig.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "CigiExample - Win32 Release" || "$(CFG)" == "CigiExample - Win32 Debug"
SOURCE=.\Callbacks.cpp

"$(INTDIR)\Callbacks.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\CigiExample.cpp

"$(INTDIR)\CigiExample.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ExampleIO.cpp

"$(INTDIR)\ExampleIO.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\GenProc.cpp

"$(INTDIR)\GenProc.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\IGMan.cpp

"$(INTDIR)\IGMan.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Network.cpp

"$(INTDIR)\Network.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ParseLine.cpp

"$(INTDIR)\ParseLine.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ParseValue.cpp

"$(INTDIR)\ParseValue.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "CigiExample - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GX /O2 /I ".\\" /I "..\..\src" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\CigiExample.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CigiExample.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CigiExample - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\src" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /Fp"$(INTDIR)\CigiExample.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CigiExample.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\XArtPartCtrl.cpp

"$(INTDIR)\XArtPartCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XAtmosCtrl.cpp

"$(INTDIR)\XAtmosCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XCelestialCtrl.cpp

"$(INTDIR)\XCelestialCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XCollDetSegDef.cpp

"$(INTDIR)\XCollDetSegDef.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XCollDetVolDef.cpp

"$(INTDIR)\XCollDetVolDef.obj" : $(SOURCE) "$(INTDIR)"


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


SOURCE=.\XIGCtrl.cpp

"$(INTDIR)\XIGCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XLosSegReq.cpp

"$(INTDIR)\XLosSegReq.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XLosVectReq.cpp

"$(INTDIR)\XLosVectReq.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XMaritimeSurfaceCtrl.cpp

"$(INTDIR)\XMaritimeSurfaceCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XMotionTrackCtrl.cpp

"$(INTDIR)\XMotionTrackCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XPostionReq.cpp

"$(INTDIR)\XPostionReq.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XRateCtrl.cpp

"$(INTDIR)\XRateCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XSensorCtrl.cpp

"$(INTDIR)\XSensorCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XShortArtPartCtrl.cpp

"$(INTDIR)\XShortArtPartCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XShortCompCtrl.cpp

"$(INTDIR)\XShortCompCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XTerrestrialSurfaceCtrl.cpp

"$(INTDIR)\XTerrestrialSurfaceCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XTrajectory.cpp

"$(INTDIR)\XTrajectory.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XViewCtrl.cpp

"$(INTDIR)\XViewCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XViewDef.cpp

"$(INTDIR)\XViewDef.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XWaveCtrl.cpp

"$(INTDIR)\XWaveCtrl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XWeatherCtrl.cpp

"$(INTDIR)\XWeatherCtrl.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

