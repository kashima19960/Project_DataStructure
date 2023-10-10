#include "StringMatching.h"
// �ַ���ƥ��BF(brute-force)�㷨ʵ��
int BF(const char *MainString, const char *SubString)
{
    int result = -1;
    int MainStringLength = strlen(MainString);
    int SubStringLength = strlen(SubString);
    int i = 0, j = 0;
    while (i < MainStringLength && j < SubStringLength)
    {
        if (MainString[i] == SubString[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= SubStringLength)
    {
        result = i - j;
        cout << "substring matching succeed!" << endl;
        cout << MainString << endl;
        for (int i = 0; i < result; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < SubStringLength; i++)
        {
            cout << "^";
        }
    }
    else
    {
        cerr << "substring matching failed!" << endl;
    }
    return 1;
}
// KMP�㷨ʵ��

/*
KMP�㷨�����next����ķ�������һ��ʵ�ʵ�ƥ��Ϊ����
                           k           i
�±�                    0  1  2  3  4  5  6  7  8  9  10
�ַ���                  a  b  c  a  b  a  b  c  a  b  c
��������ʱ���˵��±�    -1 0  0  0  1  2  1  2  3  4  5

������ȷ��next�����һ��λһ���ֱ�Ϊ-1��0���������ÿһλ��nextֵʱ������ǰһλ���бȽϡ�
�ӵ���λ��ʼ����ǰһλ����nextֵ��Ӧ�����ݽ��бȽϣ�
�����ȣ����λ��nextֵ����ǰһλ��nextֵ����1��
������ȣ���ǰ����Ѱ��nextֵ��Ӧ����������ǰһλ���бȽϣ�
ֱ���ҵ�ĳ��λ�����ݵ�nextֵ��Ӧ��������ǰһλ���Ϊֹ��
����ҵ���һλ��û���ҵ���ǰһλ��ȵ����ݣ���ô����λ�ϵ�nextֵΪ0
*/
void GetNextArray(const char *SubString, int *NextArray)
{
    NextArray[0] = -1;
    NextArray[1] = 0;
    int i = 2;
    // k��������¼next��������±�����Ӧ��ֵ��ͬʱkҲ�ǵ�ǰ�ַ�ǰ��������ǰ��׺�ĸ���
    int k = NextArray[1];
    while (i < strlen(SubString))
    {
        // ���k==-1��˵��SubString[i-1]���һ���ַ�������ȣ����Թ���ǰ��׺��Ϊ0
        if (k == -1 || SubString[i - 1] == SubString[k])
        {
            NextArray[i] = k + 1;
            // �����ǰ��׺�ĸ���+1
            k++;
            // �ƶ�����һ���ַ�
            i++;
        }
        else
        {
            k = NextArray[k];
        }
    }
}
int KMP(const char *MainString, const char *SubString)
{
    int MainLen = strlen(MainString);
    int SubLen = strlen(SubString);
    int i = 0;
    int j = 0;
    int result = -1;
    int *NextArray = new int[SubLen];
    GetNextArray(SubString, NextArray);
    while (i < MainLen && j < SubLen)
    {
        if (j == -1 || MainString[i] == SubString[j])
        {
            j++;
            i++;
        }
        else
        {
            j = NextArray[j];
        }
    }
    if (j >= SubLen)
    {
        result = i - j;
        cout << "substring matching succeed!" << endl;
        cout << MainString << endl;
        for (int i = 0; i < result; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < SubLen; i++)
        {
            cout << "^";
        }
    }
    else
    {
        cerr << "substring matching failed!" << endl;
    }
    return result;
}

void StringTest(void)
{
    char s1[] = "���������Ҷ��壬���˽����Ҷ���";
    char s2[] = " ";
    KMP(s1, s2);
}