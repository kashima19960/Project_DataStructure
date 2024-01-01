#ifndef CIRCLELINKLIST_H
#define CIRCLELINKLIST_H
#include <iostream>
#include "ListNode.h"
using std::cerr;
using std::cout;
using std::endl;
using std::string;
class CirCleLinkList
{
public:
    ListNode head;
    int size;
    CirCleLinkList();
    void pushback(ListNode *node);
    void popback();
    void insert(ListNode *node, int position);
    void RemoveByIndex(int position);
    void RemoveByValue(ListNode *node, bool (*COMPARE)(ListNode *, ListNode *));
    void List_print(void (*PRINT)(ListNode *));
};
// number表示循环的总人数，first_one表示报数的第一个人的编号，move_number表示单次报数次数
void Joseph(int number, int first_one, int move_number);
void CirCleLinkListTest(void);
#endif