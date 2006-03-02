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

ALL : "$(OUTDIR)\ccl_xhost.exe" "$(OUTDIR)\CigiExample.pch"


CLEAN :
	-@erase "$(INTDIR)\Callbacks.obj"
	-@erase "$(INTDIR)\CigiExample.obj"
	-@erase "$(INTDIR)\CigiExample.pch"
	-@erase "$(INTDIR)\ExampleIO.obj"
	-@erase "$(INTDIR)\GenProc.obj"
	-@erase "$(INTDIR)\HostMan.obj"
	-@erase "$(INTDIR)\Network.obj"
	-@erase "$(INTDIR)\ParseLine.obj"
	-@erase "$(INTDIR)\ParseValue.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XAerosolResp.obj"
	-@erase "$(INTDIR)\XAnimationStop.obj"
	-@erase "$(INTDIR)\XCollDetSegResp.obj"
	-@erase "$(INTDIR)\XCollDetVolResp.obj"
	-@erase "$(INTDIR)\XEventNotification.obj"
	-@erase "$(INTDIR)\XHatHotResp.obj"
	-@erase "$(INTDIR)\XHatHotXResp.obj"
	-@erase "$(INTDIR)\XIGMsg.obj"
	-@erase "$(INTDIR)\XLosResp.obj"
	-@erase "$(INTDIR)\XLosXResp.obj"
	-@erase "$(INTDIR)\XMaritimeSurfaceResp.obj"
	-@erase "$(INTDIR)\XPositionResp.obj"
	-@erase "$(INTDIR)\XSensorResp.obj"
	-@erase "$(INTDIR)\XSensorXResp.obj"
	-@erase "$(INTDIR)\XSOF.obj"
	-@erase "$(INTDIR)\XTerrestrialSurfaceResp.obj"
	-@erase "$(INTDIR)\XWeatherCondResp.obj"
	-@erase "$(OUTDIR)\ccl_xhost.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "..\..\src" /I ".\\" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CigiExample.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WSock32.lib Cigi.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\ccl_xhost.pdb" /machine:I386 /nodefaultlib:"LIBCMT.lib" /out:"$(OUTDIR)\ccl_xhost.exe" /libpath:"..\..\lib\Win32\Release\SingleThreaded" 
LINK32_OBJS= \
	"$(INTDIR)\Callbacks.obj" \
	"$(INTDIR)\CigiExample.obj" \
	"$(INTDIR)\ExampleIO.obj" \
	"$(INTDIR)\GenProc.obj" \
	"$(INTDIR)\HostMan.obj" \
	"$(INTDIR)\Network.obj" \
	"$(INTDIR)\ParseLine.obj" \
	"$(INTDIR)\ParseValue.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\XAerosolResp.obj" \
	"$(INTDIR)\XAnimationStop.obj" \
	"$(INTDIR)\XCollDetSegResp.obj" \
	"$(INTDIR)\XCollDetVolResp.obj" \
	"$(INTDIR)\XEventNotification.obj" \
	"$(INTDIR)\XHatHotResp.obj" \
	"$(INTDIR)\XHatHotXResp.obj" \
	"$(INTDIR)\XIGMsg.obj" \
	"$(INTDIR)\XLosResp.obj" \
	"$(INTDIR)\XLosXResp.obj" \
	"$(INTDIR)\XMaritimeSurfaceResp.obj" \
	"$(INTDIR)\XPositionResp.obj" \
	"$(INTDIR)\XSensorResp.obj" \
	"$(INTDIR)\XSensorXResp.obj" \
	"$(INTDIR)\XSOF.obj" \
	"$(INTDIR)\XTerrestrialSurfaceResp.obj" \
	"$(INTDIR)\XWeatherCondResp.obj"

"$(OUTDIR)\ccl_xhost.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CigiExample - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ccl_xhost.exe" "$(OUTDIR)\CigiExample.pch"


