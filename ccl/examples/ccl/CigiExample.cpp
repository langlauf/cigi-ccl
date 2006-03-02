// CigiExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AllCigi.h"
#include "ParseLine.h"
#include <fstream.h>
#include "IGMan.h"
#include "HostMan.h"

int main(int argc, char* argv[])
{

   printf("\nBegin Cigi Example\n\n");

   unsigned char MsgBuffer[32768];
   int MsgSz;

   IGMan IGMan(MsgBuffer,&MsgSz);
   HostMan HMan(MsgBuffer,&MsgSz);

   char line[512];


   ifstream IGinfl("IGData.csv",ios::in);

   if(IGinfl.is_open() != 0)
   {

      ParseLine IGPrsLn;

      ifstream Hinfl("HostData.csv",ios::in);

      if(Hinfl.is_open() != 0)
      {

         ParseLine HPrsLn;


         bool IGProcess = true;
         bool HProcess = true;

         while(IGProcess || HProcess)
         {

            if(!IGinfl.eof())
            {
               IGinfl.getline(line,511);

               if(line[0] != 0)
               {

                  IGPrsLn.ParseBuf(line);

                  IGMan.Out(IGPrsLn);

                  HMan.In();
               }
               else
               {
                  IGMan.Out(IGPrsLn);

                  HMan.In();
               }

            }
            else
            {
               IGProcess = false;

               IGMan.Out(IGPrsLn);

               HMan.In();
            }


            if(!Hinfl.eof())
            {
               Hinfl.getline(line,511);

               if(line[0] != 0)
               {

                  HPrsLn.ParseBuf(line);

                  HMan.Out(HPrsLn);

                  IGMan.In();
               }
               else
               {
                  HMan.Out(HPrsLn);

                  IGMan.In();
               }

            }
            else
            {
               HProcess = false;

               HMan.Out(HPrsLn);

               IGMan.In();
            }

         }

         Hinfl.close();

      }

      IGinfl.close();

   }

	return 0;

}

