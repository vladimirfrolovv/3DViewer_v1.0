#ifndef SRC_S21_3DVIEVER_H_
#define SRC_S21_3DVIEVER_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// typedef struct points_struct{

// } points;

typedef struct vertex_struct {
  double x, y, z;
} vertex;
// vertex ->  *ptr= calloc ( amount_ver, sizeof(vertex_struct);
// ptr[index] = calloc(3, sizeof(double));
// ptr[index][x] = 1 , 2 , 3

//  amount of vertex ;
// ptrofpol[index] = calloc (amoun, sizeof(int));
// ptrofpol[index][ 0 1 2 3 ] = int;

typedef struct poiligons_struct {
  int *poligon;
  int amount_pol;
} poligons;

typedef struct exit_struct {
  double minmaxX[2];
  double minmaxY[2];
  double minmaxZ[2];
  int amount_struct_pol;
  int amount_struct_ver;
  vertex *v;
  poligons *p;
} exit_st;

exit_st s21_parse(char *filename);
int s21_fill_amount(char *filename, exit_st *st);
int s21_init_struct(exit_st *st);
void parse_vertex(vertex *v, char *ptr, exit_st *st);
int memory_for_pol(char *ptr, poligons *p);
void parse_poligons(char *ptr, poligons *p);
#endif  // SRC_S21_3DVIEVER_H_