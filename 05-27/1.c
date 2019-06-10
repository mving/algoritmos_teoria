#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "A1.h"

#define TM 10

void mergesort(int a[], int i, int j){
    int mid;
    if(i<j){
        mid = (i+j) / 2;
        mergesort(a,i,mid);             //left recursion
        mergesort(a,mid + 1, j);        //right recursion
        merge(a,i,mid,mid + 1,j);       //merging of two sorted sub-arrays
    }
}

void merge(int a[], int i_1,int j_1,int i_2, int j_2){
    int temp[TM];
    int i,j,k;
    i = i_1;
    j = i_2;
    k = 0;
    while (i <= j_1 && j<= j_2) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    while (i <= j_1) {
        temp[k++] = a[i++];
    }
    while (j <= j_2) {
        temp[k++] = a[j++];
    }
    for (i = i_1, j = 0; i <= j_2; i++, j++) {
        a[i] = temp[j];
    }
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));
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
