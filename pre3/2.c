#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct{
    char nombre[MAX];
    unsigned int dni;
    float altura;
}persona_t;

bool leer_persona(FILE *f, persona_t *p);
void escribir_persona(FILE *f, const persona_t *p);
bool leer_personas(const char *r, persona_t v[], size_t max, size_t*n);
//como hacer un array de estructuras con memoria dinamica

int main(int argc, char const *argv[]) {
    FILE *f;

    persona_t persona[2] = {
        {"pedro",4064215,154},
        {"juan",2232342,84.4}
    };
    persona_t *persona2 = malloc(sizeof(persona_t));

    strcpy(persona2->nombre,"manuel");
    persona2->dni = 454545;
    persona2->altura = 197.5;

    persona_t *(personas[10]);
    for (size_t i = 0; i < 10; i++) {
        personas[i] = malloc(sizeof(persona_t));
    }
    char aux[MAX];
    for (size_t i = 0; i < 10; i++) {
        sprintf(aux,"nombre");
        strcpy(personas[i]->nombre,aux);
        personas[i]->dni = 454 * i;
        personas[i]->altura = 19.5 * i;
    }


    if((f =fopen(argv[1],"w")) == NULL){
        fprintf(stderr, "No se pudo abrir el archivo\n");
    }
    if (argc > 2)
        fprintf(stdout, "Solo se tiene en cuenta el primer archivo\n");

    if (argc < 2) {
        fprintf(stdout, "No ingreso el archivo\n");
        return EXIT_FAILURE;
    }

    escribir_persona(f,&persona[0]);
    escribir_persona(f,&persona[1]);
    escribir_persona(f,persona2);

    for (size_t i = 0; i < 10; i++) {
        escribir_persona(f,personas[i]);
    }
    free(persona2);

    fclose(f);
    return 0;
}


bool leer_persona(FILE *f, persona_t *p){

}

void escribir_persona(FILE *f, const persona_t *p){
    char output[MAX*2];
    sprintf(output,"%s;%d;%.2f\n",p->nombre,p->dni,p->altura);
    fputs(output,f);
}

bool leer_personas(const char *r, persona_t v[], size_t max, size_t*n){

}
