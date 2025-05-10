#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *arr;
  int size;
  int capacity;
} DynamicArray22;

DynamicArray22 *NewDynamicArray22(int capacity);
int DestroyDynamicArray22(DynamicArray22 *da);
int AllocAndCopy(DynamicArray22 *da);
int Put(DynamicArray22 *da, int elem);
int PutAt(DynamicArray22 *da, size_t index, int elem);
int RemoveLast(DynamicArray22 *da);
int RemoveAt(DynamicArray22 *da, int index);
int ReplaceAt(DynamicArray22 *da, int index, int elem);
void PrintDynamicArray22(DynamicArray22 *da);

#endif
