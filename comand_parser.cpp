#include <iostream>
#include <cstring>
#include <fstream>
#include "file_parser.h"

void comand_parser(int argc,char** argv){
    bool flag_tail = false;
    char delimiter = '\n';
    int lines = -1;
    char* FILE;
    bool flag_file = false;
    for(int i = 1; i < argc; i++){
        std::ifstream file;
        file.open((argv[i]));
        if(!file){
            if((std::strcmp(argv[i], "--tail") == 0) || (std::strcmp(argv[i], "-t") == 0)){
                flag_tail = true;
            }
            if(std::strncmp(argv[i], "--lines=",8) == 0){
                if(argv[i][8] != '-'){
                    char* argvi_end;
                    lines = std::strtol(argv[i]+8, &argvi_end,10);
                }
            }
            if(std::strcmp(argv[i],"-l") == 0){
                char* argvi_end;
                lines = std::strtol(argv[i+1],&argvi_end,10);
            }
            if(std::strncmp(argv[i],"--delimiter=",12) == 0){
                if(*(argv[i] + 12) == '\'' && *(argv[i]+14) == '\''){
                    delimiter = *(argv[i] + 13);
                }
                if(*(argv[i] + 12) == '\'' && *(argv[i]+13) == '\\' && *(argv[i]+15) == '\''){
                    if(*(argv[i]+14) == 'a'){
                        delimiter = '\a';
                    }
                    if(*(argv[i]+14) == 'b'){
                        delimiter = '\b';
                    }
                    if(*(argv[i]+14) == 'f'){
                        delimiter = '\f';
                    }
                    if(*(argv[i]+14) == 'n'){
                        delimiter = '\n';
                    }
                    if(*(argv[i] + 14) == 'r'){
                        delimiter = '\r';
                    }
                    if(*(argv[i] + 14) == 't'){
                        delimiter = '\t';
                    }
                    if(*(argv[i] + 14) == 'v'){
                        delimiter = '\v';
                    }
                    if(*(argv[i] + 14) == '\''){
                        delimiter = '\'';
                    }
                    if(*(argv[i] + 14) == '\"'){
                        delimiter = '\"';
                    }
                    if(*(argv[i] + 14) == '\\'){
                        delimiter = '\\';
                    }
                    if(*(argv[i] + 14) == '?'){
                        delimiter = '\?';
                    }

                }
            }
            if(std::strcmp(argv[i],"-d") == 0){
                if(*(argv[i+1]) == '\'' && *(argv[i+1]+2) == '\''){
                    delimiter = *(argv[i+1]+1);
                }
                if(*(argv[i+1]) == '\'' && *(argv[i+1] + 3) == '\'' && *(argv[i+1] + 1) == '\\'){
                    if(*(argv[i+1]+2) == 'a'){
                        delimiter = '\a';
                    }
                    if(*(argv[i+1]+2) == 'b'){
                        delimiter = '\b';
                    }
                    if(*(argv[i+1]+2) == 'f'){
                        delimiter = '\f';
                    }
                    if(*(argv[i+1]+2) == 'n'){
                        delimiter = '\n';
                    }
                    if(*(argv[i+1]+2) == 'r'){
                        delimiter = '\r';
                    }
                    if(*(argv[i+1]+2) == 't'){
                        delimiter = '\t';
                    }
                    if(*(argv[i+1]+2) == 'v'){
                        delimiter = '\v';
                    }
                    if(*(argv[i+1]+2) == '\''){
                        delimiter = '\'';
                    }
                    if(*(argv[i+1]+2) == '\"'){
                        delimiter = '\"';
                    }
                    if(*(argv[i+1]+2) == '\\'){
                        delimiter = '\\';
                    }
                    if(*(argv[i+1]+2) == '?'){
                        delimiter = '\?';
                    }
                }
            }
        }
        else{
            flag_file = true;
            FILE = argv[i];
        }
    }
    if(!flag_file){
        std::cout << "File doesnt exist";
    }
    else {
        File_parser(FILE, lines, flag_tail, delimiter);
    }
}