#include<stdio.h>

int main()
{
    int teste = 10;
    //&teste => retorna um endereço de uma variável
    int *ponteiro_teste = &teste;
    
    printf("Endereço da variável teste: %p ", (void *)&teste);    
    
    return 0;
}
