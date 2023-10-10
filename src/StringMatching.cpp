#include "StringMatching.h"
// 字符串匹配BF(brute-force)算法实现
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
// KMP算法实现

/*
KMP算法中求解next数组的方法，以一个实际的匹配为例子
                           k           i
下标                    0  1  2  3  4  5  6  7  8  9  10
字符串                  a  b  c  a  b  a  b  c  a  b  c
发生错误时回退的下标    -1 0  0  0  1  2  1  2  3  4  5

我们能确定next数组第一二位一定分别为-1，0，后面求解每一位的next值时，根据前一位进行比较。
从第三位开始，将前一位与其next值对应的内容进行比较，
如果相等，则该位的next值就是前一位的next值加上1；
如果不等，向前继续寻找next值对应的内容来与前一位进行比较，
直到找到某个位上内容的next值对应的内容与前一位相等为止，
如果找到第一位都没有找到与前一位相等的内容，那么求解的位上的next值为0
*/
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
            NextArray[i] = k + 1;
            // 最长公共前后缀的个数+1
            k++;
            // 移动到下一个字符
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
    char s1[] = "举世皆浊我独清，世人皆醉我独醒";
    char s2[] = " ";
    KMP(s1, s2);
}