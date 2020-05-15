using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task1
{
    class Queue<T>
    {
        private int size; // размер очереди
        private T[] Que;
        private int head, tail; //голова и хвост очереди
        public Queue(int item) //создание пустого экземпляра
        {
            if (item >= 0)
            {
                size = item;
                Que = new T[size];
                head = tail = 0;
            }
            else
                throw new ArgumentException();
        }

        public Queue(Queue<T> clone)//копирование
        {
            size = clone.size;
            Que = new T[size];
            head = clone.head;
            tail = clone.tail;
            clone.Que.CopyTo(Que, 0);//копируем элементы clone в que, начиная с 0
        }

        public void Push(T item) //добавление
        {
            if (tail >= size) //очередь заполнена
                throw new IndexOutOfRangeException();
            Que[tail++] = item;
        }

        public T Pop() //изъятие
        {
            if (head == tail) //очередь пуста
                throw new IndexOutOfRangeException();
            return Que[head++];
        }

        public void Print() //вывод очереди
        {
            for (int i = head; i < tail; ++i)
                Console.Write(Que[i] + " ");
            Console.WriteLine();
        }

        public Queue(Queue<T> first, Queue<T> second) //объединение очередей в новую
        {
            size = first.size + second.size;
            Que = new T[size];
            for (int i = first.head; i < first.tail; ++i)//1очередь
                this.Push(first.Que[i]);
            for (int i = second.head; i < second.tail; ++i)//2очередь
                this.Push(second.Que[i]);
        }

    }
}