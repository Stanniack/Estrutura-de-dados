#include <stdio.h>

int main () {

    int **x, *y ,valor = 25;

    y = &valor;
    x = &y;

    printf("Endereco apontado por x: %p\n", x);
    printf("Endereco apontado por y: %p\n", y);
    printf("Endereco de valor: %p\n", &valor);

    printf("Valor de x: %d\n", **x);
    printf("Valor de y: %d\n", *y);
    printf("Valor de valor: %d\n", valor);

    return 0;
}
