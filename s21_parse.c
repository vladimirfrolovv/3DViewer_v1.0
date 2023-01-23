#include "s21_3DViewer.h"

int main() {
  int status = 0;
  int amount_ver = 0;
  int amount_pol = 0;
  exit_st st= {0};
  s21_amount_value("FinalBaseMesh.obj", &status,&st);
  // printf("%d %d\n", amount_ver, amount_pol);
  return 0;
}

exit_st s21_parse() { return st; }

int s21_amount_value(char *filename, int *status, exit_st *st) {
  ssize_t read = 0;
  char *line = NULL;
  size_t size_line = 0;
  FILE *file = fopen(filename, "r");
  char sym = ' ';
  if (file != NULL) {
    while ((read = getline(&line, &size_line, file)) != -1) {
      if (line[0] == 'v' && line[1] == ' ') {
        st->amount_struct_ver += 1;
      }

      if (line[0] == 'f' && line[1] == ' ') {
        st->amount_struct_pol += 1;
      }
    }

    free(line);
  }
  printf("%d ", st->amount_struct_ver);
  printf("%d\n", st->amount_struct_pol);

  fclose(file);
}

int s21_init_struct(exit_st *st) { 
  int status =0;
   if ((st->p =(poligons*) calloc(st->amount_struct_pol,sizeof(poligons))) == NULL){
    status =1;
   } 

  if ((st->v =(vertex*) calloc(st->amount_struct_ver,sizeof(vertex))) == NULL){
    status =1;
  }
  return status;
 }