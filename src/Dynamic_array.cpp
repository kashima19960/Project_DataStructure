#include "Dynamic_array.h"

Dynamic_array::Dynamic_array()
{
    this->capacity = 20;
    this->arr = new double[this->capacity];
    this->size = 0;
}

void Dynamic_array::creat()
{
    if (this->arr == NULL)
    {
        this->capacity = 20;
        this->arr = new double[this->capacity];
        this->size = 0;
    }
    else
    {
        cout << "warning! Array is not empty.please wipe it out and retry" << endl;
        return;
    }
}

void Dynamic_array::insert(int position, int value)
{
    // 0 1 2 3 4
    for (int i = this->size - 1; i >= position; i--)
    {
        this->arr[i + 1] = this->arr[i];
    }
    this->arr[position] = value;
    this->size++;
}

void Dynamic_array::pushback(int value)
{
    if (this->size >= this->capacity)
    {
        double *temp = new double[capacity * 2];
        std::memcpy(temp, this->arr, sizeof(int) * this->capacity);
        delete this->arr;
        this->arr = temp;
        this->capacity *= 2;
    }
    this->arr[size++] = value;
}

void Dynamic_array::print()
{
    for (int i = 0; i < this->size; i++)
    {
        if (i == 0)
        {
            cout << "[";
        }
        if (i == this->size - 1)
        {
            cout << this->arr[i];
        }
        else
        {
            cout << this->arr[i] << " ";
        }
    }
    cout << "]";
}

void Dynamic_array::popback(void)
{
    if (this->size == 0 || this->arr == NULL)
    {
        return;
    }
    this->size--;
}

void Dynamic_array::clear()
{
    if (this->arr == NULL)
    {
        return;
    }
    delete this->arr;
    this->size = 0;
    this->arr = NULL;
}

void Dynamic_array::remove(int postion)
{
    try
    {
        for (int i = postion; i < this->size - 1; i++)
        {
            this->arr[i] = this->arr[i + 1];
        }
    }
    catch (std::out_of_range &e)
    {
        std::cerr << e.what() << '\n';
    }
    this->size--;
}

void Dynamic_array::sort(void)
{
    for (int i = 0; i < this->size - 1; i++)
    {
        for (int j = i; j < this->size; j++)
        {
            if (this->arr[i] > this->arr[j])
            {
                double temp = this->arr[i];
                this->arr[i] = this->arr[j];
                this->arr[j] = temp;
            }
        }
    }
}

void Dynamic_array::DuplicateRemove()
{
    this->sort();
    for (int i = 0; i < this->size; i++)
    {
        while (this->arr[i] == this->arr[i + 1])
        {
            for (int j = i; j < this->size; j++)
            {
                this->arr[j] = this->arr[j + 1];
            }
            this->size--;
        }
    }
}
double Dynamic_array::GetMax(void)
{
    double max = this->arr[0];
    if (this->arr == nullptr)
    {
        return -1;
    }
    for (int i = 1; i < this->size; i++)
    {
        if (this->arr[i] > max)
        {
            max = this->arr[i];
        }
    }
    return max;
}
double Dynamic_array::GetMin(void)
{
    double min = this->arr[0];
    if (this->arr == nullptr)
    {
        return -1;
    }
    for (int i = 1; i < this->size; i++)
    {
        if (this->arr[i] < min)
        {
            min = this->arr[i];
        }
    }
    return min;
}
Dynamic_array::~Dynamic_array()
{
    if (this->arr != NULL)
    {
        delete this->arr;
        this->arr = NULL;
    }
}
void DynamicArrayTest()
{
    Dynamic_array test;
    test.pushback(1);
    test.pushback(2);
    test.pushback(3);
    cout << test.GetMax() << endl;
    cout << test.GetMin();
}