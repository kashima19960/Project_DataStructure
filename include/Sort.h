#pragma once
#include <cstdio>
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
#define MAXLEN 10000
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
void Sort_test(void);
