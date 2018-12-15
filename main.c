#include <stdio.h>
#include <stdlib.h>

#include <arg_parser.h>
#include <hardware.h>


int main(int argc, char** argv) {
    if(argc < 2) {
        fprintf("Too few arguments!\n");
        return ARG_ERROR;
    }

    arg_t args = parse_arguments(argc, argv);
    if(arg_t.error != NO_ERROR) {
        printf("ERROR! Could not parse arguments!");
        return arg_t.error;
    }

    FILE* fp_prog = fopen(args.filename, "r");
    if(!fp_prog) {
        fprintf("Could not open file: %s", args.filename);
    }
    parse_program(fp_prog, memory);
    fclose(fp_prog);




    return 0;
}