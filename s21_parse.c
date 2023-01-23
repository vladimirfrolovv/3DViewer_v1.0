#include "s21_3DViewer.h"

int main() {
  int status = 0;
  int amount_ver = 0;
  int amount_pol = 0;
  s21_parse("test.obj", &status, &amount_ver, &amount_ver);
    //printf("%d %d\n", amount_ver, amount_pol);
  return 0;
}

exit_st s21_parse(char *filename, int *status, int *amount_ver,
                  int *amount_pol) {
  exit_st st = {0};
  ssize_t read = 0;
  char *line = NULL;
  size_t size_line = 0;
  FILE *file = fopen(filename, "r");
  char sym = ' ';
  if (file != NULL) {
    while ((read = getline(&line, &size_line, file)) != -1) {
      if (strcmp("v",line)) {
        *amount_ver+=1;
        //   printf("debug");
      }
    
      if (strcmp("f",line)) {
        *amount_pol+=1;
      }
    }
    
    free(line);
  }
  printf("%d ", *amount_pol);
  printf("%d\n", *amount_ver);
    
  fclose(file);
  return st;
}