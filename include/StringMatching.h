#pragma once
#include <iostream>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
void StringTest(void);
int BF(const char *MainString, const char *SubString);
void GetNextArray(const char *SubString, int *NextArray);
int KMP(const char *MainString, const char *SubString);
