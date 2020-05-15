#include "Queue.h"
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    Queue<int> q1(3);
    q1.Push(1);
    q1.Push(10);
    q1.Push(3);
    q1.Print();

    cout << "Изъят элемент: " << q1.Pop() << endl;
    cout << "Изъят элемент: " << q1.Pop() << endl;
    q1.Print();

    Queue<int> q4(q1);//инициализация другой очередью
    q4.Print();

    Queue<int> q2(6);
    q2.Push(1); q2.Push(100); q2.Push(5); q2.Push(1); q2.Push(7); q2.Push(2);
    q2.Print();

    cout << "-------\n";
    Queue<int> q3(q1,q2);//объединение очередей в новую
    q3.Print();
    q3.Pop();
    q3.Print();
    system("pause");

}

