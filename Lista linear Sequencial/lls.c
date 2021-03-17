#include <stdio.h>
#include <conio.h>

/** Funções de gerenciamento
*
* Implementar funções para:
*
* - Inicializar a estrutura
* - Retornar a quantidade de elementos v�lidos
* - Exibos os elementos da estrutura
* - Buscar por um elemento na estrutura
* - Inserir elementos na estrutura
*       - Inserção no início (Implementado)
*       - Inserção no fim (Implementado)
*       - Inserção ordenada pela chave
*       - Inserção posição indicada (ImplementadI)
* - Excluir elementos na estrutura
* - Reinicializar a estrutura
*/

/** Qtd elementos na lista */
#define MAX 50

/** O tipo primitivo da chave */
typedef int TYPEKEY;

/** Dados da lista */
typedef struct {
    TYPEKEY key;

}REGISTER;

typedef struct {
    // +1 para elemento sentinela
    REGISTER REGISTER[MAX + 1];
    int elementsNumber;
}List;

void mockList(List *list);

/** Inicia lista com 0 elementos */
void startList (List *list) {
    list->elementsNumber = 0;
}

/** Retorna a quantidade de elementos da lista */
int listLenght (List *list) {
    return list->elementsNumber;
}

/** Exibe os elementos da estrutura */
void showElements (List *list) {
    int i;

    for (i = 0; i < list->elementsNumber; i++)
        printf("Element %d: %d \n", i, list->REGISTER[i].key);

}

/** Buscar por um elemento na lista */
int linearSearch (List *list, TYPEKEY keyToSearch) {
    int i;

    for (i = 0; i < list->elementsNumber; i++) {
        if (keyToSearch == list->REGISTER[i].key)
            return i; // retorna posição do elemento
    }

    return -1; // laço percorrido e nenhuma posição encontrada
}

/** Busca otimizada com elemento sentinela - Reduz as comparações */
int sentinelSearch (List *list, TYPEKEY keyToSearch) {
    int i = 0;

    // elemento sentinela
    list->REGISTER[list->elementsNumber].key = keyToSearch;

    /* Se o elemento existir, o laço acaba.*/
    while (keyToSearch != list->REGISTER[i].key)
        i++;

    if (list->elementsNumber == i)
        return -1;

    return i;

}

/** Inserir elemento na lista pela posição indicada */
int insertElementPos (List *list, REGISTER reg, int posToInsert) {

    // A posi��o precisa existir e a lista n�o estiver cheia
    if (list->elementsNumber != MAX && posToInsert >= 0 && posToInsert <= MAX) {

        int i;

        // regra de inser��o (resposiciona os outros elementos)
        for (i = list->elementsNumber; i > posToInsert; i--)
            list->REGISTER[i] = list->REGISTER[i - 1];

        list->REGISTER[posToInsert] = reg;

        // Aumenta um elemento na lista
        list->elementsNumber++;

        return 0;

    }

    return 1;

}

int insertElementAtBegin (List *list, REGISTER reg) {
    int i;

    // A lista n�o estiver cheia
    if (list->elementsNumber != MAX) {
        for (i = list->elementsNumber; i > 0; i--)
            list->REGISTER[i] = list->REGISTER[i - 1];

        list->REGISTER[0] = reg;

        // Aumenta um elemento na lista
        list->elementsNumber++;

        return 0;
    }

    return 1;
}

int insertElementAtEnd (List *list, REGISTER reg) {
    int i;

    // A lista não estiver cheia
    if (list->elementsNumber != MAX) {
        list->REGISTER[list->elementsNumber] = reg;

        // Aumenta um elemento na lista
        list->elementsNumber++;

        return 0;
    }

    return 1;
}


/** Remover elemento */
int removeElement (List *list, TYPEKEY keyToRemove) {

    int i, elementPosition;
    elementPosition = linearSearch(list, keyToRemove);

    // se o elemento n existir na lista, retorna falso
    if (elementPosition == -1)
        return 1;

    // reposiciona elementos
    for (i = elementPosition; i < list->elementsNumber - 1; i++)
        list->REGISTER[i] = list->REGISTER[i + 1];

    list->elementsNumber--;

    return 0;
}

void restartList (List *list) {
    list->elementsNumber = 0;
}

/** ***************************************************************************************************************************************** */

int main () {

    List list1;
    List *list = &list1;

    REGISTER reg1, reg2, reg3;
    reg1.key = 10;
    reg2.key = 4;
    reg3.key = 50;

    startList(list);

    //insertElementPos(list, reg1, 0);
    //insertElementAtEnd(list, reg2);
    //insertElementAtEnd(list, reg3);
    mockList(list);

    //removeElement(list, 3);

    showElements(list);
    printf("%d\n", sentinelSearch(list, 1));

    printf("Numero de elementos: %d\n", listLenght(list));



    return 0;
}

void mockList (List *list) {
    int i;

    for (i = 0; i < MAX; i++) {
        //printf("teste\n");
        REGISTER reg;
        reg.key = i;
        insertElementAtBegin(list, reg);
    }
}


