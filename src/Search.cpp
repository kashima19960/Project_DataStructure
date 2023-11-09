#include "Search.h"
// À≥–Ú≤È’“
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
void Search_Test(void)
{
    LinkList<int> test;
    for (int i = 0; i < 10; i++)
        test.Insert(0, i);

    cout << Link_Search<int>(&test, 11)->data;
}