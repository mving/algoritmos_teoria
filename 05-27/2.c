#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pers{
    char nombre[30];
    int edad;
    struct pers * sig;
}pers_t;

void ins_al_principio(pers_t ** l,char * nombre,int edad);
void ins_al_final(pers_t ** l, char * nombre, int edad);
void ins_al_final_recursivo(pers_t **l, char * nombre, int edad);
pers_t * crear_lista();
void eliminar_lista(pers_t ** l, char * nombre);

int main(int argc, char const *argv[]) {
    char input[30];
    pers_t * l = NULL;
    //l = malloc(sizeof(pers_t));
    l = crear_lista();
    ins_al_principio(&l,"jose",22);
    ins_al_final(&l,"hernan",25);
    ins_al_final_recursivo(&l,"horacio",33);
    pers_t * aux2 = l;
    while (aux2 != NULL) {
        printf("nombre: %s, edad: %d\n",aux2->nombre, aux2->edad);
        aux2 = aux2->sig;
    }
    fprintf(stdout, "ingrese nombre a borrar\n");
    fgets(input,30,stdin);
    input[strcspn(input, "\n")] ='\0';
    printf("\nborrando: %s\n",input);
    eliminar_lista(&l,input);
    //eliminar_lista(&l,"manuel");
    aux2 = l;
    while (aux2 != NULL) {
        printf("nombre: %s, edad: %d\n",aux2->nombre, aux2->edad);
        aux2 = aux2->sig;
    }
    return 0;
}

void ins_al_principio(pers_t ** l,char * nombre,int edad){
    pers_t * aux = malloc(sizeof(pers_t));
    strcpy(aux->nombre, nombre);
    aux->edad = edad;
    aux->sig = NULL;
    if ((*l) == NULL) {
        (*l) = aux;
    }else{
        aux->sig = (*l);
        (*l) = aux;
    }
}

void ins_al_final(pers_t ** l, char * nombre, int edad){
    pers_t * aux = malloc(sizeof(pers_t));
    pers_t * x = malloc(sizeof(pers_t));
    strcpy(aux->nombre, nombre);
    aux->edad = edad;
    aux->sig = NULL;
    if ((*l) == NULL) {
        (*l) = aux;
    }else{
        x = (*l);
        while (x->sig != NULL) {
            x = x->sig;
        }
        x->sig = aux;
    }
}

void ins_al_final_recursivo(pers_t **l, char * nombre, int edad){
    if ((*l) == NULL) {
        pers_t * aux;
        aux = malloc(sizeof(pers_t));
        strcpy(aux->nombre, nombre);
        aux->edad = edad;
        aux->sig = NULL;
        (*l) = aux;
    }else{
        ins_al_final_recursivo(&(*l)->sig, nombre, edad);
    }
}

pers_t * crear_lista(){
    pers_t * l = NULL;
    int n;
    int edad;
    char nombre[30];
    char input[10];
    fprintf(stdout, "ingrese cantidad\n");
    fgets(input,10,stdin);
    n = atoi(input);
    for (size_t i = 0; i < n; i++) {
        fprintf(stdout, "ingrese nombre\n");
        fgets(nombre,30,stdin);
        nombre[strcspn(nombre, "\n")] ='\0';
        fprintf(stdout, "ingrese edad\n");
        fgets(input,10,stdin);
        edad = atoi(input);
        ins_al_final_recursivo(&l, nombre, edad);
    }
    //system("clear");
    return l;
}

void eliminar_lista(pers_t ** l, char * nombre){
    if (*l){
        if (strcmp((*l)->nombre,nombre) == 0) {
            pers_t * aux = (*l);
            (*l) = (*l)->sig;
            free(aux);
        }else{
            fprintf(stderr, "else\n");
            eliminar_lista(&((*l)->sig), nombre);
        }
    }
}
