/*
企业链表有个必须要注意的点！！每次往链表插入的结点，他们一定不能是同一个变量！！
简要解释一下上面的内容，企业链表的原理是将各个传进来的指针进行链接。传统链表不会出现这种问题是因为
在插入时会重新创建一个新的结点来保存数据域。
    Mydata data;
    LinkList list;
    for (int i = 0; i < 4; i++)
    {
        data.age = i + 1;
        list.pushback((ListNode *)&data);
    }
    list.List_print(Myprint);
*/
#ifndef LINKLISTPRO_H
#define LINKLISTPRO_H
#include "ListNode.h"
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::string;

class LinkList
{
public:
    ListNode head;
    int size;
    LinkList();
    void pushback(ListNode *node);
    void popback();
    void insert(ListNode *node, int position);
    void RemoveByIndex(int position);
    void RemoveByValue(ListNode *node, bool (*COMPARE)(ListNode *, ListNode *));
    void List_print(void (*PRINT)(ListNode *));
};
void LinkListProTest(void);
#endif