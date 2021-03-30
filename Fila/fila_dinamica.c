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
 *  Inserir elementos (No fim)
 *  Remover elementos (No início)
 * */

typedef struct aux {
    TYPEKEY key;
    struct aux* next;
} ELEMENT;

typedef struct {
    ELEMENT *begin;
    ELEMENT *end;
} QUEUE;


void startQueue (QUEUE *queue) {
    queue->begin = NULL;
    queue->end = NULL;

}

int queueLenght (QUEUE *queue) {
    ELEMENT *aux = queue->begin;
    int lenght = 0;

    while (aux != NULL) {
        aux = aux->next;
        lenght++;
    }

    return lenght;
}

void showElements (QUEUE *queue) {
    ELEMENT *aux = queue->begin;

    while (aux != NULL) {
        printf("%d ", aux->key);
        aux = aux->next;
    }

    printf("\n");
}

void insertElement (QUEUE *queue, int key) {

    ELEMENT *auxElement = (ELEMENT*) malloc(sizeof(ELEMENT));
    auxElement->key = key;

    /* Se for nulo, o início aponta p o primeiro elemento da fila adicionado, senão ele é o prox elemento do último */
    if (queue->begin == NULL)
        queue->begin = auxElement;
    else
        queue->end->next = auxElement;

    /* Torna o elemento inserido o último da fila */
    queue->end = auxElement;

    /* O próximo elemento do último é null */
    queue->end->next = NULL;

}

int removeElement (QUEUE *queue) {

    /* Se a fila estiver vazia */
    if (queue->begin == NULL)
        return FALSE;

    ELEMENT *remove = queue->begin;

    /* O início agora é o próximo */
    queue->begin = queue->begin->next;

    /* Se for o último elemento da fila, seta o ponteiro de fim para nulll */
    if (queue->begin == NULL)
        queue->end = NULL;

    free(remove);

    return TRUE;
}

int restartStack (QUEUE *queue) {
    ELEMENT *aux = queue->begin;

    while (aux->next != NULL) {
        ELEMENT *remove = aux->next;
        aux = aux->next;
        free(remove);
    }

    queue->begin = NULL;
    queue->end = NULL;

    return TRUE;
}

int main () {
    QUEUE queue;

    startQueue(&queue);
    insertElement(&queue, 10);
    insertElement(&queue, 5);
    insertElement(&queue, 17);

    removeElement(&queue);
    //removeElement(&queue);
    //removeElement(&queue);
    //removeElement(&queue);
    //restartStack(&queue);

    showElements(&queue);

    //printf("I: %d F: %d\n", queue.begin->key, queue.end->key);
    printf("%d\n", queueLenght(&queue));
}