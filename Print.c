//=============================================================================
//Date:     August 29, 2019
//Author:   Colby Ackerman
//Class:    Operating Systems (CS4760)
//Project:  Assignment 1
//File:     "Print.c"
//=============================================================================

#include "Print.h"

void printHelp() {
    printf("Here's a list of options:\n");
    printf("----------\n");
    printf("\"-h\" Get Help.\n");
    printf("\"-I n\" Change indent level to n spaces.\n");
    printf("\"-L\" Follow symbolic links.\n");
    printf("\"-t\" Print file-type information.\n");
    printf("\"-p\" Print permission bits.\n");
    printf("\"-i\" Print number of links to file in inode table.\n");
    printf("\"-u\" Print UID associated with the file.\n");
    printf("\"-g\" Print GID associated with the file.\n");
    printf("\"-s\" Print size of file in bytes.\n");
    printf("\"-d\" Show time of last modification.\n");
    printf("\"-l\" Enable -t -p -i -u -g -s option flags.\n");
}

void printAll() {
    listFilesInDirectory(dirName);

    printf("%s\n", getCWD());
}
