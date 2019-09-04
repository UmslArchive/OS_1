//=============================================================================
//Date:     August 29, 2019
//Author:   Colby Ackerman
//Class:    Operating Systems (CS4760)
//Project:  Assignment 1
//File:     "main.c"
//=============================================================================

#include "Options.h"
#include "Print.h"

int main(int argc, char** argv) {
   initializeFlags(); 
   
   setFlags(argc, argv);

   //DEBUGprintFlags();

   printHelp();

   return 0;
}
