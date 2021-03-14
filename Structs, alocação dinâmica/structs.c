#include <stdio.h>
#include <malloc.h>

typedef struct {
    int valor;
} StructTeste;

int main () {
    StructTeste *t = (StructTeste*) malloc(sizeof(StructTeste));

    t->valor = 10;


    printf("%d\n", t->valor);


    return 0;
}
