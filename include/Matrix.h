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
    // �����б�
    int i;
    // �����б�
    int j;
    // ����
    int data;
};
class TSMatrix
{
public:
    triple data[MAXNUMBER];
    int Row;  // ���������
    int Cols; // ���������
    int size; // ����Ԫ�صĸ���
    void Store(int row, int col, int data);
    TSMatrix(int row, int cols);
    void display();
};
void MatrixTest(void);
