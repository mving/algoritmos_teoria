struct pers{
  char nombre[20];
  int edad;
  long dni;
};

int main(int argc, char const *argv[]) {
  struct pers A;
  fgets(A.nombre,30,stdin);
  A.edad=leer_entero("ingrese edad");
  A.dni=leer_long("ingrese DNI");

  struct pers B = ("Ana",20,39487273),C;
  strcpy(C.nombre,A.nombre);
  C.edad = A.edad;
  C.dni = A.dni;
  //lo mismo que las 3 lineas anteriores juntas C=A;
  struct PERS vp[10];
  struct PERS * vpd = (struct pers *)malloc (sizeof(struct pers)*n);
  return 0;
}

/*
typedef struct PERS{
  char nom[30];
  int edad;
  ling dni;
}T_PERS;
int main(int argc, char const *argv[]) {
  T_PERS A;
  return 0;
}
*/
