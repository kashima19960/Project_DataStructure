#include "Matrix.h"
// 压缩对称矩阵
template <typename T>
bool SymmetricMatrixCondense(T (*matrix)[Demension])
{
    // 首先判断这个矩阵是不是对称矩阵
    int array[50] = {0};
    int count = 0;
    for (int i = 1; i < Demension; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }
    for (int i = 0; i < Demension; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            array[count++] = matrix[i][j];
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
    return true;
}
// 稀疏矩阵的三元组压缩法
TSMatrix::TSMatrix(int row, int cols)
{
    size = 0;
    this->Cols = cols;
    this->Row = row;
}
void TSMatrix::display()
{
    for (int i = 0; i < this->Row; i++)
    {
        for (int j = 0; j < this->Cols; j++)
        {
            int flag = 0;
            for (int k = 0; k < this->size; k++)
            {
                if (i == this->data[k].i && j == this->data[k].j)
                {
                    cout << this->data[k].data << " ";
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void TSMatrix::Store(int row, int col, int data)
{
    if (row > this->Row || col > this->Cols || data == 0)
    {
        cerr << "parameter make no sense!" << endl;
        exit(0);
    }
    this->data[size].i = row;
    this->data[size].j = col;
    this->data[size].data = data;
    size++;
}

// 测试函数
void MatrixTest(void)
{
    int a[3][4] = {
        {1, 2, 3, 4},
        {0, 0, 0, 0},
        {0, 1, 0, 3},
    };
    TSMatrix test(3, 4);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] != 0)
                test.Store(i, j, a[i][j]);
        }
    }
    test.display();
}