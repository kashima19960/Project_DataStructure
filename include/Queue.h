#pragma once
#include <iostream>
#include "ListNode.h"
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
#define MAX_SIZE 1024
// 顺序队列声明
class Sec_Queue
{
private:
    void *data[MAX_SIZE];
    int size;

public:
    Sec_Queue();
    void Pop();
    void Push(void *data);
    void *Get_Front();
    int Get_Size();
};
void QueueTest(void);
// 链式队列声明
class LinkQueue
{
private:
    ListQueueNode *head;
    int size;

public:
    LinkQueue();
    void Push(void *data);
    void Pop();
    void *Get_front(void);
    int Get_Size();
    void clear(void);
    ~LinkQueue();
};
