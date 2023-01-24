#include "s21_3DViewer.h"

int main() {
  int status = 0;
  int amount_ver = 0;
  int amount_pol = 0;
  exit_st st = {0};
  s21_amount_value("FinalBaseMesh.obj", &st);
  s21_init_struct(&st);
  return 0;
}

exit_st s21_parse(char *filename) {
  exit_st *st = (exit_st *)calloc(1, sizeof(exit_st));
  int err = 0;
  err = s21_fill_amount(filename, &st);

  return st;
}

int s21_fill_amount(char *filename, exit_st *st) {
  int status = 0;
  ssize_t read = 0;
  char *line = NULL;
  size_t size_line = 0;
  FILE *file = fopen(filename, "r");
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
    fclose(file);
  } else {
    status = 1;
  }
  // printf("%d ", st->amount_struct_ver);
  // printf("%d\n", st->amount_struct_pol);

  return status;
}

exit_st *s21_init_struct(int amount_ver, int amount_pol) {
  st->p = (poligons *)calloc(st->amount_struct_pol, sizeof(poligons));
}

int s21_init_struct(exit_st *st) {
  st->p = (poligons *)calloc(st->amount_struct_pol, sizeof(poligons));
}

if ((st->v = (vertex *)calloc(st->amount_struct_ver, sizeof(vertex))) == NULL) {
  status = 1;
}
return status;
}