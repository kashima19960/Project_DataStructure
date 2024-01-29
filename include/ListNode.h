#ifndef LISTNODE_H
#define LISTNODE_H

template <class T>
class ListNode
{
public:
    T data;
    ListNode<T> *next;
};

template <class T>
class Pair
{
public:
    unsigned long long key;
    T value;
    Pair<T> *next;
};

#endif
