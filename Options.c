//=============================================================================
//Date:     August 29, 2019
//Author:   Colby Ackerman
//Class:    Operating Systems (CS4760)
//Project:  Assignment 1
//File:     "Options.c"
//=============================================================================

#include "Options.h"

int helpFlag;
int setIndentFlag;
int symLinkFlag;
int printInfoFlag;
int permissionsFlag;
int numLinksFlag;
int uidFlag;
int gidFlag;
int fileSizeFlag;
int lastModTimeFlag;
int tpiugsFlag;

char* indentValString;
char* dirName;

void initializeFlags() {
    
    helpFlag = 0;       // -h
    setIndentFlag = 0;  // -I n
    symLinkFlag = 0;    // -L
    printInfoFlag = 0;  // -t
    permissionsFlag = 0;// -p
    numLinksFlag = 0;   // -i
    uidFlag = 0;        // -u
    gidFlag = 0;        // -g
    fileSizeFlag = 0;   // -s
    lastModTimeFlag = 0;// -d
    tpiugsFlag = 0;     // -l (lowercase L)

    indentValString = NULL;   // -I n
    dirName= NULL;            // [dirname]
}

static void tpiugsEnable() {
    printInfoFlag = 1;
    permissionsFlag = 1;
    numLinksFlag = 1;
    uidFlag = 1;
    gidFlag = 1;
    fileSizeFlag = 1;
}

void setFlags(int argc, char** argv) {

    //Stuff for getopts
    int i;
    int c;
    int opterr = 0;

    //Iterate through users passed parameters and set flags accordingly.
    while((c = getopt(argc, argv, "hI:Ltpiugsdl")) != -1) {
        switch(c) {
            case 'h':
                helpFlag = 1;
                break;
            
            case 'I':
                setIndentFlag = 1;
                indentValString = optarg;
                break;
            
            case 'L':
                symLinkFlag = 1;
                break;

            case 't':
                printInfoFlag = 1;
                break;
            
            case 'p':
                permissionsFlag = 1;
                break;

            case 'i':
                numLinksFlag = 1;
                break;

            case 'u':
                uidFlag = 1;
                break;

            case 'g':
                gidFlag = 1;
                break;

            case 's':
                fileSizeFlag = 1;
                break;

            case 'd':
                lastModTimeFlag = 1;
                break;

            case 'l':
                tpiugsFlag = 1;
                tpiugsEnable();
                break;
                
            case '?':
                if(optopt = 'I') {
                    printf("Option -%c requires an argument.\n", optopt);
                }
                break;
        }
        
        //Set dirname to directory argument.
        for(i = optind; i < argc; i++) {
            dirName = argv[i];
        }
    }
}

void printFlags() {
    
    //Print -h status.
    printf("-h = %d\n", helpFlag);
    
    //Print -I n status.
    printf("-I = %d\t%s\n", setIndentFlag, indentValString); 

    //Print -L status.
    printf("-L = %d\n", symLinkFlag); 
    
    //Print -t status.
    printf("-t = %d\n", printInfoFlag);

    //Print -p status.
    printf("-p = %d\n", permissionsFlag);

    //Print -i status.
    printf("-i = %d\n", numLinksFlag);

    //Print -u status.
    printf("-u = %d\n", uidFlag);

    //Print -g status.
    printf("-g = %d\n", gidFlag);
    
    //Print -s status.
    printf("-s = %d\n", fileSizeFlag);

    //Print -d status.
    printf("-d = %d\n", lastModTimeFlag);

    //Print -l status.
    printf("-l = %d\n", tpiugsFlag);

    //Print Directory Name.
    printf("dirname = %s\n", dirName);
}
