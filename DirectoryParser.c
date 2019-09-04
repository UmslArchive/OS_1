//=============================================================================
//Date:     August 29, 2019
//Author:   Colby Ackerman
//Class:    Operating Systems (CS4760)
//Project:  Assignment 1
//File:     "DirectoryParser.c"
//=============================================================================

#include "DirectoryParser.h"

int listFilesInDirectory(char* path) {
    struct dirent* direntp;
    DIR* dirp;

    if((dirp = opendir(path)) == NULL) {
        perror ("Failed to open directory");
        return 1;
    }

    while((direntp = readdir(dirp)) != NULL) {
        printf("%s\n", direntp->d_name);
    }

    while((closedir(dirp) == -1) && (errno == EINTR));
    
    return 0;
}
