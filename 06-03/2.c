#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valor;
    struct nodo *sig;
}nodo_t;

nodo_t * crear_lista();
void insertar_ordenado(nodo_t **l,int v);
void llenar(nodo_t *v[]);
void llenar_vector(nodo_t *v[]);
void imprimir_lista(nodo_t * l);
void enganchar(nodo_t *vpl[]);
void desenganchar(nodo_t *vpl[]);

int main(int argc, char const *argv[]) {
    nodo_t *vpl[100];
    llenar_vector(vpl);

    return 0;
}

nodo_t * crear_lista(){
    nodo_t * l = NULL;
    int n;
    int dato;
    char input[10];
    fprintf(stdout, "ingrese cantidad\n");
    fgets(input,10,stdin);
    n = atoi(input);
    for (size_t i = 0; i < n; i++) {
        fprintf(stdout, "ingrese un valor de la lista\n");
        fgets(input,30,stdin);
        dato = atoi(input);
        insertar_ordenado(&l, dato);
    }
    //system("clear");
    return l;
}


void insertar_ordenado(nodo_t **l,int v){
    if (!(*l)) {
        *l = malloc(sizeof(nodo_t));
        (*l)->valor = v;
        (*l)->sig = NULL;
    }else if(v < (*l)->valor){
        nodo_t * aux = malloc(sizeof(nodo_t));
        aux->valor = v;
        aux->sig = (*l);
        (*l) = aux;
    }else insertar_ordenado(&(*l)->sig,v);
}

void llenar_vector(nodo_t *v[]){
    char input[100];
    fgets(input,100,stdin);
    int cant = atoi(input);
    for (size_t i = 0; i < cant; i++)
        v[i] = crear_lista();
    v[cant] = NULL;
}
void imprimir_lista(nodo_t * l){
    while(l){
        fprintf(stdout, "valor: %d\n",l->valor);
        l = l->sig;
    }
}

void enganchar(nodo_t *vpl[]){
    nodo_t * aux;
    for (size_t i = 0; vpl[i+1] != NULL; i++) {
        aux = vpl[i];
        while (aux->sig != NULL)
            aux = aux->sig;

        aux->sig = vpl[i+1];
    }
}

void desenganchar(nodo_t *vpl[]){
    nodo_t * aux;
    size_t i = 1;
    aux = vpl[0];
    while (vpl[i] != NULL){
        if (aux->sig == vpl[i]){
            aux->sig = NULL;
            aux = vpl[i];
            i++;
        }
        aux = aux->sig;
    }
}
