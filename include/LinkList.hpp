#ifndef LINKLIST__HPP
#define LINKLIST__HPP
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
    ListNode<T> *tail;
    int size;
    LinkList()
    {
        head = tail = NULL;
        size = 0;
    }
    ~LinkList()
    {
        if (this->head != NULL)
        {
            Clear();
        }
    }
    void Pushback(T data)
    {
        ListNode<T> *node = new ListNode<T>;
        node->data = data;
        node->next = NULL;
        if (head == NULL)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        this->size++;
    }
    void Insert(int position, T data)
    {
        // 插入位置不合理就强制进行尾部插入
        if (position > this->size || position < 0)
        {
            this->Pushback(data);
            return;
        }
        ListNode<T> *node = new ListNode<T>;
        node->data = data;
        // 头部插入不需要遍历链表，直接利用头指针即可
        if (position == 0)
        {
            node->next = this->head;
            this->head = node;
        }
        // 尾部插入也不需要遍历链表，直接利用尾指针
        else if (position == size - 1)
        {
            tail->next = node;
            tail = node;
        }
        // 在中间插入需要遍历链表，效率会慢很多
        else
        {
            ListNode<T> *Current = this->head;
            for (int i = 0; i < position - 1; i++)
            {
                Current = Current->next;
            }
            node->next = Current->next;
            Current->next = node;
        }
        this->size++;
    }

    void Remove(int position)
    {
        // 删除位置不合理
        if (position > this->size || position < 0)
        {
            return;
        }
        ListNode<T> *temp = this->head;
        //  删除头结点
        if (position == 0)
        {
            this->head = this->head->next;
            delete temp;
        }
        // 删除处于中间位置的结点，需要遍历整个链表
        else
        {
            ListNode<T> *Currnet = this->head;
            for (int i = 0; i < position - 1; i++)
            {
                Currnet = Currnet->next;
            }
            temp = Currnet->next;
            Currnet->next = Currnet->next->next;
            delete temp;
        }
        this->size--;
    }
    void Clear()
    {
        while (this->head != NULL)
        {
            ListNode<T> *temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        this->size = 0;
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

    void Print()
    {
        ListNode<T> *PCurrent = this->head;
        cout << "[";
        for (int i = 0; i < this->size; i++)
        {
            cout << PCurrent->data;
            if (i != this->size - 1)
            {
                cout << ",";
            }
            PCurrent = PCurrent->next;
        }
        cout << "]" << endl;
    }
};
void LinkListTest(void);

#endif