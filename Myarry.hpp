#pragma once
#include <iostream>
using namespace std;
//����һ����ģ��
template<class T>
class Myarry
{
public:
    Myarry(int capacity)//�вι���
    {
        this->m_Capacity = capacity;//���뵱ǰ���������
        addr = new T[this->m_Capacity];//���ٶ����ڴ�
        this->m_size = 0;
        
    }

    Myarry(const Myarry & arry)//��������
    {
        this->m_Capacity = arry.m_Capacity;
        this->m_size = arry.m_size;
        this->addr = new T[arry.m_Capacity];//���¿���һ�������ڴ�
        //��arry�е����ݿ�������
        for (int i = 0; i < this->m_size; i++)
        {
            this->addr[i] = arry.addr[i];//��this->addr[i] = arry[i];��ʲô����
        }
    }

    //β��������ֵ
    void tail_insert(const T & value)
    {
        if (this->m_Capacity == this->m_size)//������������
        {
            return;
        }
        this->addr[this->m_size] = value;
        this->m_size++;
    }
    //β��ɾ��
    void tail_delete()
    {
        if (this->m_size == 0)
        {
            return;
        }
        this->m_size--;
    }
    //��һ�ַ�������������
void for_each()
    {
        for (int i = 0; i < this->m_size; i++)
        {
            cout << this->addr[i]<<" ";
        }
        cout << endl;
    }
    //�ڶ��ַ�����ͨ���±귽ʽ���������е�Ԫ��  arr[0] = 100
   /* T& operator[](int index)
    {
        return this->addr[index];
    }*/
    //operator=���죬����ʽ���
    Myarry& operator=(const Myarry & arry)
    {
        //���磬arry1=arry2;��ô���ж�arry1�Ƿ�Ϊ��,�ٽ������
        if (this->addr != NULL)
        {
            delete [] this->addr;
            this->addr = NULL;
            this->m_Capacity = 0;
            this->m_size = 0;
        }
        this->m_Capacity = arry.m_Capacity;
        this->m_size = arry.m_size;
        this->addr = new T[arry.m_Capacity];//���¿���һ�������ڴ�
        //��arry�е����ݿ�������
        for (int i = 0; i < this->m_size; i++)
        {
            this->addr[i] = arry.addr[i];//��this->addr[i] = arry[i];��ʲô����
        }
        return *this;
    }
    //��������
    int Capacity()
    {
        return this->m_Capacity;
    }
    //��ǰ����Ԫ�ظ���
    int size()
    {
        return this->m_size;
    }
    ~Myarry()//��������
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
    T * addr;//ָ������
    int m_size;//�����С������ǰ����ĸ���
    int m_Capacity;//��������
};