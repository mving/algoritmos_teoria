#include <stdio.h>

void sumar_uno(int *a, int n);
int * sumar_vec(int *a, int *b, int n);

int main() {
  int v[] = {1,2,3,4,5};
  sumar_uno(v,5);
  for (size_t i = 0; i < 5; i++) {
    printf("%d\n",v[i]);
  }
  printf("---\n");
  int pirulin[] = {5,6,7};
  sumar_uno(pirulin,3);
  //Se le suma 1 a cada posicion porque a la funcion le estoy pasando la direccion de memoria
  sumar_uno(pirulin+1,2);
  //suma 1 a las posiciones 1 y 2 del vector, pero no a la 0
  printf("---\n");

  return 0;
}

void sumar_uno(int *a, int n){
  for (size_t i = 0; i < n; i++) {
    a[i] += 1;
  }
}

int * sumar_vec(int *a, int *b, int n){
  return 0;
}
