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

int isDirectory(char* path) {
    struct stat statbuf;

    if(stat(path, &statbuf) == -1)
        return 0;
    else
        return S_ISDIR(statbuf.st_mode);
}

void listdir(const char *name, int indent) {
    DIR* dir;
    struct dirent* entry;

    if(!(dir = opendir(name)))
        return;

    while((entry = readdir(dir)) != NULL) {
        if(isDirectory(name)) {
            char path[1024];
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            printf("%*s-%s\n", indent, "", entry->d_name);
            listdir(path, indent + convertedIndentVal);
        }
        else {
            printf("%*s- %s\n", indent, "", entry->d_name);
        }
    }
    closedir(dir);
}
