//=============================================================================
//Date:     August 29, 2019
//Author:   Colby Ackerman
//Class:    Operating Systems (CS4760)
//Project:  Assignment 1
//File:     "DirectoryParser.h"
//=============================================================================

#ifndef DIRECTORYPARSER_H
#define DIRECTORYPARSER_H

#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include "Options.h"

char* getCWD();

int listFilesInDirectory(char* path);

int isDirectory(char* path);

void listdir(const char* name, int indent);

#endif
