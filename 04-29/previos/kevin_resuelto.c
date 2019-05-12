#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CAD 100
#define MAX_LINEA 256
#define DELIMITADOR ','
#define COLUMNAS 5

typedef struct{
  char nombre[MAX_CAD];
  unsigned int dni;
  unsigned int padron;
  float nota;
  char comentario[MAX_CAD];
}persona_t;

//char** reservar_memoria(const char* cad, char separador);
void imprimir_persona(const persona_t* p);
bool persona_desde_csv(persona_t* p, const char* linea);
size_t contador_columnas(const char* cad, char c);
size_t contador_caracteres(const char* cad,char c, size_t* n);
//char* substr(const char* origen, size_t inicio,size_t fin);
void destruir_arreglo_cadenas(char** ss, size_t n);                             //estaba con *
char** split(const char* cad, char c, size_t* n);


int main(int argc, char const *argv[]) {
  FILE *pf;
  char linea[MAX_CAD];
  if(argc!=2 || (pf = fopen(argv[1],"r")) == NULL){
    fprintf(stderr, "No pudo abrirse\n");
    return EXIT_FAILURE;
  }
  size_t cantidad = 0; //cantidad de persona_t's en personas
  size_t cant_lineas = 1;
  size_t pedido; //cantidad de memoria que tengo para guardar persona_t's en unidades
  persona_t* personas = malloc(sizeof(persona_t)); //reservo memoria para un solo persona_t
  pedido = 1;
  if (personas == NULL) {
    fclose(pf);
    return EXIT_FAILURE;
  }

  //ya terminaron todas las comprobaciones. Acá arranca el programa

  while (fgets(linea,MAX_LINEA,pf) != NULL) {     //guardo en linea cada linea del txt
    if (cantidad == pedido) { //esto significa que si la cantidad de persona_t estan llenas, necesito reservar mas memoria
      persona_t* aux = realloc(personas,sizeof(persona_t)*pedido*2); //aumento 2 veces la memoria que tengo en este momento
      if (aux == NULL) {
        free(personas);
        fclose(pf);
        return EXIT_FAILURE;
      }
      //terminan las comprobaciones
      personas = aux;
      pedido *=2;
    }

    linea[strcspn(linea, "\n")] ='\0'; //me gusta mas así. Me da la ubicacion del \n,y reemplazo esa posicion de linea, si no lo encuentra me de la ubicacion del \0

    if (!persona_desde_csv(&personas[cantidad],linea)) { //es un bool que se encarga de guardar cada elemento de la linea en su persona_t correspondiente
      fprintf(stderr, "linea %zd invalida\n",cantidad + cant_lineas);
      cant_lineas++;
      continue;
    }

    cantidad++; //aumento el contador de elementos en 1
  } //fin del while
  personas = realloc(personas, sizeof(persona_t)*cantidad); //achico personas y quito la memoria sobrante

  //una vez que termino todo hago esto
  fclose(pf);
  for (size_t i = 0; i < cantidad; i++) {
    imprimir_persona(&personas[i]);
  }
  free(personas);
  return EXIT_SUCCESS;
  return 0;
}
void imprimir_persona(const persona_t* p){
  printf("nombre: %s, dni: %d, padron: %d, nota: %.2f, comentarios: %s\n",p -> nombre, p -> dni, p -> padron, p -> nota, p -> comentario);
}

//le paso la direccion de memoria del persona_t personas[i], y la linea entera del archivo
bool persona_desde_csv(persona_t* p, const char* linea){
  size_t n;
  char** ss = split(linea,DELIMITADOR,&n); //en ss se guaran los datos que necesito guardar en el persona_t
  if (ss == NULL) {
    return false;
  }

  strcpy(p -> nombre, ss[0]); //SACA EL ESPECIO ENTRE LA FLECHA
  p -> dni    = atoi(ss[1]);
  p -> padron = atoi(ss[2]);
  p -> nota   = atof(ss[3]);
  strcpy(p -> comentario,ss[4]);

  destruir_arreglo_cadenas(ss,n);
  return true;
}

size_t contador_columnas(const char* cad, char c){
  size_t columnas = 1;
  for (size_t i = 0; cad[i] != '\0'; i++) {
    if (cad[i]==DELIMITADOR) {
      columnas++;
    }
  }
  if (columnas != COLUMNAS) { //guardo 0, porque es lo que me va a indicar que están mal las columnas(la cagada es que hay que modificar el define para que funcione con otros)
    columnas = 0;
  }
  return columnas;
}

/*no se cual es la funcion de la funcion
char* substr(const char* origen, size_t inicio,size_t fin){
  return 0;
}
*/

void destruir_arreglo_cadenas(char** ss, size_t n){
  for (size_t i = 0; i < n; i++) {
    free(ss[i]);
  }
  free(ss);
}

//c es donde separa la cadena (,) n es el valor que guardo en la direccion
// de memoria con el numero de columnas, cad es el contenido de la linea
char** split(const char* cad, char c, size_t* n){
  //char** spliteado = reservar_memoria(cad,c);
  size_t size;
  *n = contador_columnas(cad,c); //n me devuelve la cantidad de elementos
  if (*n == 0) {
    return NULL;  //*n = 0 cada vez que la cantidad de columnas sea distinto a lo definido
  }
  char** spliteado = malloc(sizeof(char*)*(*n));
    if (spliteado == NULL) {
      free(spliteado);
      return NULL;
    }
  size_t posicion = 0;  //en posicion guardo donde estaba la , cada vez que entro a contador_caracteres
  for (size_t i = 0; i < *n; i++) {
    size = contador_caracteres(cad,c,&posicion); //la cantidad de chars que tiene
    spliteado[i] = malloc(sizeof(char)*(size+1)); //guardo memoria para cada uno de los char + 1 para el \0
    if (spliteado[i] == NULL) {
      for (size_t j = 0; j <= i; j++) {
        free(spliteado[i]);
      }
      free(spliteado);
      return NULL;
    }
  }
  size_t j = 0;
  size_t aux;
  //aca guardo
  for (size_t i = 0; i < *n; i++) {
    aux = 0;
    for (; cad[j] != c && cad[j] != '\0'; j++) {
      spliteado[i][aux] = cad[j];
      aux++;
    }
    spliteado[i][aux]='\0';
    //printf("PRUEBA: %s\n", spliteado[i]); FUNCA BIEN
    j++;
  }
  return spliteado;
}

/*char** reservar_memoria(const char* cad, char separador){
  size_t size_palabra;
  size_t cantidad_columnas = contador_columnas(cad,separador); //n me devuelve la cantidad de elementos
  if (cantidad_columnas == 0) {
    return NULL;
  }
  char** cadena = malloc(sizeof(char*)*(cantidad_columnas));
  for (size_t i = 0; i < cantidad_columnas; i++) {
    size_palabra = contador_caracteres(cad,separador,i);
    cadena[i] = malloc(sizeof(char)*size_palabra);
    if (cadena[i] == NULL) {
      for (size_t j = 0; j <= i; j++) {
        free(cadena[i]);
      }
      return NULL;
    }
  }
  return cadena;
}*/

size_t contador_caracteres(const char* cad, char c, size_t *n){
  size_t i;
  for (i = (*n)+1; cad[i] != c && cad[i] != '\0'; i++);
  *n = i;
  return i; //es la cantidad de caracteres necesarias para el malloc
}
