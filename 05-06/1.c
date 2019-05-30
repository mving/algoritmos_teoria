#include <stdio.h>
#include <strig.h>
typedef struct pers{
    char nombre[30];
    long dni;
    int edad;
}pers_t;

int buscar_nombre(pers_t v[], char* nombre){
    size_t i;
    for (i = 0; strcmp(v[i].nombre,"xx")&&strcmp(v[i].nombre,nombre); i++);
    if (strcmp(v[i].nombre,"xx") == 0) {
        return -1;
    }

}

int busqueda_binaria(pers_t v[], int elementos, char* nombre){
    int pivote = elementos / 2;
    while (pivote >= 0 && pivote < elementos) {
        if (strcmp(v[pivote]nombre,nombre) > 0) {
            pivote = pivote + (pivote/2);
        }else{
            if (strcmp(v[pivote]nombre,nombre) > 0) {
            pivote = pivote - (pivote/2);
        }else{
            return v[pivote].edad;
        }
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    pers_t vp[100];
    char nombre[30];
    int e;
    ingresar_datos_pers(vp);
    fgets(nombre,30,stdin);
    e = buscar_nombre(vp,nombre);
    return 0;
}
