#include <stdio.h>


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

int main () {
    List list1;
    List *list = &list1;
    REGISTER reg;
    reg.key = 10;

    //startList(list1);

    return 0;
}

