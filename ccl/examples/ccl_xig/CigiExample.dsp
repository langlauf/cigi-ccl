# Microsoft Developer Studio Project File - Name="CigiExample" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=CigiExample - Win32 dllDebug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CigiExample.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CigiExample - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I ".\\" /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WSock32.lib ccl_lib.lib /nologo /subsystem:console /machine:I386 /nodefaultlib:"LIBCMT.lib" /out:"Release/ccl_xig.exe" /libpath:"..\..\bin\libReleaseST"

!ELSEIF  "$(CFG)" == "CigiExample - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WSock32.lib ccl_lib.lib /nologo /subsystem:console /debug /machine:I386 /nodefaultlib:"LIBCMT.lib" /out:"Debug/ccl_xig.exe" /pdbtype:sept /libpath:"..\..\bin\libDebugST"

!ELSEIF  "$(CFG)" == "CigiExample - Win32 dllDebug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "CigiExample___Win32_dllDebug"
# PROP BASE Intermediate_Dir "CigiExample___Win32_dllDebug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "dllDebug"
# PROP Intermediate_Dir "dllDebug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /FD /GZ /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WSock32.lib ccl_lib.lib /nologo /subsystem:console /debug /machine:I386 /nodefaultlib:"LIBCMT.lib" /out:"Debug/ccl_xig.exe" /pdbtype:sept /libpath:"..\..\bin\libDebugST"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WSock32.lib ccl_dll.lib /nologo /subsystem:console /debug /machine:I386 /nodefaultlib:"LIBCMT.lib" /out:"dllDebug/ccl_xig.exe" /pdbtype:sept /libpath:"..\..\bin\dllReleaseMT_DLL"

!ENDIF 

# Begin Target

# Name "CigiExample - Win32 Release"
# Name "CigiExample - Win32 Debug"
# Name "CigiExample - Win32 dllDebug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Callbacks.cpp
# End Source File
# Begin Source File

SOURCE=.\CigiExample.cpp
# End Source File
# Begin Source File

SOURCE=.\ExampleIO.cpp
# End Source File
# Begin Source File

SOURCE=.\GenProc.cpp
# End Source File
# Begin Source File

SOURCE=.\IGMan.cpp
# End Source File
# Begin Source File

SOURCE=.\Network.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseLine.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseValue.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\XArtPartCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XAtmosCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XCelestialCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XCollDetSegDef.cpp
# End Source File
# Begin Source File

SOURCE=.\XCollDetVolDef.cpp
# End Source File
# Begin Source File

SOURCE=.\XCompCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XConfClampEntityCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XEarthModelDef.cpp
# End Source File
# Begin Source File

SOURCE=.\XEntityCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XEnvCondReq.cpp
# End Source File
# Begin Source File

SOURCE=.\XEnvRgnCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XEventNotification.cpp
# End Source File
# Begin Source File

SOURCE=.\XHatHotReq.cpp
# End Source File
# Begin Source File

SOURCE=.\XIGCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XLosSegReq.cpp
# End Source File
# Begin Source File

SOURCE=.\XLosVectReq.cpp
# End Source File
# Begin Source File

SOURCE=.\XMaritimeSurfaceCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XMotionTrackCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XPostionReq.cpp
# End Source File
# Begin Source File

SOURCE=.\XRateCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XSensorCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XShortArtPartCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XShortCompCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XTerrestrialSurfaceCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XTrajectory.cpp
# End Source File
# Begin Source File

SOURCE=.\XViewCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XViewDef.cpp
# End Source File
# Begin Source File

SOURCE=.\XWaveCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XWeatherCtrl.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AllCigi.h
# End Source File
# Begin Source File

SOURCE=.\Callbacks.h
# End Source File
# Begin Source File

SOURCE=.\ExampleIO.h
# End Source File
# Begin Source File

SOURCE=.\GenProc.h
# End Source File
# Begin Source File

SOURCE=.\IGMan.h
# End Source File
# Begin Source File

SOURCE=.\Network.h
# End Source File
# Begin Source File

SOURCE=.\ParseLine.h
# End Source File
# Begin Source File

SOURCE=.\ParseValue.h
# End Source File
# Begin Source File

SOURCE=.\SignalProcessing.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\XArtPartCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XAtmosCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XCelestialCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XCollDetSegDef.h
# End Source File
# Begin Source File

SOURCE=.\XCollDetVolDef.h
# End Source File
# Begin Source File

SOURCE=.\XCompCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XConfClampEntityCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XEarthModelDef.h
# End Source File
# Begin Source File

SOURCE=.\XEntityCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XEnvCondReq.h
# End Source File
# Begin Source File

SOURCE=.\XEnvRgnCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XEventNotification.h
# End Source File
# Begin Source File

SOURCE=.\XHatHotReq.h
# End Source File
# Begin Source File

SOURCE=.\XIGCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XLosSegReq.h
# End Source File
# Begin Source File

SOURCE=.\XLosVectReq.h
# End Source File
# Begin Source File

SOURCE=.\XMaritimeSurfaceCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XMotionTrackCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XPostionReq.h
# End Source File
# Begin Source File

SOURCE=.\XRateCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XSensorCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XShortArtPartCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XShortCompCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XTerrestrialSurfaceCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XTrajectory.h
# End Source File
# Begin Source File

SOURCE=.\XViewCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XViewDef.h
# End Source File
# Begin Source File

SOURCE=.\XWaveCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XWeatherCtrl.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
