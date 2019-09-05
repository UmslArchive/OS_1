//=============================================================================
//Date:     August 29, 2019
//Author:   Colby Ackerman
//Class:    Operating Systems (CS4760)
//Project:  Assignment 1
//File:     "Print.h"
//=============================================================================

#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

#include "Options.h"

extern char currentEntry[1024];

void buildEntryString(const char* entry, const char* name, int indent);

void printHelp();

void printEntry();

#endif
