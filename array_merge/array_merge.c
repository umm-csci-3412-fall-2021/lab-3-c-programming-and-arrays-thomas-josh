#include "array_merge.h"
#include "../mergesort/mergesort.c"
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*Sees if a number is already in the array*/
int inArray(int* array, int number, int size){
    int result = 0;
    for(int i = 0; i < size; i++){
        if(array[i] == number){
            result = 1;
            break;
        }
    }
    return result;
}

/*Puts all the elements of an array of arrays into a single specified array */
void intoOneArray(int* bigArray, int** values, int num_arrays, int* sizes){
  int r = 0;
  for(int j = 0; j< num_arrays; j++){
      int size = sizes[j];
      for(int k = 0; k<size; k++){
          bigArray[r]= values[j][k];
          r++;
      }
  }

}

int* array_merge(int num_arrays, int* sizes, int** values) {
  int* bigArray;
  int* littleArray;
  int* finalArray;
  int counter2 = 0;
  int i;
  int counter = 0;

/*Counts the total number of elements in the array of arrays */
  for(i = 0; i < num_arrays; i++){
    counter = counter + sizes[i];
  }

  bigArray = (int*)calloc(counter, sizeof(int));
  littleArray = (int*)calloc(counter, sizeof(int));

  intoOneArray(bigArray, values, num_arrays, sizes);

/*Adds all non duplicate elements from one array into another */
  for(int h = 0; h < counter; h++){
      if(inArray(littleArray, bigArray[h], counter2) == 0){
          littleArray[counter2] = bigArray[h];
          counter2++;
      }
  }

  mergesort(counter2, littleArray);

  finalArray = (int*)calloc(counter2+1, sizeof(int));
  finalArray[0] = counter2;

/*Puts the now sorted elements into the final array */
  for(int x = 1; x < counter2+1; x++){
      finalArray[x] = littleArray[x-1];
  }

  free(bigArray);
  free(littleArray);

  return finalArray;
}
