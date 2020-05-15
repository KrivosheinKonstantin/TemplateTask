#pragma once
#include <iostream>
using namespace std;

template<class T>
class Queue
{
private:
	int size; //������ �������
	int head, tail; //������ � ����� �������
	T* arr;
public:
	Queue(int item) //�������� ������� ����������
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
	Queue(const Queue<T>& clone) //�����������
	{
		this->size = clone.size;
		this->head = clone.head;
		this->arr = new T[this->size];
		this->arr = clone.arr;
		this->tail = clone.tail;
	}
	~Queue() { }
	void Push(T item)//����������
	{
		if (this->tail >= this->size) throw "Error";//������� ���������
		arr[this->tail++] = item;
	}
	T Pop()//�������
	{
		if (this->head == this->tail) throw "Error";//������� �����
		return arr[head++];
	}
	void Print()//����� �������
	{
		for (int i = this->head; i < this->tail; ++i)
			cout << this->arr[i] << " ";
		cout << endl;
	}

	Queue(const Queue<T>& first,const Queue<T>& second)//����������� �������� � �����
	{
		
		size = first.size + second.size;
		arr = new T[size];
		head = tail = 0;
		for (int i = first.head; i < first.tail; ++i)//1�������
			this->Push(first.arr[i]);
		for (int i = second.head; i < second.tail; ++i)//2�������
			this->Push(second.arr[i]);
	}
};