CLEAN :
	-@erase "$(INTDIR)\Callbacks.obj"
	-@erase "$(INTDIR)\CigiExample.obj"
	-@erase "$(INTDIR)\CigiExample.pch"
	-@erase "$(INTDIR)\ExampleIO.obj"
	-@erase "$(INTDIR)\GenProc.obj"
	-@erase "$(INTDIR)\HostMan.obj"
	-@erase "$(INTDIR)\Network.obj"
	-@erase "$(INTDIR)\ParseLine.obj"
	-@erase "$(INTDIR)\ParseValue.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XAerosolResp.obj"
	-@erase "$(INTDIR)\XAnimationStop.obj"
	-@erase "$(INTDIR)\XCollDetSegResp.obj"
	-@erase "$(INTDIR)\XCollDetVolResp.obj"
	-@erase "$(INTDIR)\XEventNotification.obj"
	-@erase "$(INTDIR)\XHatHotResp.obj"
	-@erase "$(INTDIR)\XHatHotXResp.obj"
	-@erase "$(INTDIR)\XIGMsg.obj"
	-@erase "$(INTDIR)\XLosResp.obj"
	-@erase "$(INTDIR)\XLosXResp.obj"
	-@erase "$(INTDIR)\XMaritimeSurfaceResp.obj"
	-@erase "$(INTDIR)\XPositionResp.obj"
	-@erase "$(INTDIR)\XSensorResp.obj"
	-@erase "$(INTDIR)\XSensorXResp.obj"
	-@erase "$(INTDIR)\XSOF.obj"
	-@erase "$(INTDIR)\XTerrestrialSurfaceResp.obj"
	-@erase "$(INTDIR)\XWeatherCondResp.obj"
	-@erase "$(OUTDIR)\ccl_xhost.exe"
	-@erase "$(OUTDIR)\ccl_xhost.ilk"
	-@erase "$(OUTDIR)\ccl_xhost.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "..\..\src" /I ".\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CigiExample.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WSock32.lib Cigi.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\ccl_xhost.pdb" /debug /machine:I386 /nodefaultlib:"LIBCMT.lib" /out:"$(OUTDIR)\ccl_xhost.exe" /pdbtype:sept /libpath:"..\..\lib\Win32\Debug\SingleThreaded" 
LINK32_OBJS= \
	"$(INTDIR)\Callbacks.obj" \
	"$(INTDIR)\CigiExample.obj" \
	"$(INTDIR)\ExampleIO.obj" \
	"$(INTDIR)\GenProc.obj" \
	"$(INTDIR)\HostMan.obj" \
	"$(INTDIR)\Network.obj" \
	"$(INTDIR)\ParseLine.obj" \
	"$(INTDIR)\ParseValue.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\XAerosolResp.obj" \
	"$(INTDIR)\XAnimationStop.obj" \
	"$(INTDIR)\XCollDetSegResp.obj" \
	"$(INTDIR)\XCollDetVolResp.obj" \
	"$(INTDIR)\XEventNotification.obj" \
	"$(INTDIR)\XHatHotResp.obj" \
	"$(INTDIR)\XHatHotXResp.obj" \
	"$(INTDIR)\XIGMsg.obj" \
	"$(INTDIR)\XLosResp.obj" \
	"$(INTDIR)\XLosXResp.obj" \
	"$(INTDIR)\XMaritimeSurfaceResp.obj" \
	"$(INTDIR)\XPositionResp.obj" \
	"$(INTDIR)\XSensorResp.obj" \
	"$(INTDIR)\XSensorXResp.obj" \
	"$(INTDIR)\XSOF.obj" \
	"$(INTDIR)\XTerrestrialSurfaceResp.obj" \
	"$(INTDIR)\XWeatherCondResp.obj"

"$(OUTDIR)\ccl_xhost.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


SOURCE=.\HostMan.cpp

"$(INTDIR)\HostMan.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Network.cpp

"$(INTDIR)\Network.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ParseLine.cpp

"$(INTDIR)\ParseLine.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ParseValue.cpp

"$(INTDIR)\ParseValue.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "CigiExample - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GX /O2 /I "..\..\src" /I ".\\" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\CigiExample.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CigiExample.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CigiExample - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "..\..\src" /I ".\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /Fp"$(INTDIR)\CigiExample.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CigiExample.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\XAerosolResp.cpp

"$(INTDIR)\XAerosolResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XAnimationStop.cpp

"$(INTDIR)\XAnimationStop.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XCollDetSegResp.cpp

"$(INTDIR)\XCollDetSegResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XCollDetVolResp.cpp

"$(INTDIR)\XCollDetVolResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XEventNotification.cpp

"$(INTDIR)\XEventNotification.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XHatHotResp.cpp

"$(INTDIR)\XHatHotResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XHatHotXResp.cpp

"$(INTDIR)\XHatHotXResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XIGMsg.cpp

"$(INTDIR)\XIGMsg.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XLosResp.cpp

"$(INTDIR)\XLosResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XLosXResp.cpp

"$(INTDIR)\XLosXResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XMaritimeSurfaceResp.cpp

"$(INTDIR)\XMaritimeSurfaceResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XPositionResp.cpp

"$(INTDIR)\XPositionResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XSensorResp.cpp

"$(INTDIR)\XSensorResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XSensorXResp.cpp

"$(INTDIR)\XSensorXResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XSOF.cpp

"$(INTDIR)\XSOF.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XTerrestrialSurfaceResp.cpp

"$(INTDIR)\XTerrestrialSurfaceResp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\XWeatherCondResp.cpp

"$(INTDIR)\XWeatherCondResp.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

