#include "s21_3DViewer.h"

int main() {
  int status = 0;
  int amount_ver = 0;
  int amount_pol = 0;
  exit_st st = {0};
  s21_parse("test.obj");
  return 0;
}

exit_st s21_parse(char *filename) {
  exit_st *st = (exit_st *)calloc(1, sizeof(exit_st));
  int status = 0;
  status = s21_fill_amount(filename, st);
  s21_init_struct(st);
  ssize_t read = 0;
  char *line = NULL;
  size_t size_line = 0;
  FILE *file = fopen(filename, "r");
  char *ptr = line;
  int vertex_counter = 0;
  while ((read = getline(&line, &size_line, file)) != -1) {
    ptr = line;
    if (*ptr == 'v') {
      parse_vertex(&(st->v[vertex_counter]), ptr, vertex_counter);
      vertex_counter++;
    } else if(*ptr == 'f'){
      
    }
  } 
  printf("%lf", st->v[1].y);
  free(st);
  return *st;
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
  return status;
}

int s21_init_struct(exit_st *st) {
  int status = 0;
  st->p = (poligons *)calloc(st->amount_struct_pol, sizeof(poligons));
  st->v = (vertex *)calloc(st->amount_struct_ver, sizeof(vertex));
  return status;
}

void parse_vertex(vertex *v, char *ptr, int vertex_counter) {
  ptr++;
  if (*ptr == ' ') {
    while (*ptr != '\0') {
      if (!isdigit(*ptr)) {
        ptr++;
      } else {
        v->x = strtod(ptr, &ptr);
        while (*ptr == ' ') {
          ptr++;
        }
        v->y = strtod(ptr, &ptr);
        while (*ptr == ' ') {
          ptr++;
        }
        v->z = strtod(ptr, &ptr);
      }
    }
  }
}
