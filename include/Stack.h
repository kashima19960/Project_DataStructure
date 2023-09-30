#pragma once
#include <iostream>
#include <cstring>
#include "ListNode.h"
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
#define CAPACITY 1024
enum Stack_sta
{
    Stack_False = 0,
    Stack_True
};
class Sec_Stack
{
private:
    void *data[CAPACITY];
    int size;

public:
    Sec_Stack();
    int Get_Size();
    void Pop_Stack();
    void Push_Stack(void *data);
    Stack_sta IsEmpty();
    void *Get_Top();
    void clear();
};

//-----------------------------------------------------
// ¡¥ Ω’ª
class Link_Stack
{
public:
    ListStackNode head;
    int size;
    Link_Stack();
    ~Link_Stack();
    int Get_Size();
    void Pop_Stack();
    void Push_Stack(void *data);
    Stack_sta IsEmpty();
    void *Get_Top();
    void clear();
};
// À≥–Ú’ª≤‚ ‘∫Ø ˝
void test05(void);
// ¡¥ Ω’ª≤‚ ‘∫Ø ˝
void PrintError(char *str, int pos);
void ParenthesisMatching(void);
void StackTest(void);