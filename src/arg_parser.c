#include <arg_parser.h>
#include <stdio.h>

arg_t parse_arguments(int argc, char** argv) {
    int i;
    arg_t args;
    if(argc == 2) {
        printf("using file: %s\n", argv[1]);
        args.filename = argv[1];
        args.error = NO_ERROR;
        return args;
    }
    char opt = '0';
    for(i = 1; i < argc; i++) {
        opt = argv[i][1];
        switch(opt) {
            case 'f':
                args.filename = argv[i+1];
                i++;
                break;
            
            default:
                printf("ERROR: Could not read option: %s\n", argv[i]);
                args.error = ARG_PARSE_ERROR;
                return args;
        }   
    }
    args.error = ARG_PARSE_ERROR;
    return args;
}


