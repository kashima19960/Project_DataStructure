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
// number��ʾѭ������������first_one��ʾ�����ĵ�һ���˵ı�ţ�move_number��ʾ���α�������
void Joseph(int number, int first_one, int move_number);
void CirCleLinkListTest(void);
#endif