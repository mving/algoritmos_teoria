#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int leer_entero(char *mensaje){
  char cad[20];
  printf("%s\n",mensaje);
  return atoi(cad);
}

void ingresar_cadenas(char *v[], int c){
  char cad[30];
  int i;
  for (i = 0; i < c; i++) {
    fgets(cad,30,stdin);
    v[i]=(char *) malloc(strlen(cad)+1);
    strcpy (v[i],cad);
  }

}

int main(int argc, char const *argv[]) {
  int a=10;
  int *p = null;
  p = (int *)malloc(sizeof(int));
  int *v;
  int n;
  n = leer_entero("ingrese un numero que representa la cantidad de elementos");
  v = (int *) malloc(sizeof(int)*n);
  char *vpc[10];
  ingresar_cadenas(vpc,10);
  char **vpcdin;
  n = leer_entero("ingrese cantidad de cadenas");
  vpcdin = (char **)malloc(sizeof(char *)*n);
  ingresar_cadenas(vpcdin,n);
  int *mat[10];
  int **matd;
  for (size_t i = 0; i < n; i++) {
    free(vpcdin[i]);
  }
  free(vpcdin);
  return 0;
}
