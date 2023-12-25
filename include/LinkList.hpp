#pragma once
#include <iostream>
using std::cout;
using std::endl;

template <class T>
class ListNode
{
public:
    T data;
    ListNode *next;
};
template <class T>
class LinkList
{
public:
    ListNode<T> *head;
    int size;
    LinkList()
    {
        head = new ListNode<T>;
        size = 0;
        head->next = NULL;
    }
    ~LinkList()
    {
        if (this->head != NULL)
        {
            Clear();
        }
    }
    void Insert(int position, T value)
    {
        ListNode<T> *newnode = new ListNode<T>;
        // check the paramater
        if (position > this->size || this->head == NULL)
        {
            position = this->size;
        }
        // assist pointer
        ListNode<T> *CurrentNode = this->head;
        for (int i = 0; i < position; i++)
        {
            CurrentNode = CurrentNode->next;
        }
        newnode->next = CurrentNode->next;
        CurrentNode->next = newnode;
        newnode->data = value;
        size++;
    }

    void Remove(int position)
    {
        if (this->head == NULL)
        {
            cout << "error!paramater invalid" << endl;
            return;
        }
        ListNode<T> *CurrenNode = this->head;
        for (int i = 0; i < position; i++)
        {
            CurrenNode = CurrenNode->next;
        }
        ListNode<T> *Pnext = CurrenNode->next;
        CurrenNode->next = Pnext->next;
        Pnext->next = NULL;
        delete Pnext;
        size--;
    }

    void Clear()
    {
        ListNode<T> *Current = this->head;
        while (Current != NULL)
        {
            ListNode<T> *del_cache = Current->next;
            delete Current;
            Current = del_cache;
        }
        this->head = NULL;
    }

    T SearchByIndex(int index)
    {
        ListNode<T> *CurrentNode = this->head;
        for (int i = 0; i <= index; i++)
        {
            CurrentNode = CurrentNode->next;
        }
        return CurrentNode->data;
    }

    void Print(void (*print)(T data))
    {
        if (this->head == NULL)
        {
            cout << "error!paramater invalid" << endl;
        }
        ListNode<T> *CurrentNode = this->head;
        while (CurrentNode->next != NULL)
        {
            print(CurrentNode->next->data);
            CurrentNode = CurrentNode->next;
        }
    }
};
// void myprint(int data)
// {
//     cout << data << " ";
// }
// void LinkListTest(void)
// {
//     LinkList<int> test;
//     for (int i = 0; i < 8; i++)
//     {
//         test.Insert(0, i);
//     }
//     test.Print(myprint);
// }