/** <pre>
 *  The SDK is used to create and format CIGI compliant messages.
 *  Copyright (c) 2001-2003 The Boeing Company
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
 *  FILENAME:   MiniHostIO.cpp
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
 *  10/27/2005 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 *  
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.5.4
 */



#include "MiniHostIO.h"
#include <time.h>


// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiIO
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
MiniHostIO::MiniHostIO(CigiIncomingMsg &InMsg, CigiOutgoingMsg &OutMsg)
       : CigiIO(InMsg, OutMsg)
{

}

// ================================================
// ~CigiIO
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
MiniHostIO::~MiniHostIO()
{

}

// ====================================================================
// Processing
// ====================================================================

// ================================================
// Write
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int MiniHostIO::Write(unsigned char * Buffer, int Length)
{

   int stat = CIGI_SUCCESS;

   // send CIGI message
   int sentBytes = network.send(Buffer,Length);

   if(sentBytes < Length)
      stat = CIGI_ERROR_MISCELLANEOUS;


   return(stat);

}

// ================================================
// Read
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int MiniHostIO::Read(unsigned char * Buffer, int MaxLength)
{

   // wait for Start Of Frame

   int MsgSz = 0;
   long HoldTime;
   bool RcvrProc = false;
   long CheckTime = time(&HoldTime);
   while(!RcvrProc)
   {
      if((MsgSz = network.recv( Buffer, MaxLength )) > 0)
         RcvrProc = true;
      else
      {
         long TstTime = time(&HoldTime);
         if((TstTime - CheckTime) > 1)
         {
            // No message
            RcvrProc = true;
            MsgSz = 0;
         }
      }
   }


   return(MsgSz);

}


