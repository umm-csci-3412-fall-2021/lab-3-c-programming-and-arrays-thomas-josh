#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
  // This is obviously broken. It has the right type, though, eh?
  int *bigArray;

      int i;
      int counter;

      for(i = 0; i < num_arrays; i++){
          counter = counter + sizes[i];
      }

  bigArray = (int*)malloc(counter, sizeof(int));

  for(int j = 0; j< num_arrays; j++){
      int size = sizes[j];
      for(int k = 0; k<size; k++){
          bigArray[k]= values[j][k];
      }
  }

  for(int h = 0; h < counter; h++){
      int compare = bigArray[h];
  }
  return sizes;
}
