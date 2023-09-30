#include "Queue.h"
// 顺序队列定义
Sec_Queue::Sec_Queue()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        data[i] = NULL;
    }
    size = 0;
}
void Sec_Queue::Pop()
{
    for (int i = 0; i < size; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
}
void Sec_Queue::Push(void *data)
{
    if (data == NULL || size >= MAX_SIZE)
    {
        return;
    }
    this->data[size++] = data;
}
void *Sec_Queue::Get_Front()
{
    if (this->data[0] == NULL)
    {
        return NULL;
    }
    return this->data[0];
}

int Sec_Queue::Get_Size()
{
    return this->size;
}

// 链式队列定义
LinkQueue::LinkQueue()
{
    head = new ListQueueNode;
    head->data = NULL;
    head->next = NULL;
    size = 0;
}

LinkQueue::~LinkQueue()
{
    if (head->next == NULL)
    {
        return;
    }
    else
    {
        clear();
    }
}
void LinkQueue::Push(void *data)
{
    if (size == MAX_SIZE)
    {
        cout << "Current contain has fulled!" << endl;
        return;
    }
    ListQueueNode *Current = head;
    ListQueueNode *newnode = new ListQueueNode;
    newnode->data = data;
    for (int i = 0; i < size; i++)
    {
        Current = Current->next;
    }
    Current->next = newnode;
    newnode->next = NULL;
    size++;
}
void LinkQueue::Pop()
{
    if (size == 0)
    {
        cout << "Current container empty!" << endl;
        return;
    }
    ListQueueNode *del_cache = head->next;
    head->next = del_cache->next;
    delete del_cache;
    del_cache->next = NULL;
    size--;
}
void *LinkQueue::Get_front(void)
{
    if (head->next == NULL || size == 0)
    {
        cout << "Invalid action!" << endl;
        return NULL;
    }
    return head->next->data;
}
int LinkQueue::Get_Size()
{
    return size;
}
void LinkQueue::clear(void)
{
    for (int i = size; i > 0; i--)
    {
        Pop();
    }
    size = 0;
}
void QueueTest(void)
{
    Sec_Queue test;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        test.Push(new int(i));
    }
    for (int i = 0; i < MAX_SIZE; i++)
    {
        cout << *(int *)test.Get_Front() << " ";
        test.Pop();
    }
}