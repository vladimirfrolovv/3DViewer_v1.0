#ifndef SRC_S21_3DVIEVER_H_
#define SRC_S21_3DVIEVER_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// typedef struct points_struct{
  
// } points;

typedef struct vertex_struct {
  double x,y,z;
}vertex;

typedef struct poiligons_struct{
  int *p;
  int amount_pol;
} poligons;

typedef struct exit_struct {
  int minmax_coor[2];
  int amount_pol;
  int amount_ver;
  vertex *v;
  poligons *p;
}exit_st;

exit_st s21_parse(char *filename, int *status, int *amount_ver,
                  int *amount_pol);

#endif //SRC_S21_3DVIEVER_H_