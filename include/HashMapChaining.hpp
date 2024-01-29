#ifndef HASHMAPCHAINING_H
#define HASHMAPCHAINING_H
#include "common.h"
using std::vector;
#define LoadFactor 0.75
void HashMapChainingTest(void);
template <class T>
class HashMapLinkList
{
public:
    Pair<T> *head;
    Pair<T> *tail;
    int size;
    HashMapLinkList()
    {
        head = tail = NULL;
        size = 0;
    }
    void clear()
    {
        Pair<T> *Current = this->head;
        while (Current != NULL)
        {
            Pair<T> *temp = Current;
            Current = Current->next;
            delete temp;
        }
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void Pushback(unsigned long long key, T value)
    {
        Pair<T> *node = new Pair<T>;
        node->value = value;
        node->key = key;
        node->next = NULL;
        if (head == NULL)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        this->size++;
    }
    void Remove(int key)
    {
        // 如果要删除的节点是头结点
        if (this->head->key == key)
        {
            Pair<T> *temp = this->head;
            this->head = this->head->next;
            delete temp;
            this->size--;
            return;
        }

        // 如果要删除的节点是尾结点
        if (this->tail->key == key)
        {
            Pair<T> *Current = this->head;
            while (Current->next != this->tail)
            {
                Current = Current->next;
            }
            Pair<T> *temp = this->tail;
            Current->next = NULL;
            this->tail = Current;
            delete temp;
            this->size--;
            return;
        }

        // 如果要删除的节点处于中间位置
        Pair<T> *Current = this->head;
        for (int i = 0; i < this->size; i++)
        {
            if (Current->next->key == key)
            {
                break;
            }
            Current = Current->next;
        }
        Pair<T> *temp = Current->next;
        Current->next = Current->next->next;
        delete temp;
        this->size--;
    }

    void Print()
    {
        Pair<T> *Current = this->head;
        cout << "[";
        for (int i = 0; i < this->size; i++)
        {
            cout << Current->key << ":"
                 << "\"" << Current->value << "\"";
            if (i != this->size - 1)
            {
                cout << ",";
            }
            Current = Current->next;
        }
        cout << "]" << endl;
    }
};

template <class T>
class HashMapChaining
{
private:
    int size;
    int capacity;
    vector<HashMapLinkList<T>> buckets;

public:
    HashMapChaining()
    {
        this->size = 0;
        this->capacity = 4;
        buckets.resize(this->capacity);
    }
    ~HashMapChaining()
    {
        clear();
    }
    void clear()
    {
        int n = this->size;
        this->size = 0;
        this->capacity = 4;
        for (int i = 0; i < n; i++)
        {
            this->buckets[i].clear();
        }
    }

    void Put(unsigned long long key, T value)
    {
        auto index = HashFunction(key);
        Pair<T> *Current = this->buckets[index].head;
        if ((double)this->size / (double)this->capacity > LoadFactor)
        {
            Extend();
        }
        while (Current != NULL)
        {
            if (Current->key == key)
            {
                Current->value = value;
                return;
            }
            Current = Current->next;
        }
        this->buckets[index].Pushback(key, value);
        this->size++;
    }
    T Get(int key)
    {
        int index = HashFunction(key);
        Pair<T> *Current = this->buckets[index].head;
        while (Current != NULL)
        {
            if (Current->key == key)
            {
                return Current->value;
            }
            Current = Current->next;
        }
        return T();
    }
    void Remove(int key)
    {
        this->buckets[HashFunction(key)].Remove(key);
    }
    void Extend()
    {
        vector<HashMapLinkList<T>> bucketstmp = this->buckets;
        this->capacity *= 2;
        this->buckets.clear();
        this->buckets.resize(this->capacity);
        this->size = 0;
        for (int i = 0; i < bucketstmp.size(); i++)
        {
            Pair<T> *Current = bucketstmp[i].head;
            while (Current != NULL)
            {
                this->Put(Current->key, Current->value);
                Current = Current->next;
            }
        }
    }
    void Print()
    {
        for (int i = 0; i < this->size; i++)
        {
            this->buckets[i].Print();
        }
    }
    unsigned long long HashFunction(unsigned long long key)
    {
        return key % this->capacity;
    }
};

#endif
