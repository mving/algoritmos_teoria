#include <stdio.h>
#include <string.h>

#define MAX 100

void elimina_espacios(char cad[]);
int cont_caract(char cad[], char c);
int main() {
  char oracion[MAX];
  printf("Ingrese oracion\n");
  fgets(oracion,MAX,stdin);
  strtok(oracion,"\n");
  elimina_espacios(oracion);
  printf("%s\n",oracion);

  char car[2];
  printf("Ingrese caracter a contar\n");
  fgets(car,2,stdin);
  //strtok(oracion,'\n');
  printf("la cantidad de caracteres %c en la cadena %s es de :%d\n",car[0],oracion,cont_caract(oracion,*car) );
  char test[MAX];
  printf("ingrese\n");
  fgets(test,MAX,stdin);
  printf("h!%s\n",test);
  return 0;
}

void elimina_espacios(char cad[]){
  int j=0;
  int posicion=0;
  /*for (size_t posicion = 0; cad[posicion]!=' '; posicion++) {
  }
  if (cad[posicion]==' ') {
    posicion++;
  }*/
  while (cad[posicion]==' ' && cad[posicion]!='\0') {
    posicion++;
  }
  for (size_t i = posicion; i < strlen(cad); i++) {
    if (cad[i] != ' ') {
      cad[j]=cad[i];
      j++;
    }else if (cad[i-1]!= ' ') {
      cad[j]=' ';
      j++;
    }
  }
  if (cad[j-1]==' ') {
    j--;
  }
  cad[j]='\0';
}

int cont_caract(char cad[], char c){
  int cont=0;
  for (size_t i = 0; cad[i] != '\0'; i++) {
    if (cad[i]==c) {
      cont++;
    }
  }
  return cont;
}
