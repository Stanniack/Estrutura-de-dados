#include <stdio.h>
#include <conio.h>

#define MAX 50
#define INVALID -1
#define TRUE 0
#define FALSE 1
#define DEBUG
#undef DEBUG
typedef int TYPEKEY;

/** Funções de gerenciamento
 *  Inicializar
 *  Retornar a quantidade de elementos válidos
 *  Exibir os elementos
 *  Inserir elementos (Push)
 *  Remover elementos (Pop)
 * */

typedef struct {
    TYPEKEY key;
    struct aux* next;
} ELEMENT;

typedef struct {
    ELEMENT *top;
} STACK;

void startStack (STACK *stack) {
    stack->top = NULL;
}

int stackLenght (STACK *stack) {
    ELEMENT *element = stack->top;
    int lenght = 0;

    while (element != NULL) {
        element = element->next;
        lenght++;
    }

    return lenght;
}

int isEmpty (STACK *stack) {
    return stack->top == NULL ? TRUE : FALSE;
}

void showElements (STACK *stack) {
    ELEMENT *element = stack->top;

    while (element != NULL) {
        printf("%d ", element->key);
        element = element->next;
    }

    printf("\n");
}

push (STACK *stack, ELEMENT *elementToInsert) {

    /* Guarda o antigo topo */
    ELEMENT *aux = stack->top;
    /* O novo elemento é o topo*/
    stack->top = elementToInsert;
    /* O antigo topo é o next */
    elementToInsert->next = aux;

}

ELEMENT* pop (STACK *stack) {

    if (stack->top != NULL) {
        ELEMENT *aux = stack->top;
        stack->top = stack->top->next;

        return aux;
    }

    return NULL;
}

ELEMENT* topStack (STACK *stack) {
    return stack->top != NULL ? stack->top : NULL;
}

int main () {
    ELEMENT ELEMENT, ELEMENT2, ELEMENT3;
    STACK stack;

    ELEMENT.key = 5;
    ELEMENT2.key = 7;
    ELEMENT3.key = 2;

    startStack(&stack);
    push(&stack, &ELEMENT);
    push(&stack, &ELEMENT2);
    push(&stack, &ELEMENT3);
    pop(&stack);

    printf("%d\n", stackLenght(&stack));
    printf("%d\n", topStack(&stack));

    showElements(&stack);

}

