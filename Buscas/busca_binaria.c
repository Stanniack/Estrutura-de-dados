#include <stdio.h>

/** ************************************ */
int binarySearch(int key, int begin, int end, int array[]);
int recursiveBinarySearch(int key, int begin, int end, int array[]);

int main () {

    int array[] = {1, 2, 3, 4, 5, 6, 7}, tam;
    tam = sizeof(array)/ sizeof(array[0]);

    int r = recursiveBinarySearch(7, 0, tam - 1, array);
    printf("%d\n", r);

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

int recursiveBinarySearch (int key, int begin, int end, int array[]) {

    int middle = (begin + end) / 2;

    if (end < begin)
        return -1;

    if (key > array[middle])
        recursiveBinarySearch(key, middle + 1, end, array);
    else
    if (key < array[middle])
        recursiveBinarySearch(key, begin, middle - 1, array);
    else
        return middle;
}

