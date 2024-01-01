#include "LinkList_pro.h"
class Mydata
{
public:
    ListNode node;
    int age;
    Mydata(int age)
    {
        this->age = age;
    }
    Mydata()
    {
    }
};
LinkList::LinkList()
{
    this->head.next = NULL;
    this->size = 0;
}
void LinkList::pushback(ListNode *node)
{
    ListNode *Current = &(this->head);
    while (Current->next != NULL)
    {
        Current = Current->next;
    }
    Current->next = node;
    node->next = NULL;
    this->size++;
}
void LinkList::popback()
{
    if (this->head.next == NULL)
    {
        cerr << "error! LinkList empty" << endl;
        return;
    }
    ListNode *Current = this->head.next;
    for (int i = 1; i < this->size - 1; i++)
    {
        Current = Current->next;
    }
    Current->next = NULL;
    this->size--;
}
void LinkList::insert(ListNode *node, int position)
{
    if (position > this->size || position < 0)
    {
        position = this->size - 1;
    }
    ListNode *Current = &(this->head);
    for (int i = 0; i < position; i++)
    {
        Current = Current->next;
    }
    node->next = Current->next;
    Current->next = node;
}
void LinkList::RemoveByIndex(int position)
{
    if (position > this->size)
    {
        // 这里保存的是下标，下标是几，Current就移动几次
        position = this->size - 1;
    }
    ListNode *Current = &(this->head);
    for (int i = 0; i < position; i++)
    {
        Current = Current->next;
    }
    Current->next = Current->next->next;
}
void LinkList::List_print(void (*PRINT)(ListNode *))
{
    ListNode *Current = this->head.next;
    while (Current != NULL)
    {
        PRINT(Current);
        Current = Current->next;
    }
}
void LinkList::RemoveByValue(ListNode *node, bool (*COMPARE)(ListNode *, ListNode *))
{
    ListNode *Current = &(this->head);
    while (Current->next != NULL)
    {
        if (COMPARE(node, Current->next) == true)
        {
            Current->next = Current->next->next;
            this->size--;
        }
        else
        {
            Current = Current->next;
        }
    }
}
static void Myprint(ListNode *node)
{
    Mydata *temp = (Mydata *)node;
    cout << temp->age << " " << endl;
}
static bool Mycompare(ListNode *data1, ListNode *data2)
{
    Mydata *temp1 = (Mydata *)data1;
    Mydata *temp2 = (Mydata *)data2;
    if (temp1->age == temp2->age)
    {
        return true;
    }
    return false;
}
void LinkListProTest(void)
{
    Mydata data;
    LinkList list;
    for (int i = 0; i < 4; i++)
    {
        data.age = i + 1;
        list.pushback((ListNode *)&data);
    }
    list.List_print(Myprint);
}