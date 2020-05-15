#pragma once
#include <iostream>
using namespace std;

template<class T>
class Queue
{
private:
	int size; //размер очереди
	int head, tail; //голова и хвост очереди
	T* arr;
public:
	Queue(int item) //создание пустого экземпляра
	{
		if (item >= 0)
		{
			this->size = item;
			this->arr = new T[this->size];
			this->head = 0;
			this->tail = 0;
		}
		else throw "Error";
	}
	Queue(const Queue<T>& clone) //Копирование
	{
		this->size = clone.size;
		this->head = clone.head;
		this->arr = new T[this->size];
		this->arr = clone.arr;
		this->tail = clone.tail;
	}
	~Queue() { }
	void Push(T item)//добавление
	{
		if (this->tail >= this->size) throw "Error";//очередь заполнена
		arr[this->tail++] = item;
	}
	T Pop()//изъятие
	{
		if (this->head == this->tail) throw "Error";//очередь пуста
		return arr[head++];
	}
	void Print()//вывод очереди
	{
		for (int i = this->head; i < this->tail; ++i)
			cout << this->arr[i] << " ";
		cout << endl;
	}

	Queue(const Queue<T>& first,const Queue<T>& second)//объединение очередей в новую
	{
		
		size = first.size + second.size;
		arr = new T[size];
		head = tail = 0;
		for (int i = first.head; i < first.tail; ++i)//1очередь
			this->Push(first.arr[i]);
		for (int i = second.head; i < second.tail; ++i)//2очередь
			this->Push(second.arr[i]);
	}
};

