#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdint>
#include "comand_parser.h"

char EscapeChar(char* argv){
    char delimiter;
    if (*argv == 'a') {
        delimiter = '\a';
    }
    if (*argv == 'b') {
        delimiter = '\b';
    }
    if (*argv == 'f') {
        delimiter = '\f';
    }
    if (*argv == 'n') {
        delimiter = '\n';
    }
    if (*argv == 'r') {
        delimiter = '\r';
    }
    if (*argv == 't') {
        delimiter = '\t';
    }
    if (*argv == 'v') {
        delimiter = '\v';
    }
    if (*argv == '\'') {
        delimiter = '\'';
    }
    if (*argv == '\"') {
        delimiter = '\"';
    }
    if (*argv == '\\') {
        delimiter = '\\';
    }
    if (*argv == '?') {
        delimiter = '\?';
    }
    return delimiter;
}


Arguments ComandParse(int argc,char** argv){
    Arguments args;
    args.flag_tail = false;
    args.delimiter = '\n';
    args.lines = -1;
    args.filename;
    bool flag_file = false;
    for (int i = 1; i < argc; ++i) {
        std::ifstream file(argv[i]);
        if (!file) {
            if (!((std::strcmp(argv[i], "--tail"))) || !((std::strcmp(argv[i], "-t")))) {
                args.flag_tail = true;
            } else if (!(std::strncmp(argv[i], "--lines=",8))) {
                if (argv[i][8] != '-') {
                    char* argvi_end;
                    args.lines = std::strtol(argv[i]+8, &argvi_end,10);
                }
            } else if (!(std::strcmp(argv[i],"-l"))) {
                char* argvi_end;
                args.lines = std::strtol(argv[i+1],&argvi_end,10);
            } else if (!(std::strncmp(argv[i],"--delimiter=",12))) {
                if (*(argv[i] + 12) == '\'' && *(argv[i]+14) == '\'') {
                    args.delimiter = *(argv[i] + 13);
                } else if (*(argv[i] + 12) == '\'' && *(argv[i]+13) == '\\' && *(argv[i]+15) == '\'') {
                    args.delimiter = EscapeChar(argv[i]+14);
                }
            } else if (!(std::strcmp(argv[i],"-d"))) {
                if (*(argv[i+1]) == '\'' && *(argv[i+1]+2) == '\'') {
                    args.delimiter = *(argv[i+1]+1);
                } else if (*(argv[i+1]) == '\'' && *(argv[i+1] + 3) == '\'' && *(argv[i+1] + 1) == '\\') {
                    args.delimiter = EscapeChar(argv[i+1]+2);
                }
            }
        }
        else {
            flag_file = true;
            args.filename = argv[i];
        }
    }
    if (!flag_file) {
        std::cout << "File isn't exist";
    }
    else {
        return args;
    }
}