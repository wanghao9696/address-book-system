#pragma once
#include<iostream>

using namespace std;

template<class T>
class MyArray
{
public:
    // 构造函数实现
    MyArray(int capacity)
    {
        this->m_Capacity = capacity;
        this->m_Size = 0;
        pAddress = new T[this->m_Capacity];
    }

    // 拷贝构造函数实现
    MyArray(const MyArray & arr)
    {
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
        
        for(int i=0; i<this->m_Size; i++)
        {
            // 如果T尾对象，而且还包含指针，必须需要重载 "=" 操作符，因为这个等号不是 构造， 而是赋值
            // 普通类型可以直接 = ，但是指针类型需要深拷贝
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // 重载“=”操作符  防止浅拷贝问题
    MyArray & operator=(const MyArray & myarray)
    {
        if(this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        this->m_Capacity = myarray.m_Capacity;
        this->m_Size = myarray.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for(int i=0; i<this->m_Size; i++)
        {
            this->pAddress[i] = myarray[i];
        }
        return *this;
    }

    // 重载[]操作符 arr[0]
    T & operator[](int index)
    {
        return this->pAddress[index];
    }

    // 尾插法实现
    void push_Back(const T & val)
    {
        if(this->m_Capacity == this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    // 尾删法实现
    void pop_Back()
    {
        if(this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;
    }

    // 获取数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    // 获取数组大小
    int getSize()
    {
        return this->m_Size;
    }

    // 析构函数实现
    ~MyArray()
    {
        if(this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
    }

    
private:
    T * pAddress; // 指向一个堆空间，这个空间存储真正的数据
    int m_Capacity; // 容量
    int m_Size; // 大小
};