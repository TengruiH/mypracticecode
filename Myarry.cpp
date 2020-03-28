#include<iostream>
#include "Myarry.hpp"
using namespace std;
//数组元素添加
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
   //测试拷贝构造
   Myarry<int>arry1(arry);
   arry1.for_each();
   
//测试赋值操作
   Myarry<int>arry2(20);
   for (int i = 0; i < 10; i++)
   {
       arry2.tail_insert(i);
   }
   arry2.for_each();
   cout << "赋值前的容量" << arry2.Capacity() << endl;
   cout << "赋值前的大小" << arry2.size() << endl;
    arry2= arry1;
    arry2.for_each();
    cout << "赋值后的容量" << arry2.Capacity() << endl;
    cout << "赋值后的大小" << arry2.size() << endl;
    return 0;
}