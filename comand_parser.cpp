#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdint>
#include "comand_parser.h"
#include "file_parser.h"

void EscapeChar(char* argv, char* delimiter){
    if (*argv == 'a') {
        *delimiter = '\a';
    }
    if (*argv == 'b') {
        *delimiter = '\b';
    }
    if (*argv == 'f') {
        *delimiter = '\f';
    }
    if (*argv == 'n') {
        *delimiter = '\n';
    }
    if (*argv == 'r') {
        *delimiter = '\r';
    }
    if (*argv == 't') {
        *delimiter = '\t';
    }
    if (*argv == 'v') {
        *delimiter = '\v';
    }
    if (*argv == '\'') {
        *delimiter = '\'';
    }
    if (*argv == '\"') {
        *delimiter = '\"';
    }
    if (*argv == '\\') {
        *delimiter = '\\';
    }
    if (*argv == '?') {
        *delimiter = '\?';
    }
}


void ComandParser(int argc,char** argv){
    bool flag_tail = false;
    char delimiter = '\n';
    int lines = -1;
    char* filename;
    bool flag_file = false;
    for(int i = 1; i < argc; i++){
        std::ifstream file;
        file.open((argv[i]));
        if (!file) {
            if ((std::strcmp(argv[i], "--tail") == 0) || (std::strcmp(argv[i], "-t") == 0)) {
                flag_tail = true;
            } else if (std::strncmp(argv[i], "--lines=",8) == 0) {
                if (argv[i][8] != '-') {
                    char* argvi_end;
                    lines = std::strtol(argv[i]+8, &argvi_end,10);
                }
            } else if (std::strcmp(argv[i],"-l") == 0) {
                char* argvi_end;
                lines = std::strtol(argv[i+1],&argvi_end,10);
            } else if (std::strncmp(argv[i],"--delimiter=",12) == 0) {
                if (*(argv[i] + 12) == '\'' && *(argv[i]+14) == '\'') {
                    delimiter = *(argv[i] + 13);
                } else if (*(argv[i] + 12) == '\'' && *(argv[i]+13) == '\\' && *(argv[i]+15) == '\'') {
                    char* pointer_to_delimiter = &delimiter;
                    EscapeChar(argv[i]+14, pointer_to_delimiter);
                }
            } else if (std::strcmp(argv[i],"-d") == 0) {
                if (*(argv[i+1]) == '\'' && *(argv[i+1]+2) == '\'') {
                    delimiter = *(argv[i+1]+1);
                } else if (*(argv[i+1]) == '\'' && *(argv[i+1] + 3) == '\'' && *(argv[i+1] + 1) == '\\') {
                    char* pointer_to_char = &delimiter;
                    EscapeChar(argv[i+1]+2, pointer_to_char);
                }
            }
        }
        else {
            flag_file = true;
            filename = argv[i];
        }
    }
    if (!flag_file) {
        std::cout << "File isn't exist";
    }
    else {
        FileParse(filename,lines,flag_tail,delimiter);
    }
}