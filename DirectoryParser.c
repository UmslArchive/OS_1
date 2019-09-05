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

int isDirectory(const char* path) {
    struct stat statbuf;

    if(stat(path, &statbuf) == -1)
        return 0;
    else
        return S_ISDIR(statbuf.st_mode);
}

void listdir(const char *path, int indent) {
    DIR* dir;
    struct dirent* entry;

    if(!(dir = opendir(path)))
        return;

    while((entry = readdir(dir)) != NULL) {
        if(isDirectory(path)) {
            char newPath[1024];
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(newPath, sizeof(newPath), "%s/%s", path, entry->d_name);
            printf("%*s-%s\n", indent, "", entry->d_name);
            listdir(newPath, indent + convertedIndentVal);
        }
        else {
            printf("%*s- %s\n", indent, "", entry->d_name);
        }
    }
    closedir(dir);
}