#ifndef STACK_H
#define STACK_H
#include "common.h"
#define CAPACITY 1024
enum Stack_sta
{
    Stack_False = 0,
    Stack_True
};
template <class T>
class Sec_Stack
{
private:
    T data[CAPACITY];
    int size;

public:
    Sec_Stack()
    {
        for (int i = 0; i < CAPACITY; i++)
        {
            this->data[i] = 0;
        }
        this->size = 0;
    }
    void Pop_Stack()
    {
        if (IsEmpty() == Stack_True)
        {
            cerr << "栈为空，不可在弹出元素" << endl;
            return;
        }
        this->size--;
    }
    void Push_Stack(T data)
    {
        if (this->size == CAPACITY)
        {
            cerr << "栈已满，不可在添加元素" << endl;
            return;
        }
        this->data[this->size++] = data;
    }

    Stack_sta IsEmpty()
    {
        if (this->size == 0)
        {
            return Stack_True;
        }
        else
        {
            return Stack_False;
        }
    }
    T Get_Top()
    {
        if (IsEmpty() == Stack_True)
        {
            return -1;
        }
        return this->data[this->size - 1];
    }
    void clear()
    {
        if (IsEmpty() == Stack_True)
        {
            return;
        }
        this->size = 0;
    }
    int Get_Size()
    {
        return this->size;
    }
    void print()
    {
        int max = this->size;
        cout << "[";
        for (int i = 0; i < max; i++)
        {
            cout << this->data[i];
            if (i != max - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
};

template <class T>
class Link_Stack
{
public:
    ListNode<T> head;
    int size;

    Link_Stack()
    {
        head.data = 0;
        head.next = NULL;
        size = 0;
    }
    ~Link_Stack()
    {
        if (head.next != NULL)
        {
            clear();
        }
    }
    int Get_Size()
    {
        return size;
    }
    void Pop_Stack()
    {
        if (IsEmpty() == Stack_True)
        {
            return;
        }
        else
        {
            ListNode<T> *del_cache = head.next;
            head.next = del_cache->next;
            delete del_cache;
            size--;
        }
    }
    void Push_Stack(T data)
    {
        ListNode<T> *newnode = new ListNode<T>;
        newnode->data = data;
        newnode->next = head.next;
        head.next = newnode;
        size++;
    }
    Stack_sta IsEmpty()
    {
        if (this->size == 0)
        {
            return Stack_True;
        }
        else
        {
            return Stack_False;
        }
    }
    T Get_Top()
    {
        if (IsEmpty() == Stack_True)
        {
            return NULL;
        }
        else
        {
            return head.next->data;
        }
    }
    void clear()
    {
        if (head.next == NULL)
        {
            return;
        }
        for (int i = 0; i < size; i++)
        {
            Pop_Stack();
        }
    }
    void print()
    {
        int max = this->size;
        ListNode<T> *Current = this->head.next;
        cout << "[";
        for (int i = 0; i < max; i++)
        {
            cout << Current->data;
            Current = Current->next;
            if (i != max - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
};
void PrintError(char *str, int pos);
Stack_sta ParenthesisMatching(char str[]);
void StackTest(void);
#endif