// CigiExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AllCigi.h"
#include "ParseLine.h"
#include <fstream.h>
#include "IGMan.h"

int main(int argc, char* argv[])
{

   printf("\nBegin Cigi Example\n\n");

   unsigned char MsgBuffer[32768];
   int MsgSz;

   IGMan IGMan(MsgBuffer,&MsgSz);

   char line[512];


   ifstream IGinfl("IGData.csv",ios::in);

   if(IGinfl.is_open() != 0)
   {

      ParseLine IGPrsLn;



         bool IGProcess = true;
         bool HProcess = true;

         while(IGProcess)
         {

            if(!IGinfl.eof())
            {
               IGinfl.getline(line,511);

               if(line[0] != 0)
               {

                  IGPrsLn.ParseBuf(line);

                  IGMan.Out(IGPrsLn);

               }
               else
               {
                  IGMan.Out(IGPrsLn);
               }

            }
            else
            {
               IGProcess = false;

               IGMan.Out(IGPrsLn);

            }




               IGMan.In();
         }



      IGinfl.close();

   }

	return 0;

}

