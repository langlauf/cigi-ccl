/** <pre>
 *  The SDK is used to create and format CIGI compliant messages.
 *  Copyright (c) 2001-2005 The Boeing Company
 *  
 *  This library is free software; you can redistribute it and/or modify it 
 *  under the terms of the GNU Lesser General Public License as published by 
 *  the Free Software Foundation; either version 2.1 of the License, or (at 
 *  your option) any later version.
 *  
 *  This library is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more 
 *  details.
 *  
 *  You should have received a copy of the GNU Lesser General Public License 
 *  along with this library; if not, write to the Free Software Foundation, 
 *  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *  
 *  FILENAME:   CigiBaseEnvCtrl.h
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Common Image Generator Interface (CIGI) SDK
 *  
 *  PROGRAM DESCRIPTION: 
 *  ...
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  09/17/2003 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Added the CIGI_SPEC modifier to the class declaration for exporting the 
 *  class in a Windows DLL.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Changed native C++ types in function declarations to CCL-defined types.
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.6.0
 */


#if !defined(_CIGI_BASE_ENV_CTRL_INCLUDED_)
#define _CIGI_BASE_ENV_CTRL_INCLUDED_

#include "CigiBasePacket.h"

class CigiEnvCtrlV1;
class CigiEnvCtrlV2;
class CigiAtmosCtrlV3;
class CigiCelestialCtrlV3;
class CigiHoldEnvCtrl;


class CIGI_SPEC CigiBaseEnvCtrl : public CigiBasePacket
{

friend class CigiEnvCtrlV1;
friend class CigiEnvCtrlV2;
friend class CigiAtmosCtrlV3;
friend class CigiCelestialCtrlV3;
friend class CigiHoldEnvCtrl;

protected:

   // This class can only be instanciated by friend classes
   //   and should be only instanced by the session manager.

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiBaseEnvCtrl();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiBaseEnvCtrl();


public:

   //==> Buffer Packing/Unpacking

   //=========================================================
   //! A pure virtual Pack function.  
   //! This function is not implemented in this class.
   //! \param Base - A pointer to the instance of the packet 
   //!          to be packed. (Downcast to CigiBasePacket)
   //! \param Buff - A pointer to the current pack point.
   //! \param Spec - A pointer to special data.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Pack(CigiBasePacket * Base, unsigned char * Buff, void *Spec) const=0;

   //=========================================================
   //! A pure virtual Unpack function.
   //! This function is not implemented in this class.
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - N/A for V1 & V2
   //! \param Spec - A pointer to special data.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Unpack(unsigned char * Buff, bool Swap, void *Spec) =0;


   //==> Hold Object Manipulation

   //=========================================================
   //! A pure virtual FillHold function.  
   //! This function is not implemented in this class.
   //!
   virtual void FillHold(CigiBaseEnvCtrl * Hold) const=0;



   //==> Accessing Member Variable Values functions


protected:

   //==> Member variables

   //=========================================================
   //! Hour<br>
   //! The current hour.
   //!
   unsigned char Hour;

   //=========================================================
   //! Minute<br>
   //! The current minute.
   //!
   unsigned char Minute;

   //=========================================================
   //! Month<br>
   //! The current month.
   //!
   unsigned char Month;

   //=========================================================
   //! Day<br>
   //! The current day of the month.
   //!
   unsigned char Day;

   //=========================================================
   //! Year<br>
   //! The current year.
   //!
   Cigi_uint16 Year;

   //=========================================================
   //! StarInt<br>
   //! The Star field intensity.
   //!
   float StarInt;

   //=========================================================
   //! EphemerisEn<br>
   //! The ephemeris model enable
   //!
   bool EphemerisEn;

   //=========================================================
   //! SunEn<br>
   //! The Sun enable
   //!
   bool SunEn;

   //=========================================================
   //! MoonEn<br>
   //! The Moon enable
   //!
   bool MoonEn;

   //=========================================================
   //! StarEn<br>
   //! The star field enable.
   //!
   bool StarEn;

   //=========================================================
   //! DateVld<br>
   //! Date is valid flag.
   //!
   bool DateVld;

   //=========================================================
   //! AtmosEn<br>
   //! The atmospheric model enable.
   //!
   bool AtmosEn;

   //=========================================================
   //! Aerosol<br>
   //! The current aerosol density
   //!
   float Aerosol;

   //=========================================================
   //! Humidity<br>
   //! The current humidity.
   //!
   unsigned char Humidity;

   //=========================================================
   //! AirTemp<br>
   //! The current ambient air temperature
   //!
   float AirTemp;

   //=========================================================
   //! Visibility<br>
   //! Global visibility
   //!
   float Visibility;

   //=========================================================
   //! HorizWindSp<br>
   //! The horizontal wind speed or more commonly just wind speed.
   //!
   float HorizWindSp;

   //=========================================================
   //! VertWindSp<br>
   //! The vertical wind speed.
   //!
   float VertWindSp;

   //=========================================================
   //! WindDir<br>
   //! The wind direction.
   //!
   float WindDir;

   //=========================================================
   //! BaroPress<br>
   //! global barometric pressure
   //!
   float BaroPress;


};

#endif // #if !defined(_CIGI_BASE_ENV_CTRL_INCLUDED_)CL
