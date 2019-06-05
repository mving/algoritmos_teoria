#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valor;
    struct nodo *sig;
}nodo_t;

nodo_t * crear_lista();
void insertar_ordenado(nodo_t **l,int v);


int main(int argc, char const *argv[]) {
    nodo_t *l = NULL;
    l = crear_lista();
    insertar_ordenado(&l,8);
    nodo_t *aux2 = l;
    while (aux2 != NULL) {
        printf("valor: %d\n",aux2->valor);
        aux2 = aux2->sig;
    }
    free(l);
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
