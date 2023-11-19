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
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                Swap<T>(array[j], array[j + 1]);
            }
        }
    }
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