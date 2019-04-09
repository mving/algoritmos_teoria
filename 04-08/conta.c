#include <stdio.h>
#include <strig.h>

#define MAX 100

int main() {
  char oracion[MAX], char car[2];
  fgets(oracion,MAX,stdin);
  strtok(oracion,'\n');

  return 0;
}

int cant_carac()
