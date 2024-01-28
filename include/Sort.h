#ifndef SORT_H
#define SORT_H
#include "common.h"
#define MAXLEN 50000
// 交换函数
template <typename T>
void Swap(T &value1, T &value2);

// 打印数组
template <typename T>
void PrintArray(T array[], int length);

// 冒泡排序
template <typename T>
void BubbleSort(T array[], int length);

// 选择排序
template <typename T>
void SelectSort(T array[], int length);

// 插入排序
template <typename T>
void InsertSort(T array[], int length);
// 希尔排序
template <typename T>
void ShellSort(T array[], int length);
// 快速排序
template <typename T>
void QuickSort(T array[], int start, int end);
// 归并排序
template <typename T>
void MergeSort(T array[], int start, int end);
template <typename T>
void Merge(T array[], int start, int mid, int end);
void Sort_test(void);
#endif