//=============================================================================
//Date:     August 29, 2019
//Author:   Colby Ackerman
//Class:    Operating Systems (CS4760)
//Project:  Assignment 1
//File:     "DirectoryParser.h"
//=============================================================================

#ifndef DIRECTORYPARSER_H
#define DIRECTORYPARSER_H

#include "Print.h"

char* getCWD();

int isDirectory(const char* path);

void listDirectories(const char* path, int indent);

#endif
