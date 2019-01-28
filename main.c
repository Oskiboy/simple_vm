#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <parser.h>
#include <arg_parser.h>
#include <hardware.h>

INIT_HARDWARE(hw)


int main(int argc, char** argv) {
    bool running = true;
    instruction_t instruction;


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
    parse_program(fp_prog, hw.memory);
    fclose(fp_prog);

    init_machine(hw); 

    while(running) {
        instruction = fetch_decode(hw);
        
    }
    


    return 0;
}
