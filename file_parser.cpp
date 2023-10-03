#include <iostream>
#include <fstream>
#include <cstdint>
#include "file_parser.h"
#include "comand_parser.h"


void PrintHead(Arguments args){
    std::ifstream file(args.filename, std::ios::binary);
    int counter = 0;
    char a;
    while (file.get(a)) {
        std::cout << a;
        if (a == args.delimiter) {
            counter++;
        }
        if (counter == args.lines) {
            break;
        }
    }
}

void PrintTail(Arguments args){
    std::ifstream file(args.filename, std::ios::binary);
    int count_of_delimiter = 0;
    char a;
    while (file.get(a)) {
        if (a == args.delimiter) {
            count_of_delimiter++;
        }
    }
    if (count_of_delimiter == 0) {
        std::ifstream file(args.filename, std::ios::binary);
        while (file.get(a)) {
            std::cout << a;
        }
    }
    else {
        std::ifstream file(args.filename, std::ios::binary);
        int count_of_delimiter1 = 0;
        bool lets_go = false;
        while (file.get(a)) {
            if (lets_go) {
                std::cout << a;
            }
            if (a == args.delimiter && count_of_delimiter1 < count_of_delimiter - args.lines + 1) {
                count_of_delimiter1++;
                if (count_of_delimiter1 == count_of_delimiter - args.lines + 1) {
                    lets_go = true;
                }
            }
        }
    }
}

void PrintFile(Arguments args){
    std::ifstream file(args.filename, std::ios::binary);
    uint64_t test_lines = 0;
    char b;
    while (file.get(b)) {
        if (b == args.delimiter) {
            ++test_lines;
        }
    }
    if (args.lines == -1 || args.lines > test_lines + 1) {
        std::ifstream file(args.filename, std::ios::binary);
        char a;
        while (file.get(a)) {
            std::cout << a;
        }
    } else if (args.flag_tail) {
        PrintTail(args);
    } else {
        PrintHead(args);
    }
}