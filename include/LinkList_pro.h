/*
��ҵ�����и�����Ҫע��ĵ㣡��ÿ�����������Ľ�㣬����һ��������ͬһ����������
��Ҫ����һ����������ݣ���ҵ�����ԭ���ǽ�������������ָ��������ӡ���ͳ���������������������Ϊ
�ڲ���ʱ�����´���һ���µĽ��������������
    Mydata data;
    LinkList list;
    for (int i = 0; i < 4; i++)
    {
        data.age = i + 1;
        list.pushback((ListNode *)&data);
    }
    list.List_print(Myprint);
*/
#pragma once
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
void LinkListTest(void);