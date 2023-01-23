#include "s21_3DViewer.h"

int main() { return 0; }

exit_st s21_parse(char *filename, int *status){
    exit_st st = {0};
    ssize_t line = 0;
    size_t size_line = 0;
    FILE* file = fopen(filename, "r");
    char sym = ' ';
    
    if(file != NULL){
        while(line != ){
            sym= fgetc(file);
            if(sym == 'v') {
              sym= fgetc(file);
              sym= fgetc(file);
            //   fscanf(file, "v %lf %lf %lf", )
            //   if(isdigit)  
            }
        }
    }
    return st;
}