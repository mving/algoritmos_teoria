#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "A1.h"

#define TM2 6
#define TM 6
#define MAX 100

void mergesort(int a[], int i, int j){
    int mid;
    if(i<j){
        mid = (i+j) / 2;
        mergesort(a,i,mid);             //left recursion
        mergesort(a,mid + 1, j);        //right recursion
        merge(a,i,mid-1,mid + 1,j);       //merging of two sorted sub-arrays
    }
}

void merge(int a[], int izq_bck,int mid,int mid_der, int der){
    int temp[MAX];
    size_t j;
    int izq = izq_bck, k = 0;
    while (izq <= mid && mid_der <= der){
        if (a[izq] < a[mid_der])
            temp[k++] = a[izq++];
        else
            temp[k++] = a[mid_der++];
    }
    while (izq <= mid)
        temp[k++] = a[izq++];

    while (mid_der <= der)
        temp[k++] = a[mid_der++];

    for (izq = izq_bck, j = 0; izq <= der; izq++, j++)
        a[izq] = temp[j];
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int vector2[TM2] = {2,4,8,1,3,7};
    merge(vector2,0,TM2 / 2 - 1,TM2 / 2,TM2 - 1);

    for (size_t i = 0; i < TM2; i++)
        printf("%zd)_%d\n",i+1,vector2[i]);

    int vector[TM];
    for (size_t i = 0; i < TM; i++) {
        vector[i] = rand() % TM;
    }
    mergesort(vector,0,TM - 1);
    for (size_t i = 0; i < TM; i++) {
        printf("%zd)_%d\n",i+1,vector[i]);
    }

    return 0;
}
