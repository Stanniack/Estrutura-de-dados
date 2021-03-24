#include <stdio.h>
#include <conio.h>

#define MAX 50
#define INVALID -1
#define DEBUG
#undef DEBUG
typedef int TYPEKEY;

typedef struct {
    TYPEKEY key;
    /* Outros dados */
} DATE;

typedef struct {
    DATE DATE;
    int next;
} ELEMENT;

typedef struct {
  ELEMENT ELEMENT[MAX];
  int begin;
  int availableIndex;
} LIST;

int listLenght(LIST *list);

void startList (LIST *list) {
    int i;

    /* Todos os index de elementos estão disponíveis */
    for (i = 0; i < MAX - 1; i++) {
        list->ELEMENT[i].next = i + 1;
    }

    /* Último elemento não tem index disponível */
    list->ELEMENT[MAX - 1].next = INVALID;

    /* Não há nenhum elemento válido ao inicializar*/
    list->begin = INVALID;

    /* O elemento imediamente disponível é o de index 0 pois a estrutura foi inicializada agora */
    list->availableIndex = 0;
}

void insertElement (LIST *list, ELEMENT elementToInsert) {

    if (list->begin != INVALID && listLenght(list) != MAX) {

        /* Insere elemento */
        list->ELEMENT[list->availableIndex] = elementToInsert;

        /* Atualiza index */
        list->availableIndex++;



    } else {
        /* Insere elemento no primeiro index disponivel */
        list->ELEMENT[list->availableIndex] = elementToInsert;

        /* Atualiza next disponível, como só tem um elemento então não aponta pra ninguém */
        list->ELEMENT[list->availableIndex].next = INVALID;

        list->begin = 0;

        /* O primeiro index agora está sendo usado*/
        list->availableIndex++;
    }
}

int listLenght (LIST *list) {
    int i = list->begin, lenght = 0;

    while (i != INVALID) {

        /* Percorre todos os elementos válidos da lista */
        i = list->ELEMENT[i].next;
        lenght++;
    }

    return lenght;
}

void showElements (LIST *list) {
    int i = list->begin, index = 0;

    while (i != INVALID){
        printf("%d ", list->ELEMENT[index].DATE.key);
        i = list->ELEMENT[i].next;
    }
}

int linearSearch (LIST *list, int keyToSearch) {
    int i = list->begin;

    /* Se for invalido e elemento da lista for menor que o procurado (lista ordenada), saia do laço */
    while (i != INVALID && list->ELEMENT[i].DATE.key < keyToSearch)
        i = list->ELEMENT[i].next;

    /*  O elemento existe na lista e foi encontrado */
    if (i != INVALID && list->ELEMENT[i].DATE.key == keyToSearch) {
        return i;
    }

    return INVALID;
}



int main () {
    LIST list;
    LIST *pointerList = &list;

    startList(pointerList);
    int r = listLenght(pointerList);
    printf("%d\n", r);

}

