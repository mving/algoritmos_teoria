//punteros
#include <stdio.h>

int main() {
  int a = 5, b = 10;
  //float x = 31;
  //char z = 'a';
  int v[]={1,2,3,4,5};
  //punteros
  int * p = &a;
  //el & me devuelve la direccion de memoria que se le asigno
  //imprimir el puntero
  printf("%d\n",*p );
  // a y *p son alias
  // *p = 8 es lo mismo que a = 8
  *p = 8;
  a = 8;
  p = &b;
  b++;
  printf("%d %d\n",*p,b);
  p = v;
  printf("%d\n",*p);
  printf("%d\n",p[0]);
  printf("%d\n",*v);
  printf("---\n");
  for (int i = 0; i < 5; i++) {
    printf("%d\n",p[i]);
  }
  printf("---\n");
  for (size_t i = 0; i < 5; i++) {
    printf("%d\n",*p);
    p += 1;
  }
  p=v;  //es necesario porque cambie el valor de *p
  printf("---\n");
  for (size_t i = 0; i < 5; i++) {
    printf("%d\n",*(p++));
  }p=v;
  printf("---\n");
  for (size_t i = 0; i < 5; i++) {
    printf("hola%d\n",*(p+i));
    //*(p+i) == p[i]
  }
  printf("---\n");
  for (size_t i = 0; i < 5; i++) {
    printf("%d\n",*(v+i));
  }
  printf("---\n");
  p = v + 1;
  for (size_t i = 0; i < 4; i++) {
    printf("%d %d\n",v[i],*(p+i));
  }p = v;
  printf("---\n");
  p = &v[1];
  for (size_t i = 0; i < 3; i++) {
    printf("%d %d\n",v[i],*(p+i));
  }
  return 0;
}
