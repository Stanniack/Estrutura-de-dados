#include <stdio.h>

int main () {

    int *x, valor = 25;

    x = &valor;

    printf("Valor que esta sendo apontado por X: %d\n", *x);
    printf("Valor da variavel valor: %d\n", valor);
    printf("Endereco apontado pelo X: %p\n", x);
    printf("Endereço da variavel valor: %p\n", &valor);

    return 0;
}
