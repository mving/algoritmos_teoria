#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pers{
    char nombre[30];
    int edad;
    int dni;
    struct pers * sig;
}pers_t;

void ins_al_principio(pers_t ** l,char * nombre,int edad, int dni);
void ins_al_final(pers_t ** l, char * nombre, int edad, int dni);
void ins_al_final_recursivo(pers_t **l, char * nombre, int edad, int dni);
pers_t * crear_lista();
void eliminar_lista(pers_t ** l, char * nombre);
void modificar_edad(pers_t *l, int dni, int edad);
void modificar_edad_ordenado(pers_t * l,int dni, int edad);

int main(int argc, char const *argv[]) {
    char input[30];
    pers_t * l = NULL;
    //l = malloc(sizeof(pers_t));
    l = crear_lista();
    ins_al_principio(&l,"jose",22,23452354);
    ins_al_final(&l,"hernan",25,23634642);
    ins_al_final_recursivo(&l,"horacio",33,35325625);
    pers_t * aux2 = l;
    while (aux2 != NULL) {
        printf("nombre: %s, edad: %d, dni: %d\n",aux2->nombre, aux2->edad, aux2->dni);
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
        printf("nombre: %s, edad: %d, dni: %d\n",aux2->nombre, aux2->edad, aux2->dni);
        aux2 = aux2->sig;
    }
    return 0;
}

void ins_al_principio(pers_t ** l,char * nombre,int edad, int dni){
    pers_t * aux = malloc(sizeof(pers_t));
    strcpy(aux->nombre, nombre);
    aux->edad = edad;
    aux->dni = dni;
    aux->sig = NULL;
    if ((*l) == NULL) {
        (*l) = aux;
    }else{
        aux->sig = (*l);
        (*l) = aux;
    }
}

void ins_al_final(pers_t ** l, char * nombre, int edad, int dni){
    pers_t * aux = malloc(sizeof(pers_t));
    pers_t * x = malloc(sizeof(pers_t));
    strcpy(aux->nombre, nombre);
    aux->edad = edad;
    aux->dni = dni;
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

void ins_al_final_recursivo(pers_t **l, char * nombre, int edad, int dni){
    if ((*l) == NULL) {
        pers_t * aux;
        aux = malloc(sizeof(pers_t));
        strcpy(aux->nombre, nombre);
        aux->edad = edad;
        aux->dni = dni;
        aux->sig = NULL;
        (*l) = aux;
    }else{
        ins_al_final_recursivo(&(*l)->sig, nombre, edad, dni);
    }
}

pers_t * crear_lista(){
    pers_t * l = NULL;
    int n;
    int edad;
    int dni;
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
        fprintf(stdout, "ingrese dni\n");
        fgets(input,10,stdin);
        dni = atoi(input);
        ins_al_final_recursivo(&l, nombre, edad, dni);
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

void modificar_edad(pers_t *l, int dni, int edad){
    if (l){
        if (l->dni == dni)
            l->edad = edad;
            else  modificar_edad(l->sig,dni,edad);
    }
}

void modificar_edad_ordenado(pers_t * l,int dni, int edad){
    if(l){
        if(l->dni == dni)
            l->edad = edad;
        else if(dni > l->dni)
            modificar_edad_ordenado(l->sig,dni,edad);
    }
}

//hacer modificar_edad que retorne bool
