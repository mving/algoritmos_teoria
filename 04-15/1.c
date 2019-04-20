clasificacion de variables

x tipo de dato    *int
                  *float
                  *char
                  *etc

x almacenamiento  *automaticas
                  *estaticas
                  *registro
                  *externas

x ambito          *globales
                  *locales

ejemplo archivo
extern int suma();
extern int p;

static int b;
//cuando esta dentro de una funcion si guardo un valor en b, si salgo de la funcion se va a mantener el valor
//tambien sirve para funciones

pasaje de parametros:

                      x valor
                      x referencia
