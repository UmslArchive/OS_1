//=============================================================================
//Date:     August 29, 2019
//Author:   Colby Ackerman
//Class:    Operating Systems (CS4760)
//Project:  Assignment 1
//File:     "Options.h"
//=============================================================================

#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

                    /* OPTION FLAG DECLARATIONS */

extern int helpFlag;
extern int setIndentFlag;
extern int symLinkFlag;
extern int printInfoFlag;
extern int permissionsFlag;
extern int numLinksFlag;
extern int uidFlag;
extern int gidFlag;
extern int fileSizeFlag;
extern int lastModTimeFlag;
extern int tpiugsFlag;

extern char* indentValString;
extern char* dirName;

                    /* FUNCTION DECLARATIONS */

//Function initalizes all variables that store user set and parameters that
//pertain to those options to 0 or NULL.
void initializeFlags();

//Function reads user set options from the command line and sets flags and
//flag parameters accordingly.
void setFlags(int argc, char** argv);

//Function prints status of all flags. (Used for debugging)
void printFlags();

#endif
