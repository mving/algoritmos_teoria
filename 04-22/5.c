#include <stdio.h>
#include <stdlib.h>


typedef struct PERS{
  char nombre[30];
  int edad;
  long dni;
}T_PERS;

T_PERS * crear_vector(int c){
  return (T_PERS *)malloc(sizeof(T_PERS)*c);
}

void leer_datos_persona(T_PERS *v, int c){
  int i;
  for (i = 0; i < c; i++) {
    printf("ingrese nombre\n");
    fgets(v[i].nombre,30,stdin);
    char input[30];
    printf("ingrese edad\n");
    fgets(input,30,stdin);
    v[i].edad = atoi(input);
    printf("ingrese dni\n");
    fgets(input,30,stdin);
    v[i].dni=atof(input);
  }
}

void imprimir_vector_persona(T_PERS *v, int c){
  int i;
  for (i = 0; i < c; i++) {
    printf("%s %d \n%ld\n",v[i].nombre,v[i].edad,v[i].dni);
  }
}

int main(int argc, char const *argv[]) {
  T_PERS *vpd;
  char input[30];
  fgets(input,30,stdin);
  int n = atoi(input);
  vpd = crear_vector(n);
  leer_datos_persona(vpd,n);
  imprimir_vector_persona(vpd,n);
  return 0;
}
