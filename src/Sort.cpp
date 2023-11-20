#include "Sort.h"
template <typename T>
void Swap(T &value1, T &value2)
{
    T temp = value1;
    value1 = value2;
    value2 = temp;
}
template <typename T>
void PrintArray(T array[], int length)
{
    int limit = 1;
    for (int i = 0; i < length; i++, limit++)
    {
        cout << array[i] << " ";
        if (limit % 12 == 0)
        {
            limit = 0;
            cout << endl;
        }
    }
    cout << endl;
}
template <typename T>
void BubbleSort(T array[], int length)
{
    bool exchange = true;
    for (int i = 0; i < length && exchange != false; i++)
    {
        exchange = false;
        for (int j = 0; j < length - 1 - i; j++)
        {
            // if语句如果没有执行,说明在本轮扫描中没有任何元素发生了交换，也就是说整个序列已经有序,没必要再接着往下扫描了
            if (array[j] > array[j + 1])
            {
                Swap<T>(array[j], array[j + 1]);
                exchange = true;
            }
        }
    }
}
template <typename T>
void SelectSort(T array[], int length)
{
}
void Sort_test(void)
{
    int test[MAXLEN];
    srand((unsigned int)time((long long)0));
    for (int i = 0; i < MAXLEN; i++)
    {
        test[i] = rand() % 100;
    }
    cout << "before sort:" << endl;
    PrintArray(test, MAXLEN);
    BubbleSort(test, MAXLEN);
    cout << "after sort:" << endl;
    PrintArray(test, MAXLEN);
}