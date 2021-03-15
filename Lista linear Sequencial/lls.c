#include <stdio.h>

/** Fun��es de gerenciamento
*
* Implementar fun��es para:
*
* - Inicializar a estrutura
* - Retornar a quantidade de elementos v�lidos
* - Exibos os elementos da estrutura
* - Buscar por um elemento na estrutura
* - Inserir elementos na estrutura
*       - Inser��o no in�cio
*       - Inser��o no fim
*       - Inser��o ordenada pela chave
*       - Inser��o posi��o indicada (Implementa)
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
    REGISTER REGISTER[MAX];
    int elementsNumber;
}List;

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
        return i; // retorna posi��o do elemento
    }

    return -1; // la�o percorrido e nenhuma posi��o encontrada
}

/** Inserir elemento na lista pela posi��o indicada */
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

    // A posi��o precisa existir e a lista n�o estiver cheia
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


int main () {

    List list1;
    List *list = &list1;

    REGISTER reg1, reg2, reg3;
    reg1.key = 10;
    reg2.key = 4;
    reg3.key = 50;

    startList(list);

    insertElementAtBegin(list, reg1);
    insertElementAtBegin(list, reg2);
    //insertElementAtBegin(list, reg3);

    //removeElement(list, 10);

    showElements(list);
    //printf("%d\n", linearSearch(list, 4));

    printf("Numero de elementos: %d\n", listLenght(list));



    return 0;
}
