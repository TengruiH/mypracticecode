#pragma once
#include <iostream>
using namespace std;
//创建一个类模板
template<class T>
class Myarry
{
public:
    Myarry(int capacity)//有参构造
    {
        this->m_Capacity = capacity;//传入当前对象的容量
        addr = new T[this->m_Capacity];//开辟堆区内存
        this->m_size = 0;
        
    }

    Myarry(const Myarry & arry)//拷贝构造
    {
        this->m_Capacity = arry.m_Capacity;
        this->m_size = arry.m_size;
        this->addr = new T[arry.m_Capacity];//重新开辟一个堆区内存
        //将arry中的数据拷贝过来
        for (int i = 0; i < this->m_size; i++)
        {
            this->addr[i] = arry.addr[i];//与this->addr[i] = arry[i];有什么区别
        }
    }

    //尾部插入数值
    void tail_insert(const T & value)
    {
        if (this->m_Capacity == this->m_size)//数组容量已满
        {
            return;
        }
        this->addr[this->m_size] = value;
        this->m_size++;
    }
    //尾部删除
    void tail_delete()
    {
        if (this->m_size == 0)
        {
            return;
        }
        this->m_size--;
    }
    //第一种方法：遍历数组
void for_each()
    {
        for (int i = 0; i < this->m_size; i++)
        {
            cout << this->addr[i]<<" ";
        }
        cout << endl;
    }
    //第二种方法：通过下标方式访问数组中的元素  arr[0] = 100
   /* T& operator[](int index)
    {
        return this->addr[index];
    }*/
    //operator=构造，用链式编程
    Myarry& operator=(const Myarry & arry)
    {
        //比如，arry1=arry2;那么先判断arry1是否不为空,再进行深拷贝
        if (this->addr != NULL)
        {
            delete [] this->addr;
            this->addr = NULL;
            this->m_Capacity = 0;
            this->m_size = 0;
        }
        this->m_Capacity = arry.m_Capacity;
        this->m_size = arry.m_size;
        this->addr = new T[arry.m_Capacity];//重新开辟一个堆区内存
        //将arry中的数据拷贝过来
        for (int i = 0; i < this->m_size; i++)
        {
            this->addr[i] = arry.addr[i];//与this->addr[i] = arry[i];有什么区别
        }
        return *this;
    }
    //数组容量
    int Capacity()
    {
        return this->m_Capacity;
    }
    //当前数组元素个数
    int size()
    {
        return this->m_size;
    }
    ~Myarry()//析构函数
    {
        if (this->addr != NULL)
        {
            delete [ ] this->addr;
            this->addr = NULL;
            this->m_Capacity = 0;
            this->m_size = 0;
        }
    }

private:
    T * addr;//指向数组
    int m_size;//数组大小。即当前数组的个数
    int m_Capacity;//数组容量
};