#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
class Dynamic_array
{
public:
    int size;
    int capacity;
    double *arr;
    Dynamic_array();
    void creat();
    void insert(int position, int value);
    void pushback(int value);
    void popback(void);
    void DuplicateRemove();
    void clear();
    void remove(int postion);
    void sort(void);
    void print();
    double GetMax(void);
    double GetMin(void);
    ~Dynamic_array();
};
void DynamicArrayTest();
#endif