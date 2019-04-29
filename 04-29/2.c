#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[]) {
  FILE *pf;
  char cadena[80];
  char s[80];
  int i=0;
  if ((pf=fopen("texto","w"))==NULL) {
    printf("Error\n");
  }
  return 0;
}
