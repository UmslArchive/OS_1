//=============================================================================
//Date:     August 29, 2019
//Author:   Colby Ackerman
//Class:    Operating Systems (CS4760)
//Project:  Assignment 1
//File:     "Options.c"
//=============================================================================

#include "Options.h"

void initializeFlags() {
    
    int helpFlag = 0;
    int setIndentFlag = 0;
    int symLinkFlag = 0;
    int printInfoFlag = 0;
    int permissionsFlag = 0;
    int numLinksFlag = 0;
    int uidFlag = 0;
    int gidFlag = 0;
    int fileSizeFlag = 0;
    int lastModTimeFlag = 0;
    int tpiugsFlag = 0;

    char* indentValString = NULL;
    char* dirName= NULL;
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
                hFlag = 1;
                break;
            
            case 'I':
                IFlag = 1;
                IFlagVal = optarg;
                break;
            
            case 'L':
                LFlag = 1;
                break;

            case 'd':
                dFlag = 1;
                break;
            
            case 'g':
                gFlag = 1;
                break;

            case 'i':
                iFlag = 1;
                break;

            case 'p':
                pFlag = 1;
                break;

            case 's':
                sFlag = 1;
                break;

            case 't':
                tFlag = 1;
                break;

            case 'u':
                uFlag = 1;
                break;
                lFlag = 1;
                break;
                
            case '?':
                if(optopt = 'I') {
                    printf("Option -%c requires an argument.\n", optopt);
                }
                break;
        }
        
        //Set dirname to directory argument.
        for(i = optind; i < argc; i++) {
            dirname = argv[i];
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
