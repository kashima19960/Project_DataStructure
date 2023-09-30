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
Stack_sta ParenthesisMatching(char str[])
{
    Stack_sta status = Stack_True;
    int index = 0;
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
                status = Stack_False;
                PrintError(str, p - str);
            }
        }
        p++;
    }
    // �����û��ƥ�䵽��������
    while (mystack.Get_Size() > 0)
    {
        cout << "δƥ���������\n";
        status = Stack_False;
        PrintError(str, (char *)mystack.Get_Top() - str);
        mystack.Pop_Stack();
    }
    return status;
}
// 2.��׺���ʽת���ɺ�׺���ʽ
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
char *Transform(char c[])
{
    if (ParenthesisMatching(c) == Stack_False)
    {
        exit(0);
    }
    Link_Stack mystack;
    char *result = new char[1024];
    int count = 0;
    for (int i = 0; i < strlen(c); i++)
    {
        // ��������Ϊ����ʱ��ֱ�Ӵ�ӡ���
        if (c[i] >= '0' && c[i] <= '9')
        {
            // cout << c[i] << " ";
            result[count++] = c[i];
        }
        // ��������Ϊ������ʱ������洢��ջstack�г�ΪԪ�ط�
        if (c[i] == '(')
        {
            mystack.Push_Stack(&c[i]);
        }
        //  ��������Ϊ������Ϊ����ջstack�е���ջ��Ԫ�ط����������ֱ��ƥ�䵽������Ϊֹ
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
                // cout << *ch << " ";
                result[count++] = *ch;
                mystack.Pop_Stack();
            }
        }
        // ��������Ϊ�����ʱ����Ҫ������ջ��Ԫ�ط����ȼ���һ���Ƚ�
        if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')
        {
            // ���ջ�վ�ֱ����ջ�����ý������ȼ��Ƚ�
            if (mystack.Get_Size() == 0)
            {
                mystack.Push_Stack(&c[i]);
            }
            else
            {
                while (mystack.Get_Size() > 0)
                {
                    // �����������ȼ�����ջ��Ԫ�ط����ȼ���ʱ��ֱ����ջ
                    if (priority(c[i]) > priority(*(char *)mystack.Get_Top()))
                    {
                        mystack.Push_Stack(&c[i]);
                        break;
                    }
                    // �����������ȼ�С�ڻ����ջ��Ԫ�����ȼ���ʱ�򣬵���ջ��Ԫ�ط�����ӡ��
                    else
                    {
                        // cout << *(char *)mystack.Get_Top() << " ";
                        result[count++] = *(char *)mystack.Get_Top();
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
    // �������ַ������������ջ��Ԫ��
    while (mystack.Get_Size() > 0)
    {
        // cout << *(char *)mystack.Get_Top() << " ";
        result[count++] = *(char *)mystack.Get_Top();
        mystack.Pop_Stack();
    }
    return result;
}
// 3.��׺���ʽ�����
int operate(int numleft, int numright, char c)
{
    int result;
    switch (c)
    {
    case '+':
        result = numleft + numright;
        break;
    case '-':
        result = numleft - numright;
        break;
    case '*':
        result = numleft * numright;
        break;
    case '/':
        result = numleft / numright;
        break;
    default:
        break;
    }
    return result;
}
int CalculatePostfix(char *postfix)
{
    char *array = Transform(postfix);
    Link_Stack stack;
    for (int i = 0; i < strlen(array); i++)
    {
        // ��������Ϊ����ʱ��ֱ����ջ��
        if (array[i] >= '0' && array[i] <= '9')
        {
            stack.Push_Stack(new int(array[i] - '0'));
        }
        // ��������Ϊ�����ʱ��ȡջ���������Ҽ�����ֵ����������ȡһ��ջ���������������ֵ��������������������������㣬�����ջ��
        if (array[i] == '+' || array[i] == '-' || array[i] == '*' || array[i] == '/')
        {
            int numberright = *(int *)stack.Get_Top();
            stack.Pop_Stack();
            int numberleft = *(int *)stack.Get_Top();
            stack.Pop_Stack();
            int result = operate(numberleft, numberright, array[i]);
            stack.Push_Stack(new int(result));
        }
    }
    // ��������ɺ󣬴�ջ�е���Ψһ���֣������־��������׺���ʽ��������
    return *(int *)stack.Get_Top();
}
void StackTest(void)
{
    char str[] = "5+5*(6)+9/3*1-1+3";
    cout << CalculatePostfix(str);
}