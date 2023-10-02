#include <iostream>
#include <fstream>
#include <cstdint>
#include "file_parser.h"


void PrintHead(char delimiter, char* filename, uint64_t lines){
    std::ifstream file(filename, std::ios::binary);
    int counter = 0;
    char a;
    while (file.get(a)) {
        file.get(a);
        if (file.get(a)) {
            std::cout << a;
        }
        if (a == delimiter) {
            counter++;
        }
        if (counter == lines) {
            break;
        }
    }
}

void PrintTail(char delimiter, char* filename, uint64_t lines){
    std::ifstream file(filename, std::ios::binary);
    int count_of_delimiter = 0;
    char a;
    while (file.get(a)) {
        file.get(a);
        if (a == delimiter && file.get(a)) {
            count_of_delimiter++;
        }
    }
    if (count_of_delimiter == 0) {
        std::ifstream file(filename, std::ios::binary);
        while (file.get(a)) {
            file.get(a);
            if (file.get(a)) {
                std::cout << a;
            }
        }
    }
    else {
        std::ifstream file(filename, std::ios::binary);
        int count_of_delimiter1 = 0;
        bool lets_go = false;
        while (file.get(a)) {
            file.get(a);
            if (lets_go) {
                if (file.get(a)) {
                    std::cout << a;
                }
            }
            if (a == delimiter && count_of_delimiter1 < count_of_delimiter - lines + 1) {
                count_of_delimiter1++;
                if (count_of_delimiter1 == count_of_delimiter - lines + 1) {
                    lets_go = true;
                }
            }
        }
    }
}

void FileParse(char* filename, uint64_t lines, bool flag_tail, char delimiter){
    std::ifstream file(filename, std::ios::binary);
    uint64_t test_lines = 0;
    char b;
    while (file.get(b)){
        file.get(b);
        if (b == delimiter && file.get(b)) {
            test_lines++;
        }
    }
    if (lines == -1 || lines > test_lines + 1) {
        std::ifstream file(filename, std::ios::binary);
        char a;
        while (file.get(a)) {
            file.get(a);
            if (file.get(a)) {
                std::cout << a;
            }
        }
    } else if (flag_tail) {
        PrintTail(delimiter, filename, lines);
    } else {
        PrintHead(delimiter, filename, lines);
    }
}