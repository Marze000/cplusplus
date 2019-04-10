#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
// 要求：用户可以控制创建大堆还是小堆

typedef int DataType;

typedef struct Heap
{
	DataType* _array;
	int _capacity;
	int _size;
}Heap;

void CreatHeap(Heap* hp, int* array, int size);
void InsertHeap(Heap* hp, DataType data);
void EraseHeap(Heap* hp);
int SizeHeap(Heap* hp);
int EmptyHeap(Heap* hp);
DataType TopHeap(Heap* hp);
void DestroyHeap(Heap* hp);

