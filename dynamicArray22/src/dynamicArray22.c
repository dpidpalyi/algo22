#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *arr;
  int size;
  int capacity;
} DynamicArray22;

DynamicArray22 *NewDynamicArray22(int capacity) {
  if (capacity <= 0) {
    return NULL;
  }

  DynamicArray22 *da = malloc(sizeof(DynamicArray22));

  da->size = 0;
  da->capacity = capacity;
  da->arr = malloc(capacity * sizeof(int));

  return da;
}

int DestroyDynamicArray22(DynamicArray22 *da) {
  if (!da) {
    return 1;
  }

  free(da->arr);

  return 0;
}

int AllocAndCopy(DynamicArray22 *da) {
  if (!da) {
    return 1;
  }

  int newCapacity = da->capacity * 2;
  int *arr = malloc(newCapacity * sizeof(int));
  if (!arr) {
    return 1;
  }

  for (int i = 0; i < da->size; i++) {
    arr[i] = da->arr[i];
  }

  free(da->arr);
  da->arr = arr;
  da->capacity = newCapacity;

  return 0;
}

int Put(DynamicArray22 *da, int elem) {
  if (!da) {
    return 1;
  }
  if (da->size == da->capacity && AllocAndCopy(da)) {
    return 1;
  }
  da->arr[da->size] = elem;
  da->size++;

  return 0;
}

int PutAt(DynamicArray22 *da, int index, int elem) {
  if (!da || index > da->size) {
    return 1;
  }

  if (index == da->size) {
    return Put(da, elem);
  }

  if (da->size == da->capacity && AllocAndCopy(da)) {
    return 1;
  }

  for (int i = da->size + 1; i > index; i--) {
    da->arr[i] = da->arr[i - 1];
  }
  da->arr[index] = elem;
  da->size++;

  return 0;
}

int RemoveLast(DynamicArray22 *da) {
  if (!da || da->size == 0) {
    return 1;
  }

  da->size--;
  return 0;
}

int RemoveAt(DynamicArray22 *da, int index) {
  if (!da || index >= da->size) {
    return 1;
  }

  if (index == da->size - 1) {
    return RemoveLast(da);
  }

  for (int i = index; i < da->size - 1; i++) {
    da->arr[i] = da->arr[i + 1];
  }

  da->size--;
  return 0;
}

int ReplaceAt(DynamicArray22 *da, int index, int elem) {
  if (!da || index >= da->size) {
    return 1;
  }

  da->arr[index] = elem;
  return 0;
}

void PrintDynamicArray22(DynamicArray22 *da) {
  if (!da) {
    return;
  }

  for (int i = 0; i < da->size; i++) {
    printf("%d ", da->arr[i]);
  }
  printf("\nsize = %d, capacity = %d\n", da->size, da->capacity);
}

// int main() {
//	DynamicArray22 *da = NewDynamicArray22(2);
//	int err = Put(da, 10);
//	err = Put(da, 20);
//	err = PutAt(da, 1, 30);
//	PrintDynamicArray22(da);
//	(void)err;
//
//	RemoveLast(da);
//	PrintDynamicArray22(da);
//	RemoveLast(da);
//	PrintDynamicArray22(da);
//	RemoveLast(da);
//	PrintDynamicArray22(da);
//	err = Put(da, 10);
//	PrintDynamicArray22(da);
//
//	err = DestroyDynamicArray22(da);
//}
