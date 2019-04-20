#include <stdio.h>
#include <stdlib.h>

size_t mi_strlen(const char *leng){
  size_t i;
  for (i = 0; leng[i] != '\0'; i++) {
  }
  return i;
}

void mi_strcpy(char *dest, const char *orig){
  for (size_t i = 0; orig[i] != '\0'; i++) {
    dest[i] = orig[i];
  }
}

int mi_strcmp(const char *s2, const char *s1){
  size_t i;
  for (i = 0; s1[i] == s2[i] && s1[i]!='\0'&&s2[i]!='\0'; i++) {
    //if (s1[i]-s2[i]!=0)
      //return s1[i]-s2[i];
  }

  //if (s1[i]=='\0'&&s2[i]=='\0') {
    //return 0;
  //}
  return s1[i]-s2[i];
}
//si es negativo s2 es mayor

int main() {
    char primero[50]="mundo cruel";
    char segundo[50]="chau";
    //mi_strcpy(segundo,primero);
    printf("%d\n",mi_strcmp(primero,segundo));
  return 0;
}
