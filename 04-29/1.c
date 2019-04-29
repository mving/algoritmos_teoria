#include <stdio.h>

int main(int argc, char const *argv[]) {
  FILE *pf;
  pf = fopen("datos.txt","r");
  /*
  r lee. si no E error
  w graba. Si no E se crea. Si E regraba
  a agrega. Si no E, crea
  r+ lee y graba. Si no E, error
  w+ lee y graba. Si no E, crea. Si E, se regraba
  a+ lee y graba. Si no E, crea. Si E se agrega
  FILE * fopen (const char * cadena, const char * modo)
  */
  if ((pf = fopen("datos.txt","r")) == NULL) {
    printf("error al abrir el archivo\n");
  }
  feof(FILE *pf); //devuelve 0 si esta bien. otro si esta mal
  fclose(pf);
  //funcion de E/S para chars
  int ftutc(int car, FILE *pf);
  if (fputc('a',pf)!= EOF) {
  }
  int fgetc(FILE *pf);//caracter leido. EOF si hubo error
  float v;
  char cad[30];
  int a;
  char car;
  scanf("%d\n",&a);
  scanf("%f\n",&v);
  scanf("%s\n",cad);
  scanf("%c\n",&car);
  return 0;
}

/*
struct FILE{
  char *ptr;  //puntero al sig del buffer
  int c;      //cant de bytes q quedan en el buffer
  .
  .
  .
}
*/
