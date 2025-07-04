#include <stdio.h>

typedef struct
{
    float numerador;
    float denominador;
} Fracao;

float calcula(const Fracao frac);
float calculaRef(const Fracao *frac);

float calcula(const Fracao frac)
{
    //frac.numerador = 0;
    return frac.numerador / frac.denominador;
}

float calculaRef(const Fracao *frac)
{
    //frac->denominador = 0;
    //return (*frac).numerador/(*frac).denominador;;
    return frac->numerador / frac->denominador;
}

int main()
{
    Fracao f1;
    f1.numerador = 10;
    f1.denominador = 2;
    printf("Valor da f1: %f\n", calcula(f1));
    printf("Valor (por ref.) da f1: %f\n",
           calculaRef(&f1));

    Fracao f2 = {18, 3};
    printf("Valor (por ref.) da f2: %f\n",
           calculaRef(&f2));
}