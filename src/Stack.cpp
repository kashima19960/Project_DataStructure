#include "Stack.hpp"
void StackTest(void)
{
    Link_Stack<int> test;
    test.Push_Stack(1);
    test.Push_Stack(2);
    test.Push_Stack(3);
    test.Push_Stack(4);
    test.Push_Stack(5);
    test.print();
}