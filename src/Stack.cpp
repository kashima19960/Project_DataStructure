#include "Stack.h"
//---------------------------------------------------------
// 顺序栈
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
// 链式栈
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
// 下面是栈的一些应用
// 1.括号的就近匹配
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
        // 处理右括号
        if (*p == ')')
        {
            if (mystack.Get_Size() > 0)
            {
                mystack.Pop_Stack();
            }
            else
            {
                cout << "未匹配的右括号\n";
                PrintError(str, p - str);
            }
        }
        p++;
    }
    // 处理掉没有匹配到的左括号
    while (mystack.Get_Size() > 0)
    {
        cout << "未匹配的左括号\n";
        PrintError(str, (char *)mystack.Get_Top() - str);
        mystack.Pop_Stack();
    }
}
// 2.中缀表达式转换成后缀表达式
unsigned short priority(char c)
{
    unsigned short value = 0;
    if (c == '*' || c == '/')
    {
        value = 2;
    }
    if (c == '+' || c == '-')
    {
        value = 1;
    }
    return value;
}
void Transform(char c[])
{
    Link_Stack mystack;
    for (int i = 0; i < strlen(c); i++)
    {
        // 当操作符为数字时，直接打印输出
        if (c[i] > '0' && c[i] < '9')
        {
            cout << c[i] << " ";
        }
        // 当操作符为左括号时，将其存储到栈stack中成为元素符
        if (c[i] == '(')
        {
            mystack.Push_Stack(&c[i]);
        }
        //  当操作符为右括号为，从栈stack中弹出栈顶元素符，并输出，直到匹配到左括号为止
        if (c[i] == ')')
        {
            while (mystack.Get_Size() > 0)
            {
                char *ch = (char *)mystack.Get_Top();
                if (*ch == '(')
                {
                    mystack.Pop_Stack();
                    break;
                }
                cout << *ch << " ";
                mystack.Pop_Stack();
            }
        }
        // 当操作符为运算符时，需要将其与栈顶元素符优先级做一个比较
        if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')
        {
            // 如果栈空就直接入栈，不用进行优先级比较
            if (mystack.Get_Size() == 0)
            {
                mystack.Push_Stack(&c[i]);
            }
            else
            {
                while (mystack.Get_Size() > 0)
                {
                    // 当操作符优先级大于栈顶元素符优先级的时候，直接入栈
                    if (priority(c[i]) > priority(*(char *)mystack.Get_Top()))
                    {
                        mystack.Push_Stack(&c[i]);
                        break;
                    }
                    // 当操作符优先级小于或等于栈顶元素优先级的时候，弹出栈顶元素符并打印，
                    else
                    {
                        cout << *(char *)mystack.Get_Top() << " ";
                        mystack.Pop_Stack();
                        if (mystack.Get_Size() == 0)
                        {
                            mystack.Push_Stack(&c[i]);
                            break;
                        }
                    }
                }
            }
        }
    }
    // 遍历完字符串后，输出所有栈中元素
    while (mystack.Get_Size() > 0)
    {
        cout << *(char *)mystack.Get_Top() << " ";
        mystack.Pop_Stack();
    }
}
void StackTest(void)
{
    char test[] = "8+1*3/(1-2)";
    Transform(test);
}