#include "Search.h"
// ˳�����
template <typename T>
int Sec_Search(T arr[], int n, T value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}
template <typename T>
ListNode<T> *Link_Search(LinkList<T> *list, T value)
{
    ListNode<T> *Current = list->head;
    while (Current != NULL)
    {
        if (Current->data == value)
        {
            return Current;
        }
        Current = Current->next;
    }
    return NULL;
}

/*
���ֲ�������ֻ��ʹ��˳��洢�ṹ,���Ҽٶ����ҵ������������
*/

int Binary_Search(int arr[], int n, int value)
{
    int low = 0, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] > value)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

void Search_Test(void)
{
    int test[4] = {1, 3, 5, 7};
    cout << Binary_Search(test, 4, 5);
}