#include "Queue.hpp"

void QueueTest(void)
{
    ArrayQueue<int> test;
    for (int i = 0; i < 5; i++)
    {
        test.push(i);
    }
    test.pop();
    test.pop();
    test.pop();
    test.pop();
    test.PrintArrayQueue();
}
