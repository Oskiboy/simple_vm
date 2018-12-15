#include <parser.h>
#include <hardware.h>

void parse_program(FILE* program, uint16_t* memory) {
    char buffer[16], c_buff;
    uint16_t temp;
    int size = 0, i;
    while(program != EOF && size < PROG_MEM_END) {
        for(i = 0; ((c_buff = fgetc(program)) != '\n'), i++) {
            buffer[i] = c_buff;
        }
        printf("Buffer: %s", buffer);
        for(i = 0; i < 16; i++) {
            temp = buffer[i] << i;
        }
        memory[size] = temp;
        size++;      
    }
}