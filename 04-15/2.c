#include <stdio.h>

void intercambio(int *x, int *y){
  int aux = *x;
  *x = *y;
  *y = aux;
}

int int main() {
  int a=10, b=20;
  intercambio(&a,&b);
  printf("%d-%d\n",a,b);
  return 0;
}
