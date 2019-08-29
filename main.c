//=============================================================================
//Date:     August 29, 2019
//Author:   Colby Ackerman
//Class:    Operating Systems (CS4760)
//Project:  Assignment 1
//File:     "main.c"
//=============================================================================

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {

    //FLAGS
    int     hFlag = 0;
    int     IFlag = 0;
    char*   IFlagVal = NULL;
    int     LFlag = 0;
    int     dFlag = 0;
    int     gFlag = 0;
    int     iFlag = 0;
    int     pFlag = 0;
    int     sFlag = 0;
    int     tFlag = 0;
    int     uFlag = 0;
    int     lFlag = 0;
    char*   dirname = NULL;

    //Stuff for getopts
    int index;
    int c;
    opterr = 0;

    //Set flags.
    while((c = getopt(argc, argv, "hI:Ldgipstul")) != -1) {
        switch(c) {
            case 'h':
                hFlag = 1;
                printf("h ");
                break;
            
            case 'I':
                IFlag = 1;
                IFlagVal = optarg;
                printf("I-Flag: %d, %s\n", IFlag, IFlagVal);
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
    }

    //Set dirname to directory argument.
    for(index = optind; index < argc; index++) {
        dirname = argv[index];
    }

    printf("DIRNAME: %s\n", dirname);

    return 0;
} 
