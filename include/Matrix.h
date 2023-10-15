#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#define Demension 3
#define MAXNUMBER 50
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
class triple
{
public:
    // 矩阵行标
    int i;
    // 矩阵列标
    int j;
    // 数据
    int data;
};
class TSMatrix
{
public:
    triple data[MAXNUMBER];
    int Row;  // 矩阵的行数
    int Cols; // 矩阵的列数
    int size; // 非零元素的个数
    void Store(int row, int col, int data);
    TSMatrix(int row, int cols);
    void display();
};
void MatrixTest(void);
