#include "StringMatching.h"
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

void GetNextArray(const char *SubString, int *NextArray)
{
    NextArray[0] = -1;
    NextArray[1] = 0;
    int i = 2;
    // k是用来纪录next数组各个下标所对应的值，同时k也是当前字符前面的最长公共前后缀的个数
    int k = NextArray[1];
    while (i < strlen(SubString))
    {
        // 如果k==-1，说明SubString[i-1]与第一个字符都不相等，所以公共前后缀就为0
        if (k == -1 || SubString[i - 1] == SubString[k])
        {

            // 最长公共前后缀的个数+1
            k++;
            // 移动到下一个字符
            i++;
            NextArray[i] = k;
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
void SingleCharCount(char str[])
{
    // 按照数字，小写字母，大写字母的顺序排列
    int count[62] = {0};
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            count[str[i] - '0' + 0]++;
        }
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            count[str[i] - 'a' + 10]++;
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            count[str[i] - 'A' + 36]++;
        }
    }
    // 打印每个字符出现的频率
    for (int i = 0; i < 62; i++)
    {
        if (i >= 0 && i <= 9 && count[i] != 0)
        {
            cout << "字符 \"" << (char)('0' + i) << "\""
                 << " : " << count[i] << endl;
        }
        if (i >= 10 && i <= 35 && count[i] != 0)
        {
            cout << "字符 \"" << (char)('a' + i - 10) << "\""
                 << " : " << count[i] << endl;
        }
        if (i >= 36 && i <= 61 && count[i] != 0)
        {
            cout << "字符 \"" << (char)('A' + 36) << "\""
                 << " : " << count[i] << endl;
        }
    }
    cout << endl;
}
void StringTest(void)
{
    char s[] = "abcde11";
    SingleCharCount(s);
}