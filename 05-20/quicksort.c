#include <stdio.h>

void quicksort(int v[], int inf, int sup);
void intercambiar(int *v,int *b);

int main(int argc, char const *argv[]) {
    int v[] = {1,8,5,9,4,63,41,52,74,95,45,36,0,12,35,6};
    int size = sizeof(v) / sizeof(int);
    quicksort(v,0,size);
    for (size_t i = 0; i < size; i++)
        fprintf(stdout, "%d\n", v[i]);
    return 0;
}

void quicksort(int v[], int inf, int sup) {
    int pivote = v[sup];
    int i = inf - 1, j = sup, cont = 1;
    if(!(inf >= sup))return;//{
        while (cont) {
            while(v[++i] < pivote);
            while(v[--j] > pivote);
            if (i < j)  intercambiar(&v[i],&v[j]);
            cont = 0;
        }
        intercambiar(&v[i],&v[sup]);
        quicksort(v,inf,j-1);
        quicksort(v,i+1,sup);
    //}
}

void intercambiar(int *v,int *b){
    int aux = *v;
    *v = *b;
    *b = aux;
}
