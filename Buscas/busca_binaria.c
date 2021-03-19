#include <stdio.h>

/** ************************************ */

int main () {

    int array[] = {1, 2, 3}, tam;
    tam = sizeof(array)/ sizeof(array[0]);

    //int r = recursiveBinarySearch(2, 0, tam - 1, array);
    //printf("%d\n", r);

    return 0;
}

int binarySearch (int key, int begin, int end, int array[]) {
    int middle;

    while (end >= begin) {

        middle = (begin + end) / 2;

        if (key > array[middle])
            begin = middle + 1;
        else
            if (key < array[middle])
                end = middle - 1;
            else
                return middle;

    }

    return -1;
}


