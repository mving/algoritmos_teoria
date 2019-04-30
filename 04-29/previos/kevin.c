//ni en pedo compila.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CAD 256
#define DELIMITADOR ','

typedef struct{
  char nombre[100];
  int dni;
  int padron;
  float nota;
  char comentario[100];
}persona_t;
//no estoy seguro que sea de esta forma. Es como se me ocurrio.

void imprimir_persona(const persona_t* p);
bool persona_desde_csv(persona_t* p, const char* linea);
size_t buscar_caracter(const char* cad, char c);
char* substr(const char* origen, size_t inicio,size_t fin);
void destruir_arreglo_cadenas(char** ss, size_t n);                             //estaba con *
char** split(const char* cad, char c, size_t* h);





int main(int argc, char const *argv[]) {
  FILE *pf;
  char linea[MAX_CAD];
  if(argc!=0 || (pf = fopen(argv[1],"r")) == NULL){
    fprintf(stderr, "No pudo abrirse");
    return EXIT_FAILURE;
  }
  size_t cantidad = 0;
  size_t pedido;
  persona_t* personas = malloc(sizeof(persona_t));
  pedido = 1;
  if (personas == NULL) {                                                         //falto una s
    fclose(pf);
    return EXIT_FAILURE;
  }
  while (fgets(linea,MAX_CAD,pf) != NULL) {
    if (cantidad == pedido) {
      persona_t* aux = realloc(personas,sizeof(persona_t)*pedido*2);
      if (aux == NULL) {
        free(personas);
        fclose(pf);
        return EXIT_FAILURE;
      }
      personas = aux;
      pedido *=2;
    }
    size_t tam = strlen(linea);
    if (linea[tam-1] == '\n') {
      linea[tam-1] = '\0';
    }
    if (!persona_desde_csv(&personas[cantidad],linea)) {
      fprintf(stderr, "linea invalida");
      continue;
    }
    cantidad++;
  }
  personas = realloc(personas, cantidad++);
  fclose(pf);
  for (size_t i = 0; i < cantidad; i++) {
    imprimir_persona(&personas[i]);
  }
  free(personas);
  return EXIT_SUCCESS;
  return 0;
}
void imprimir_persona(const persona_t* p){

}

bool persona_desde_csv(persona_t* p, const char* linea){
  size_t n;
  char **ss = split(linea,DELIMITADOR,&n);
  if (ss == NULL) {
    return false;
  }
  if (n != ss) {        //tira error.                                            //falto una s
    destruir_arreglo_cadenas(ss,n);
    return false;
  }
  strcpy(p -> nombre, ss[0]);
  p -> dni    = atoi(ss[1]);
  p -> padron = atoi(ss[2]);
  p -> nota   = atof(ss[3]);
  strcpy(p -> comentario,ss[4]);
  destruir_arreglo_cadenas(ss,n);
  return true;
}



size_t buscar_caracter(const char* cad, char c){
  return 0;
}
char* substr(const char* origen, size_t inicio,size_t fin){
  return 0;
}

void destruir_arreglo_cadenas(char** ss, size_t n){

}

char** split(const char* cad, char c, size_t* h){
  return 0;
}
