#include <parser.h>
#include <hardware.h>

void parse_program(FILE* program, uint16_t* memory) {
    char buffer[16];
    uint16_t temp = 0;
    int size = 0, i;
    while(!feof(program) && (size < PROG_MEM_END)) {
        fgets(buffer, 17, program);
        fgetc(program);
        printf("Buffer: %s\n", buffer);
        temp = 0;
        for(i = 0; i < 16; i++) {
            temp |= (buffer[i] - '0') << (15 - i);
        }

        memory[size] = temp;
        size++;      
    }
}
