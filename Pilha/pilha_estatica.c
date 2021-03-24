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
} ELEMENT;

typedef struct {
    ELEMENT ELEMENT[MAX];
    int top;
} STACK;

void startStack (STACK *stack) {
    stack->top = INVALID;
}

int stackLenght (STACK *stack) {
    return stack->top + 1;
}

void showElements (STACK *stack) {

    int elements = stack->top;

    while (elements >= 0) {
        printf("%d ", stack->ELEMENT[elements].key);
        elements--;
    }

    printf("\n");
}

int push (STACK *stack, ELEMENT elementToInsert) {

    if (stack->top < MAX - 1) {
        stack->top++;
        stack->ELEMENT[stack->top] = elementToInsert;

        return TRUE;
    }

    return FALSE;
}

int pop (STACK *stack) {

    if (stack->top != INVALID) {
        stack->top--;

        return TRUE;
    }

    return FALSE;
}

int topStack (STACK *stack) {
    return stack->top != INVALID ? stack->ELEMENT[stack->top].key : INVALID;
}

int main () {
    ELEMENT ELEMENT, ELEMENT2, ELEMENT3;
    ELEMENT.key = 5;
    ELEMENT2.key = 7;
    ELEMENT3.key = 2;
    STACK stack;
    STACK *pointerStack = &stack;

    startStack(pointerStack);
    push(pointerStack, ELEMENT);
    push(pointerStack, ELEMENT2);
    push(pointerStack, ELEMENT3);
    pop(pointerStack);
    showElements(pointerStack);
    printf("%d\n", topStack(pointerStack));
    printf("%d\n", stackLenght(pointerStack));
}

