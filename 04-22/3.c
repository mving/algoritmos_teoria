#include <stdio.h>
#include <stdlib.h>

typedef struct PERS{
  char nom[30];
  int edad;
  long dni;
}T_PERS;

int main(int argc, char const *argv[]) {
  T_PERS A;
  int n = 4;
  T_PERS vp[10];
  T_PERS ** vpd = (T_PERS **) malloc (sizeof(T_PERS*)*n);
  T_PERS * pp = (T_PERS *) malloc (sizeof(T_PERS));
  for (size_t i = 0; i < n; i++) {
    vpd[i]=(T_PERS*)malloc(sizeof(T_PERS));
  }

  //acceder

  (*pp).nombre; // pp->nombre
  (*pp).edad; // pp->edad
  vpd[i]->nombre;
  return 0;
}
