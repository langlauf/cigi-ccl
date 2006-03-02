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
# ADD CPP /nologo /W3 /GX /O2 /I "..\..\include" /I ".\\" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WSock32.lib ccl_lib.lib /nologo /subsystem:console /machine:I386 /nodefaultlib:"LIBCMT.lib" /out:"Release/ccl_xhost.exe" /libpath:"..\..\bin\libReleaseST"

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
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\..\include" /I ".\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WSock32.lib ccl_lib.lib /nologo /subsystem:console /debug /machine:I386 /nodefaultlib:"LIBCMT.lib" /out:"Debug/ccl_xhost.exe" /pdbtype:sept /libpath:"..\..\bin\libDebugST"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\..\include" /I ".\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /FD /GZ /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\include" /I ".\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "CIGI_LITTLE_ENDIAN" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WSock32.lib ccl_lib.lib /nologo /subsystem:console /debug /machine:I386 /nodefaultlib:"LIBCMT.lib" /out:"Debug/ccl_xhost.exe" /pdbtype:sept /libpath:"..\..\bin\libDebugST"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WSock32.lib ccl_dll.lib /nologo /subsystem:console /debug /machine:I386 /nodefaultlib:"LIBCMT.lib" /out:"dllDebug/ccl_xhost.exe" /pdbtype:sept /libpath:"..\..\bin\dllDebugMT_DLL"

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

SOURCE=.\HostMan.cpp
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

SOURCE=.\XAerosolResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XAnimationStop.cpp
# End Source File
# Begin Source File

SOURCE=.\XCollDetSegResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XCollDetVolResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XEventNotification.cpp
# End Source File
# Begin Source File

SOURCE=.\XHatHotResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XHatHotXResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XIGMsg.cpp
# End Source File
# Begin Source File

SOURCE=.\XLosResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XLosXResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XMaritimeSurfaceResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XPositionResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XSensorResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XSensorXResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XSOF.cpp
# End Source File
# Begin Source File

SOURCE=.\XTerrestrialSurfaceResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XWeatherCondResp.cpp
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

SOURCE=.\HostMan.h
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

SOURCE=.\XAerosolResp.h
# End Source File
# Begin Source File

SOURCE=.\XAnimationStop.h
# End Source File
# Begin Source File

SOURCE=.\XCollDetSegResp.h
# End Source File
# Begin Source File

SOURCE=.\XCollDetVolResp.h
# End Source File
# Begin Source File

SOURCE=.\XEventNotification.h
# End Source File
# Begin Source File

SOURCE=.\XHatHotResp.h
# End Source File
# Begin Source File

SOURCE=.\XHatHotXResp.h
# End Source File
# Begin Source File

SOURCE=.\XIGMsg.h
# End Source File
# Begin Source File

SOURCE=.\XLosResp.h
# End Source File
# Begin Source File

SOURCE=.\XLosXResp.h
# End Source File
# Begin Source File

SOURCE=.\XMaritimeSurfaceResp.h
# End Source File
# Begin Source File

SOURCE=.\XPositionResp.h
# End Source File
# Begin Source File

SOURCE=.\XSensorResp.h
# End Source File
# Begin Source File

SOURCE=.\XSensorXResp.h
# End Source File
# Begin Source File

SOURCE=.\XSOF.h
# End Source File
# Begin Source File

SOURCE=.\XTerrestrialSurfaceResp.h
# End Source File
# Begin Source File

SOURCE=.\XWeatherCondResp.h
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
