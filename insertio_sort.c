#include <stdio.h>
#include <stdlib.h>


void insertion_sort(int *p, int tamanho) {
      int i, j, tmp;
      for (i = 1; i < tamanho; i++) {
            j = i;
            while (j > 0 && p[j - 1] > p[j]) {
                  tmp = p[j];
                  p[j] = p[j - 1];
                  p[j - 1] = tmp;
                  j--;
            }
      }
}
/*
void insertionSortD(int array[], int tamanho) {
      int i, j, tmp;
      for (i = 1; i < tamanho; i++) {
            j = i;
            while (j > 0 && array[j - 1] < array[j]) {
                  tmp = array[j];
                  array[j] = array[j - 1];
                  array[j - 1] = tmp;
                  j--;
            }
      }
}
*/