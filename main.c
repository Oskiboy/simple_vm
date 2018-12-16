#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <parser.h>
#include <arg_parser.h>
#include <hardware.h>

INIT_MEMORY(memory)
INIT_REGISTERS(registers)


int main(int argc, char** argv) {
    registers[0] = 0;
    int i;
    if(argc < 2) {
        printf("Too few arguments!\n");
        return ARG_ERROR;
    }

    arg_t args = parse_arguments(argc, argv);
    if(args.error != NO_ERROR) {
        printf("ERROR! Could not parse arguments!\n");
        return args.error;
    }

    FILE* fp_prog = fopen(args.filename, "r");
    if(!fp_prog) {
        printf("Could not open file: %s\n", args.filename);
    }
    parse_program(fp_prog, memory);
    fclose(fp_prog);


    return 0;
}
