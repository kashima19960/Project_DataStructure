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
    // �����ж��Ƿ����˽���
    bool exchange = true;
    for (int i = 0; i < length && exchange != false; i++)
    {
        exchange = false;
        for (int j = 0; j < length - 1 - i; j++)
        {
            // if������û��ִ��,˵���ڱ���ɨ����û���κ�Ԫ�ط����˽�����Ҳ����˵���������Ѿ�����,û��Ҫ�ٽ�������ɨ����
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
        // �ȼٶ�i���ǵ�ǰ������С(��)Ԫ�ص��±�
        int min = i;
        // ��i����һ�����ң�����û�б�i��С(��)��Ԫ���±�
        for (int j = i; j < length; j++)
        {
            // ����ҵ��˾͸���min��ֵ
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        // ���min=i��˵��i����û�б�����С(��)��Ԫ�أ������Լ����Լ�������û�б�Ҫ�ģ�����Ҫ�����ж�
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
    // ���������˼���ǽ����������е�Ԫ��������뵽ǰ������������У�����Ԫ�ؿ��Կ���������ģ����i��1��ʼ
    for (int i = 1; i < length; i++)
    {
        T temp = array[i];
        j = i - 1;
        // ���temp��ǰ����������ж�ҪС����ô�����j=-1�������
        while (j >= 0 && temp < array[j])
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
        // ����ʵ���Ͼ���һ�ַ���Ĳ���
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

template <typename T>
void QuickSort(T array[], int start, int end)
{
    int left = start;
    int right = end;
    if (left >= right)
    {
        return;
    }
    while (left < right)
    {
        while (left < right && array[right] >= array[start])
        {
            right--;
        }
        while (left < right && array[left] <= array[start])
        {
            left++;
        }
        T temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }
    T temp = array[start];
    array[start] = array[left];
    array[left] = temp;
    QuickSort(array, start, left - 1);
    QuickSort(array, left + 1, end);
}

template <typename T>
void Merge(T array[], int start, int mid, int end)
{
    int left_start = start;
    int left_end = mid;
    int right_start = mid + 1;
    int right_end = end;
    int count = 0;
    T *temp = new T[end - start + 1];
    while (left_start <= left_end && right_start <= right_end)
    {
        if (array[left_start] < array[right_start])
        {
            temp[count++] = array[left_start++];
        }
        else
        {
            temp[count++] = array[right_start++];
        }
    }
    while (left_start <= left_end)
    {
        temp[count++] = array[left_start++];
    }
    while (right_start <= right_end)
    {
        temp[count++] = array[right_start++];
    }
    for (int i = 0; i < count; i++)
    {
        array[start + i] = temp[i];
    }
}

template <typename T>
void MergeSort(T array[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    MergeSort(array, start, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, start, mid, end);
}

void Sort_test(void)
{
    int test[MAXLEN];
    std::chrono::high_resolution_clock clock;
    srand((unsigned int)time((long long)0));
    int *temp = new int[100];
    for (int i = 0; i < MAXLEN; i++)
    {
        test[i] = rand() % 100000000 + 1;
    }
#if 0
    cout << "before sort:" << endl;
    PrintArray(test, MAXLEN);
    MergeSort(test, 0, MAXLEN - 1);
    cout << "after sort:" << endl;
    PrintArray(test, MAXLEN);
#else
    auto start1 = clock.now();
    QuickSort(test, 0, MAXLEN - 1);
    auto end1 = clock.now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
    cout << "���ѵ�ʱ��:" << duration1.count() << endl;
#endif
}