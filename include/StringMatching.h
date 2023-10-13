#pragma once
#include <iostream>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
void StringTest(void);
// �ַ���ƥ��BF(brute-force)�㷨ʵ��
int BF(const char *MainString, const char *SubString);
void GetNextArray(const char *SubString, int *NextArray);
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
int KMP(const char *MainString, const char *SubString);
/*
ͳ��һ���ַ�����ÿһ���ַ����ֵĴ����������������ֻ��ͳ��Ӣ����ĸ�Ͱ��������֣��޷�ͳ�ƺ���
*/
void SingleCharCount(char str[]);