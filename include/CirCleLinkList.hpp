#ifndef CIRCLELINKLIST_H
#define CIRCLELINKLIST_H

#include "common.h"
template <class T>
class CirCleLinkList
{
public:
    ListNode<T> head;
    int size;
    CirCleLinkList()
    {
        this->head.next = NULL;
        this->size = 0;
    }
    void pushback(ListNode<T> *node)
    {
        ListNode<T> *Current = &(this->head);
        for (int i = 0; i < this->size; i++)
        {
            Current = Current->next;
        }
        Current->next = node;
        node->next = this->head.next;
        this->size++;
    }
    void popback()
    {
        if (this->size == 0)
        {
            cerr << "error! CirCleLinkList empty" << endl;
            return;
        }
        ListNode<T> *Current = &(this->head);
        for (int i = 0; i < this->size - 1; i++)
        {
            Current = Current->next;
        }
        ListNode<T> *del_cache = Current->next;
        Current->next = this->head.next;
        del_cache->next = NULL;
        this->size--;
    }
    void insert(ListNode<T> *node, int position)
    {
        ListNode<T> *Current;
        position = position % (this->size + 1);
        if (position == 0)
        {
            Current = &(this->head);
            for (int i = 0; i < this->size; i++)
            {
                Current = Current->next;
            }
            Current->next = this->head.next;
            node->next = this->head.next;
            this->head.next = node;
            Current = this->head.next;
        }
        else
        {
            Current = &(this->head);
            for (int i = 0; i < position; i++)
            {
                Current = Current->next;
            }
            node->next = Current->next;
            Current->next = node;
        }
        this->size++;
    }
    void RemoveByIndex(int position)
    {
        if (position > this->size)
        {
            // 这里保存的是下标，下标是几，Current就移动几次
            position = this->size - 1;
        }
        ListNode<T> *Current = &(this->head);
        if (position == 0)
        {
            for (int i = 0; i < this->size; i++)
            {
                Current = Current->next;
            }
            this->head.next = this->head.next->next;
            Current->next = this->head.next;
            this->size--;
        }
        else
        {
            for (int i = 0; i < position; i++)
            {
                Current = Current->next;
            }
            Current->next = Current->next->next;
            this->size--;
        }
    }
    void List_print()
    {
        ListNode<T> *Current = this->head.next;
        for (int i = 0; i < this->size; i++)
        {
            cout << Current->next << " ";
            Current = Current->next;
        }
        cout << endl;
    }
};
void CirCleLinkListTest(void);
#endif