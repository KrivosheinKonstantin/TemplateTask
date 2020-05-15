using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task1
{
    class Program
    {
        static void Main(string[] args)
        {
            Queue<int> q1 = new Queue<int>(3);
            q1.Push(1);
            q1.Push(10);
            q1.Push(3);
            q1.Print();

            Console.WriteLine("Изъят элемент: " + q1.Pop());
            Console.WriteLine("Изъят элемент: " + q1.Pop());
            q1.Print();

            Queue<int> q4 = new Queue<int>(q1); //инициализация другой очередью
            q4.Print();

            Queue<int> q2 = new Queue<int>(6);
            q2.Push(1); q2.Push(100); q2.Push(5); q2.Push(1); q2.Push(7); q2.Push(2);
            q2.Print();
            Console.WriteLine("Изъят элемент: ");
            Queue<int> q3 = new Queue<int>(q1, q2);//объединение очередей в новую
            q3.Print();
            q3.Pop();
            q3.Print();
            Console.ReadKey();
        }
    }
}