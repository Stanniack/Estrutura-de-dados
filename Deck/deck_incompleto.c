#include <stdio.h>
#include <conio.h>
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
 *  Inserir elementos (No ínício e no fim)
 *  Remover elementos (Pop)
 * */

typedef struct {
    TYPEKEY key;
    struct aux* next;
    struct aux* previous;
} ELEMENT;

typedef struct {
    ELEMENT *headNode;
} DECK;

void startDeck (DECK *deck) {
    deck->headNode = (ELEMENT*) malloc(sizeof(ELEMENT));
    deck->headNode->next = deck->headNode;
    deck->headNode->previous = deck->headNode;
}

int deckLenght (DECK *deck) {
    ELEMENT *valid = deck->headNode->next;
    int lenght = 0;

    while (valid != deck->headNode){
        valid = deck->headNode->next;
        lenght++;
    }

    return lenght;
}

void showElementsBegin (DECK *deck) {
    ELEMENT *valid = deck->headNode->next;

    while (valid != deck->headNode){
        printf("%d ", valid->key);
        valid = deck->headNode->next;
    }
}

void showElementsEnd (DECK *deck) {
    ELEMENT *valid = deck->headNode->previous;

    while (valid != deck->headNode){
        printf("%d ", valid->key);
        valid = deck->headNode->previous;
    }
}

void insertElementEnd (DECK *deck, ELEMENT* element) {
    ELEMENT *aux = (ELEMENT*) malloc(sizeof(ELEMENT));
    aux = element;

    aux->next = deck->headNode;
    aux->previous = deck->headNode->previous;

    deck->headNode->previous = aux;

    // Não funciona:
    //deck->headNode->next->previous = aux; ou aux->previous->next

}

void insertElementBegin (DECK *deck, ELEMENT* element) {
}

int main () {
    DECK deck;
    ELEMENT element1, element2;
    element1.key = 5;
    element1.key = 7;

    startDeck(&deck);
    insertElementEnd(&deck, &element1);
    insertElementEnd(&deck, &element1);
    printf("%d\n", deckLenght(&deck));
}