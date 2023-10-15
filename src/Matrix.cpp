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
void MatrixTest(void)
{
    int test[3][3] = {
        {1, 2, 3},
        {2, 1, 4},
        {3, 4, 1}};
    SymmetricMatrixCondense<int>(test);
}