#include<iostream>
#include "Myarry.hpp"
using namespace std;
//����Ԫ�����
int main()
{
    Myarry<int>arry(50);
    for (int i = 0; i < 5; i++)
    {
        arry.tail_insert(i);
    }
   /* for (int i = 0; i < 5; i++)
    {
       cout << arry[i]<<endl;
    }*/
   arry.for_each();
   cout << arry.Capacity() << endl;
   cout << arry.size() << endl;
   //���Կ�������
   Myarry<int>arry1(arry);
   arry1.for_each();
   
//���Ը�ֵ����
   Myarry<int>arry2(20);
   for (int i = 0; i < 10; i++)
   {
       arry2.tail_insert(i);
   }
   arry2.for_each();
   cout << "��ֵǰ������" << arry2.Capacity() << endl;
   cout << "��ֵǰ�Ĵ�С" << arry2.size() << endl;
    arry2= arry1;
    arry2.for_each();
    cout << "��ֵ�������" << arry2.Capacity() << endl;
    cout << "��ֵ��Ĵ�С" << arry2.size() << endl;
    return 0;
}