#ifndef QUEUE_H
#define QUEUE_H
#include "common.h"
void QueueTest(void);
template <class T>
class LinkQueue
{
private:
    ListNode<T> *front;
    ListNode<T> *rear;
    int size;

public:
    LinkQueue()
    {
        this->front = this->rear = NULL;
        this->size = 0;
    }
    ~LinkQueue()
    {
        while (this->size)
        {
            this->Pop();
        }
    }
    void Push(T data)
    {
        ListNode<T> *node = new ListNode<T>;
        node->data = data;
        node->next = NULL;

        if (this->front == NULL)
        {
            this->front = node;
            this->rear = node;
        }
        else
        {
            this->rear->next = node;
            this->rear = node;
        }
        this->size++;
    }
    T Pop()
    {
        T num = peek();
        if (this->size <= 0)
        {
            cerr << "队列为空，不可以继续出队！" << endl;
            exit(0);
        }
        ListNode<T> *temp = this->front;
        this->front = this->front->next;
        this->size--;
        delete temp;
        return num;
    }
    T peek()
    {
        return this->front->data;
    }
    int Get_Size()
    {
        return this->size;
    }
    void PrintArrayQueue()
    {
        cout << "[";
        ListNode<T> *Current = this->front;
        for (int i = 0; i < size; i++)
        {
            cout << Current->data;
            Current = Current->next;
            if (i != size - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
};
// 顺序队列
template <class T>
class ArrayQueue
{
private:
    T *data;
    int front;
    int size;
    int capacity;

public:
    ArrayQueue(int capacity)
    {
        this->capacity = capacity;
        data = new T[this->capacity];
        front = size = 0;
    }
    ArrayQueue()
    {
        this->capacity = 1024;
        data = new T[this->capacity];
        front = size = 0;
    }
    ~ArrayQueue()
    {
        delete data;
        size = 0;
    }
    int GetCapacity()
    {
        return this->capacity;
    }
    int GetSize()
    {
        return this->size;
    }

    void push(T data)
    {
        if (this->size >= this->capacity)
        {
            cerr << "队列已满，无法继续添加元素" << endl;
            return;
        }
        int rear = (this->size + this->front) % this->capacity;
        this->data[rear] = data;
        this->size++;
    }
    T pop()
    {
        int value = peek();
        if (this->size <= 0)
        {
            cerr << "队列已经为空，无法继续删除元素！" << endl;
            exit(0);
        }
        this->front = (this->front + 1) % this->capacity;
        this->size--;
        return value;
    }
    T peek()
    {
        return this->data[this->front];
    }
    void PrintArrayQueue()
    {
        cout << "[";
        for (int i = 0, temp = this->front; i < this->size; i++, temp = (temp + 1) % this->capacity)
        {
            cout << data[temp];
            if (i != size - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
};
#endif