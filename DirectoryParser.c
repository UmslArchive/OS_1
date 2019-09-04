//=============================================================================
//Date:     August 29, 2019
//Author:   Colby Ackerman
//Class:    Operating Systems (CS4760)
//Project:  Assignment 1
//File:     "DirectoryParser.c"
//=============================================================================

#include "DirectoryParser.h"

char* getCWD() {
    long maxpath;
    char* mycwdp;

    if((maxpath = pathconf(".", _PC_PATH_MAX)) == -1) {
        perror("Failed to determine the pathname length");
        return NULL;
    }

    if((mycwdp = (char*) malloc(maxpath)) == NULL) {
        perror("Failed to allocate space for pathname.");
        return NULL;
    }

    if(getcwd(mycwdp, maxpath) == NULL) {
        perror("Failed to get current working directory");
        return NULL;
    }

    return mycwdp;
}

int listFilesInDirectory(char* path){
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
