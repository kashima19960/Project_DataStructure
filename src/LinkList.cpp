#include "LinkList.hpp"
void LinkListTest(void)
{
    LinkList<int> test;
    for (int i = 0; i < 5; i++)
    {
        test.Pushback(i);
    }
    test.Print();
    test.Remove(3);
    test.Print();
}