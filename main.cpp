#include "comand_parser.h"
#include "file_parser.h"


int main(int argc, char** argv){
    Arguments args = ComandParse(argc,argv);
    PrintFile(args);
    return 0;
}