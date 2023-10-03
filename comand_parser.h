#ifndef LABWORK1_VYACHESLAV_ATAMANYUK_COMAND_PARSER_H
#define LABWORK1_VYACHESLAV_ATAMANYUK_COMAND_PARSER_H
#include <cstdint>

struct Arguments{
public:
    char* filename;
    uint64_t lines;
    bool flag_tail;
    char delimiter;
};

Arguments ComandParse(int argc, char** argv);
#endif //LABWORK1_VYACHESLAV_ATAMANYUK_COMAND_PARSER_H
