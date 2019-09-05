//=============================================================================
//Date:     August 29, 2019
//Author:   Colby Ackerman
//Class:    Operating Systems (CS4760)
//Project:  Assignment 1
//File:     "main.c"
//=============================================================================

#include "DirectoryParser.h"

int main(int argc, char** argv) {
   initializeFlags(); 
   
   setFlags(argc, argv);

   listDirectories(dirName, 0);

   return 0;
}
