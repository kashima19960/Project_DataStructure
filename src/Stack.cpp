#include "Stack.h"
//---------------------------------------------------------
// ˳��ջ
Sec_Stack::Sec_Stack()
{
    for (int i = 0; i < CAPACITY; i++)
    {
        this->data[i] = NULL;
    }
    this->size = 0;
}
void Sec_Stack::Pop_Stack()
{
    if (IsEmpty() == Stack_True)
    {
        return;
    }
    this->data[this->size - 1] = NULL;
    this->size--;
}
void Sec_Stack::Push_Stack(void *data)
{
    if (this->size == CAPACITY)
    {
        return;
    }
    this->data[this->size] = data;
    this->size++;
}

Stack_sta Sec_Stack::IsEmpty()
{
    if (this->size == 0)
    {
        return Stack_True;
    }
    else
    {
        return Stack_False;
    }
}
void *Sec_Stack::Get_Top()
{
    if (IsEmpty() == Stack_True)
    {
        return NULL;
    }
    return this->data[this->size - 1];
}
void Sec_Stack::clear()
{
    if (IsEmpty() == Stack_True)
    {
        return;
    }
    for (int i = 0; i < this->size; i++)
    {
        this->data[i] = NULL;
    }
}
int Sec_Stack::Get_Size()
{
    return this->size;
}

//---------------------------------------------------------
// ��ʽջ
Link_Stack::Link_Stack()
{
    head.data = NULL;
    head.next = NULL;
    size = 0;
}
Link_Stack::~Link_Stack()
{
    if (head.next != NULL)
    {
        clear();
    }
}
int Link_Stack::Get_Size()
{
    return size;
}
void Link_Stack::Pop_Stack()
{
    if (IsEmpty() == Stack_True)
    {
        return;
    }
    else
    {
        ListStackNode *del_cache = head.next;
        head.next = del_cache->next;
        delete del_cache;
        size--;
    }
}
void Link_Stack::Push_Stack(void *data)
{
    ListStackNode *newnode = new ListStackNode;
    newnode->data = data;
    newnode->next = head.next;
    head.next = newnode;
    size++;
}
Stack_sta Link_Stack::IsEmpty()
{
    if (this->size == 0)
    {
        return Stack_True;
    }
    else
    {
        return Stack_False;
    }
}
void *Link_Stack::Get_Top()
{
    if (IsEmpty() == Stack_True)
    {
        return NULL;
    }
    else
    {
        return head.next->data;
    }
}
void Link_Stack::clear()
{
    if (head.next == NULL)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        Pop_Stack();
    }
}
// ������ջ��һЩӦ��
// 1.���ŵľͽ�ƥ��
void PrintError(char *str, int pos)
{
    printf("%s\n", str);
    for (int i = 0; i < pos; i++)
    {
        printf(" ");
    }
    printf("^\n");
}
void ParenthesisMatching(void)
{
    int index = 0;
    char str[] = "5+5*(6)+9/3*1-(1+3(";
    char *p = str;
    Sec_Stack mystack;
    while (*p != '\0')
    {
        if (*p == '(')
        {
            mystack.Push_Stack(p);
        }
        // ����������
        if (*p == ')')
        {
            if (mystack.Get_Size() > 0)
            {
                mystack.Pop_Stack();
            }
            else
            {
                cout << "δƥ���������\n";
                PrintError(str, p - str);
            }
        }
        p++;
    }
    // �����û��ƥ�䵽��������
    while (mystack.Get_Size() > 0)
    {
        cout << "δƥ���������\n";
        PrintError(str, (char *)mystack.Get_Top() - str);
        mystack.Pop_Stack();
    }
}
void StackTest(void)
{
    ParenthesisMatching();
}