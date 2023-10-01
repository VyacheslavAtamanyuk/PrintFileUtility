#include <iostream>
#include <fstream>

void File_parser(char* FILE, int lines, bool flag_tail, char delimiter){
    std::ifstream file(FILE, std::ios::binary);
    int test_lines = 0;
    char b;
    while(!file.eof()){
        file.get(b);
        if(b == delimiter && !file.eof()){
            test_lines++;
        }
    }
    if(lines == -1 || lines > test_lines + 1){
        std::ifstream file(FILE, std::ios::binary);
        char a;
        while(!file.eof()){
            file.get(a);
            if(!file.eof()){
                std::cout << a;
            }
        }
    }
    else{
        if(flag_tail){
            std::ifstream file(FILE, std::ios::binary);
            int count_of_delimiter = 0;
            char a;
            while(!file.eof()){
                file.get(a);
                if(a == delimiter && !file.eof()){
                    count_of_delimiter++;
                }
            }
            if(count_of_delimiter == 0){
                std::ifstream file(FILE, std::ios::binary);
                while(!file.eof()){
                    file.get(a);
                    if(!file.eof()){
                        std::cout << a;
                    }
                }
            }
            else{
                std::ifstream file(FILE, std::ios::binary);
                int count_of_delimiter1 = 0;
                bool lets_go = false;
                while (!file.eof()) {
                    file.get(a);
                    if (lets_go) {
                        if (!file.eof()) {
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
        else{
            std::ifstream file(FILE, std::ios::binary);
            int counter = 0;
            char a;
            while(!file.eof()){
                file.get(a);
                if(!file.eof()){
                    std::cout << a;
                }
                if(a == delimiter){
                    counter++;
                }
                if(counter == lines){
                    break;
                }
            }
        }
    }
}