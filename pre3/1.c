#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    double * coeficiente;
    size_t grado_polinomio;
}polinomio_t;

void destruir_polinomio(polinomio_t * p);

polinomio_t *polinomio_crear(size_t n);

double polinomio_evaluar(const polinomio_t *p, double x);

polinomio_t *polinomio_derivar(const polinomio_t *p);

void imprimir_polinomio(polinomio_t *p);

int main(int argc, char const *argv[]) {
    polinomio_t * polinomio = polinomio_crear(3);
    polinomio->coeficiente[0] = 5;
    polinomio->coeficiente[1] = 2;
    polinomio->coeficiente[2] = -4;
    polinomio->coeficiente[3] = 9;
    fprintf(stdout, "%f\n",polinomio_evaluar(polinomio,2) );
    imprimir_polinomio(polinomio);
    polinomio = polinomio_derivar(polinomio);
    imprimir_polinomio(polinomio);
    return 0;
}

void destruir_polinomio(polinomio_t * p){
    free(p->coeficiente);
    free(p);
}

polinomio_t *polinomio_crear(size_t n){
    polinomio_t * polinomio = malloc(sizeof(polinomio_t));
    if (polinomio == NULL)
        return NULL;

    polinomio->coeficiente = calloc(n+1,sizeof(double));
    if (polinomio->coeficiente == NULL) {
        free(polinomio);
        return NULL;
    }
    polinomio->grado_polinomio = n;
    return polinomio;
}

double polinomio_evaluar(const polinomio_t *p, double x){
    double polinomio_evaluado = 0;
    for (size_t i = 0; i <= p->grado_polinomio; i++) {
        polinomio_evaluado += p->coeficiente[i] * pow(x,i);
    }
    return polinomio_evaluado;
}

polinomio_t *polinomio_derivar(const polinomio_t *p){
    polinomio_t * derivada = polinomio_crear(p->grado_polinomio - 1);
    for (size_t i = 0; i <= p->grado_polinomio - 1; i++) {
        derivada->coeficiente[i] = (p->coeficiente[i+1] * (i+1));
    }
    return derivada;
}

void imprimir_polinomio(polinomio_t *p){
    fprintf(stdout, "%.2f ",p->coeficiente[0]);
    for (size_t i = 1; i <= p->grado_polinomio; i++) {
        fprintf(stdout, "%+.2fX^%zd ",p->coeficiente[i],i);
    }
    fprintf(stdout, "\n");
    fprintf(stdout, "%f\n",p->coeficiente[3]);

}
