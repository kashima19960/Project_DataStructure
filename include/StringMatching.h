#ifndef STRINGMATCHING_H
#define STRINGMATCHING_H
#include <iostream>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
void StringTest(void);
// 字符串匹配BF(brute-force)算法实现
int BF(const char *MainString, const char *SubString);
void GetNextArray(const char *SubString, int *NextArray);
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
int KMP(const char *MainString, const char *SubString);
/*
统计一个字符串中每一个字符出现的次数，这个函数功能只能统计英文字母和阿拉伯数字，无法统计汉字
*/
void SingleCharCount(char str[]);
#endif