#ifndef LISTNODE_H
#define LISTNODE_H

template <class T>
class ListNode
{
public:
    T data;
    ListNode<T> *next;
};
#endif