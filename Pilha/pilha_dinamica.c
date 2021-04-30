#include <stdio.h>
#include <malloc.h>

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

/* Função demonstrativa. Não existe em uma situação real. */
void showElements (STACK *stack) {
    ELEMENT *element = stack->top;

    while (element != NULL) {
        printf("%d ", element->key);
        element = element->next;
    }

    printf("\n");
}

void push (STACK *stack, int key) {

    /* Aloca memória para novo elemento */
    ELEMENT *elementToInsert = (ELEMENT*) malloc(sizeof(ELEMENT));
    elementToInsert->key = key;

    /* O antigo topo é o next */
    elementToInsert->next = stack->top;

    /* O novo elemento é o topo*/
    stack->top = elementToInsert;

}

int pop (STACK *stack) {

    if (stack->top != NULL) {
        ELEMENT *aux = stack->top;
        stack->top = stack->top->next;
        free(aux);

        return TRUE;
    }

    return FALSE;
}

/* Jamais retornar um ponteiro, isso pode comprometer toda a estrutura */
int topStack (STACK *stack) {
    return stack->top != NULL ? stack->top->key : INVALID;
}

void restartStack (STACK *stack) {
    ELEMENT *position = stack->top;

    while (position != NULL) {
        ELEMENT *remove = position;
        position = position->next;
        free(remove);
    }

    stack->top = NULL;

}

int main () {
    STACK stack;

    startStack(&stack);
    push(&stack, 5);
    push(&stack, 7);
    push(&stack, 10);
    pop(&stack);
    restartStack(&stack);

    int el = topStack(&stack);
    el = 11;
    printf("%d\n", el);

    //printf("%d\n", stackLenght(&stack));
    //printf("%d\n", topStack(&stack)->key);
    //printf("Vazio: %d\n", isEmpty(&stack));

    showElements(&stack);

}

