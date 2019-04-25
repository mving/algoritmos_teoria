const int *p = &a;
//puedo
p=&b;
//no puedo
p=15;

//////////////////////////

int * const p = &a;
//puedo
p=15;
//no puedp
p=&b
