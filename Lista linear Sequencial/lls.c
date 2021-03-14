#include <stdio.h>

/** Funções de gerenciamento
*
* Implementar funções para:
*
* - Inicializar a estrutura
* - Retornar a quantidade de elementos válidos
* - Exibos os elementos da estrutura
* - Buscar por um elemento na estrutura
* - Inserir elementos na estrutura
*       - Inserção no início
*       - Inserção no fim
*       - Inserção ordenada pela chave
*       - Inserção posição indicada (Implementação de agora)
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
    printf("t");

    for (i = 0; i < list->elementsNumber; i++) {
        printf("Total list's elements: %d\n", list->elementsNumber);
        printf("Element %d: %d: \n", i+1, list->REGISTER[i].key);
    }
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

/** Inserir elemento na lista */
int insertElement (List *list, REGISTER reg, int posToInsert) {

    // A posição precisa existir e a lista não estiver cheia
    if (list->elementsNumber != MAX && posToInsert >= 0 && posToInsert <= MAX) {

        int i;

        // regra de inserção
        for (i = list->elementsNumber; i > posToInsert; i--) {
            list->REGISTER[i] = list->REGISTER[i - 1];
        }

        list->REGISTER[i] = reg;

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


    for (i = elementPosition; i < list->elementsNumber - 1; i++) {
        list->REGISTER[i] = list->REGISTER[i + 1];
    }

    list->elementsNumber--;

    return 0;
}

void restartList (List *list) {
    list->elementsNumber = 0;
}


int main () {
    List list1;
    List *list = &list1;
    REGISTER reg;
    reg.key = 10;

    startList(list1);



    return 0;
}
