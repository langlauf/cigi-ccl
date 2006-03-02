// CigiExample.cpp : Defines the entry point for the console application.
//

#include "StdAfx.h"
#include "AllCigi.h"
#include "ParseLine.h"
#include "HostMan.h"


#ifndef _WIN32
    #include <fstream>
#elif _MSC_VER > 13000
    #include <fstream>
#else
    #include <fstream.h>
#endif


int main(int argc, char* argv[])
{

   printf("\nBegin Cigi Example\n\n");

   unsigned char MsgBuffer[32768];
   int MsgSz;

   HostMan HMan(MsgBuffer,&MsgSz);

   char line[512];



      ifstream Hinfl("HostData.csv",ios::in);

      if(Hinfl.is_open() != 0)
      {

         ParseLine HPrsLn;


         bool IGProcess = true;
         bool HProcess = true;

         while(HProcess)
         {


            HMan.In();


            if(!Hinfl.eof())
            {
               Hinfl.getline(line,511);

               if(line[0] != 0)
               {

                  HPrsLn.ParseBuf(line);

                  HMan.Out(HPrsLn);

               }
               else
               {
                  HMan.Out(HPrsLn);

               }

            }
            else
            {
               HProcess = false;

               HMan.Out(HPrsLn);

            }

         }

         Hinfl.close();


   }

	return 0;

}

