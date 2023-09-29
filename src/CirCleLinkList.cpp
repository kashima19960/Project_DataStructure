#include "CirCleLinkList.h"
class JosephData
{
public:
    ListNode node;
    int number;
    JosephData(int number)
    {
        this->number = number;
    }
    JosephData()
    {
    }
};
CirCleLinkList::CirCleLinkList()
{
    this->head.next = NULL;
    this->size = 0;
}
void CirCleLinkList::pushback(ListNode *node)
{
    ListNode *Current = &(this->head);
    for (int i = 0; i < this->size; i++)
    {
        Current = Current->next;
    }
    Current->next = node;
    node->next = this->head.next;
    this->size++;
}
void CirCleLinkList::popback()
{
    if (this->size == 0)
    {
        cerr << "error! CirCleLinkList empty" << endl;
        return;
    }
    ListNode *Current = &(this->head);
    for (int i = 0; i < this->size - 1; i++)
    {
        Current = Current->next;
    }
    ListNode *del_cache = Current->next;
    Current->next = this->head.next;
    del_cache->next = NULL;
    this->size--;
}
void CirCleLinkList::insert(ListNode *node, int position)
{
    ListNode *Current;
    position = position % (this->size + 1);
    if (position == 0)
    {
        Current = &(this->head);
        for (int i = 0; i < this->size; i++)
        {
            Current = Current->next;
        }
        Current->next = this->head.next;
        node->next = this->head.next;
        this->head.next = node;
        Current = this->head.next;
    }
    else
    {
        Current = &(this->head);
        for (int i = 0; i < position; i++)
        {
            Current = Current->next;
        }
        node->next = Current->next;
        Current->next = node;
    }
    this->size++;
}
// 写到这个函数
void CirCleLinkList::RemoveByIndex(int position)
{
    if (position > this->size)
    {
        // 这里保存的是下标，下标是几，Current就移动几次
        position = this->size - 1;
    }
    ListNode *Current = &(this->head);
    if (position == 0)
    {
        for (int i = 0; i < this->size; i++)
        {
            Current = Current->next;
        }
        this->head.next = this->head.next->next;
        Current->next = this->head.next;
        this->size--;
    }
    else
    {
        for (int i = 0; i < position; i++)
        {
            Current = Current->next;
        }
        Current->next = Current->next->next;
        this->size--;
    }
}
void CirCleLinkList::List_print(void (*PRINT)(ListNode *))
{
    ListNode *Current = this->head.next;
    for (int i = 0; i < this->size; i++)
    {
        PRINT(Current);
        Current = Current->next;
    }
    cout << endl;
}

void CirCleLinkList::RemoveByValue(ListNode *node, bool (*COMPARE)(ListNode *, ListNode *))
{
    ListNode *Current = &(this->head);
    if (COMPARE(node, Current->next) && Current->next == this->head.next)
    {
        for (int i = 0; i < this->size; i++)
        {
            Current = Current->next;
        }
        this->head.next = this->head.next->next;
        Current->next = this->head.next;
        this->size--;
    }
    else
    {
        for (int i = 0; i < this->size; i++)
        {
            Current = Current->next;
            if (COMPARE(node, Current->next))
            {
                break;
            }
        }
        Current->next = Current->next->next;
        this->size--;
    }
}

static void Myprint(ListNode *node)
{
    JosephData *temp = (JosephData *)node;
    cout << temp->number << " ";
}
static bool Mycompare(ListNode *data1, ListNode *data2)
{
    JosephData *temp1 = (JosephData *)data1;
    JosephData *temp2 = (JosephData *)data2;
    if (temp1->number == temp2->number)
    {
        return true;
    }
    return false;
}
void Joseph(int number, int first_one, int move_number)
{
    CirCleLinkList list;
    int index = 1;
    JosephData data[number];
    ListNode *Current = &(list.head);
    // 检查参数
    if (first_one > number || first_one < 0 || number < 0)
    {
        cout << "参数不合理！" << endl;
        return;
    }
    // 创建循环链表
    for (int i = 0; i < number; i++)
    {
        data[i].number = i + 1;
        list.pushback((ListNode *)&data[i]);
    }
    // 移动到第一个报数人的位置
    for (int i = 0; i < first_one; i++)
    {
        Current = Current->next;
    }
    while (list.size > 1)
    {
        while (index != move_number)
        {
            Current = Current->next;
            index++;
        }
        index = 1;
        cout << "本轮出局的为：";
        Myprint(Current);
        list.RemoveByValue(Current, Mycompare);
        Current = Current->next;
    }
    cout << endl;
    cout << "最后的赢家是：";
    list.List_print(Myprint);
}

void CirCleLinkListTest(void)
{
}