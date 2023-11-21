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
    for (int i = 0; i < length; i++)
    {
        int min = i;
        for (int j = i; j < length; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            Swap(array[min], array[i]);
        }
    }
}
template <typename T>
void InsertSort(T array[], int length)
{
    int j = 0;
    for (int i = 1; i < length; i++)
    {
        T temp = array[i];
        j = i - 1;
        // 如果temp比前面的有序序列都要小，那么会出现j=-1这种情况
        while (temp < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}
template <typename T>
void ShellSort(T array[], int length)
{
    int step = length;
    while (step > 1)
    {
        // 步长实际上就是一种分组的策略
        step = step / 3 + 1;
        for (int i = 0; i < step; i++)
        {
            int k;
            for (int j = i + step; j < length; j += step)
            {
                T temp = array[j];
                k = j - step;
                while (k >= 0 && temp < array[k])
                {
                    array[k + step] = array[k];
                    k -= step;
                }
                array[k + step] = temp;
            }
        }
    }
}
void Sort_test(void)
{
    int test[MAXLEN];
    std::chrono::high_resolution_clock clock;
    srand((unsigned int)time((long long)0));
    for (int i = 0; i < MAXLEN; i++)
    {
        test[i] = rand() % 1000;
    }
    // cout << "before sort:" << endl;
    // PrintArray(test, MAXLEN);
    auto start1 = clock.now();
    InsertSort(test, MAXLEN);
    auto end1 = clock.now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
    cout << "花费的时间:" << duration1.count() << endl;
    // cout << "after sort:" << endl;
    // PrintArray(test, MAXLEN);
}