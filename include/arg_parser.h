#ifndef ARG_PARS_H
#define ARG_PARS_H

#define NO_ERROR        0
#define ARG_PARSE_ERROR 1
#define ARG_ERROR       2

struct {
    char* filename;
    int error;
} arg_t;

arg_t parse_arguments(int argc, char** argv);


#endif //ARG_PARSE_H