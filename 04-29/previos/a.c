/*#include <stdio.h>

#define DELIMITADOR ','

int main(int argc, char const *argv[]) {
  char input[100];
  fgets(input,100,stdin);
  char hold[10];
  char aux[100];
  sprintf(aux,"%%[^%c]",DELIMITADOR);
  for (size_t i = 0; i < 5; i++) {
  //  scanf(aux,&hold);
    fgets(aux,100,cad);
  }
  return 0;
}

#include <stdio.h>

#define DELIMITADOR ','

int main() {
  char aux[100];
  sprintf(aux,"%%[^%c]%c%%u%c%%u%c%%f%c%%s",DELIMITADOR, DELIMITADOR, DELIMITADOR, DELIMITADOR, DELIMITADOR);
  printf("%s\n",aux);
  char input[100];
  char input2[100];
  printf("Ingreso de datos\n");
  scanf(aux,&input);
  scanf(aux,&input2);
  printf("!!%s\n%s",input,input2 );
  return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char tipo [1];
    float n1, n2, n3, n4;
    int i;
    FILE *stream;
    stream=fopen("init.txt", "r");
    if ((stream=fopen("alumnos.txt", "r"))==NULL) {
        printf("Error");
    } else {
        i=0;
        while (i<4) {
            i++;
//i know i could use a for instead of a while
            fscanf(stream, "%s %f %f %f %s%", &tipo, &n1, &n2, &n3, &n4);
            printf("%s %d %d %d %f", tipo, n1, n2, n3, n4);
        }
    }
    return 0;
}
