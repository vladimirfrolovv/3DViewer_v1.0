#ifndef SRC_S21_3DVIEVER_H_
#define SRC_S21_3DVIEVER_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct points_struct{
  double x,y,z;
} points;

typedef struct vertex_struct {
  int minmax_p[2];
  points *coord;
  int amount_ver;
}vertex;

typedef struct poiligons_struct{
  int amount_pol;
  int *p;
} poligons;

typedef struct exit_struct {
    vertex *v;
  poligons *p;
}exit_st;



#endif //SRC_S21_3DVIEVER_H_