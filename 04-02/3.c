#include <stdio.h>

void eliminar_vocales(char *cad);

int main() {
//  char cad[] = "hola";
  char *vc[] = {"hola","lunes","nada"};
  for (int i = 0; i < 3; i++) {
    printf("%s\n",vc[i]);
  }
  for (size_t i = 0; i < 3; i++) {
    eliminar_vocales(vc[i]);
    printf("%s\n",vc[i]);
  }

  return 0;
}

void eliminar_vocales(char *cad){

  int j = 0;
  printf("hh\n");
  for (int i = 0; cad[i] != '\0' ; i++) {
    fprintf(stderr,"gg\n");
    if (cad[i] != 'a' && cad[i] != 'e' && cad[i] != 'i' && cad[i] != 'o' && cad[i] != 'u') {
      printf("%c\n",cad[3]);
      cad[j]= cad[i];
      fprintf(stderr,"gg\n");
      j++;
    }
  }
  fprintf(stderr,"gg\n");
  cad[j] = '\0';
}
