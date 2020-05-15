#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Разработайте шаблонный класс бинарного дерева.
//Реализуйте функции построения дерева, добавления новой вершины, удаления вершины, 
//обхода вершин дерева, получения списка листьев, поиска по дереву.

template<class T>
class BinaryTree
{
private:
	struct Node {
		T data; //значение узла
		Node* left = nullptr; //указатель на левое звено
		Node* right = nullptr; //указатель на правое звено
	};
	Node* root;

	void Del_Mem(Node*);//очистка памяти
	void Add(T, Node*&);//добавление
	void Delete(T, Node*&);//удаление
	void Show(Node*); //вывод
	bool Search(T, Node*);//поиск
	void PreOrderTravers(vector<T>&, Node*);//Прямой обход бин дерева
	void List(vector<T>&, Node*);//листья

public:
	BinaryTree() { root = nullptr; }
	~BinaryTree() {
		if (root) {
			Del_Mem(root);
		}
	}
	void Add(T);
	void Delete(T);
	void Print();
	bool Search(T);
	vector<T> PreOrderTravers();
	vector<T> List();
};

template<class T>
void BinaryTree<T>::Del_Mem(Node* root)
{ //рекурсивная ф. прохода по поддеревьям
	if (root)
	{
		Del_Mem(root->left);
		Del_Mem(root->right);
		delete root;
	}
}

template<class T>
void BinaryTree<T>::Add(T x)//добавление
{
	if (!root)
	{ //если первый элемент, выделяем память и инициализируем переменные
		root = new Node;
		root->data = x;
	}
	else Add(x, root);
}

template<class T>
void BinaryTree<T>::Add(T x, Node*& root)
{
	if (x < root->data)   //если элемент меньше добавляем влево
	{
		if (root->left) Add(x, root->left); //если дочерние места заняты, то идем дальше
		else          //Найдено место для элемента
		{
			root->left = new Node;
			root->left->data = x;
		}
	}

	else if (x > root->data)//записываем вправо
	{
		if (root->right) Add(x, root->right);
		else
		{
			root->right = new Node;
			root->right->data = x;
		}
	}
	else throw "Error";
}

template<class T>
void BinaryTree<T>::Delete(T x)
{
	Delete(x, root);
}

template<class T>
void BinaryTree<T>::Delete(T x, Node*& root)
{
	if (!root) throw "Error";//элемент не найден
	if (x > root->data) Delete(x, root->right); // ищем элемент в правом поддереве
	else if (x < root->data) Delete(x, root->left);//в левом
	else {

		if (root->right && !root->left) root = root->right;//при наличии 1 потомка ссылаемся на него
		else if (!root->right && root->left) root = root->left;
		else if (root->right && root->left) {//два потомка
			Node* d = root->right;//заменяем самым правым элементом левого поддерева
			while (d->left)
				d = d->left;
			root->data = d->data;
			Delete(d->data, root->right);//аналогичным способом удаляем  взятый на замену элемент

		}
		else root = nullptr;//нет потомков
	}
}

template<class T>
void BinaryTree<T>::Print()
{
	Show(root); cout << endl;
}

template<class T>
void BinaryTree<T>::Show(Node* root)
{
	if (root)//вывод слева направо
	{
		cout << root->data << " ";
		Show(root->left);
		//cout << root->data << "\t";
		Show(root->right);
	}
}

template<class T>
bool BinaryTree<T>::Search(T x, Node* root)
{
	if (!root) return false;//узел пуст => элемент не найден
	else if (root->data == x) return true;
	else if (root->data > x) return Search(x, root->left);//поиск элемента слева
	else return Search(x, root->right);//поиск элемента справа
}

template<class T>
bool BinaryTree<T>::Search(T x)
{
	return Search(x, root);
}

template<class T>
vector<T> BinaryTree<T>::PreOrderTravers()
{
	if (root)
	{
		vector<T> out;
		PreOrderTravers(out, this->root);
		return out;
	}
	else throw "Error";
}

template<class T>
void BinaryTree<T>::PreOrderTravers(vector<T>& out, Node* root)
{
	if (root) {
		out.push_back(root->data);
		//cout << root->data << " ";
		PreOrderTravers(out, root->left);
		PreOrderTravers(out, root->right);

	}
}

template<class T>
void BinaryTree<T>::List(vector<T>& out, Node* root)
{
	if (!root->left && !root->right)//если является листом
		out.push_back(root->data);
	else {
		if (root->left) List(out, root->left);
		if (root->right) List(out, root->right);
	}
}

template<class T>
vector<T> BinaryTree<T>::List()
{
	if (root) {
		vector<T> out;
		List(out, this->root);
		return out;
	}
	else throw "Error";
}