#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//������������ ��������� ����� ��������� ������.
//���������� ������� ���������� ������, ���������� ����� �������, �������� �������, 
//������ ������ ������, ��������� ������ �������, ������ �� ������.

template<class T>
class BinaryTree
{
private:
	struct Node {
		T data; //�������� ����
		Node* left = nullptr; //��������� �� ����� �����
		Node* right = nullptr; //��������� �� ������ �����
	};
	Node* root;

	void Del_Mem(Node*);//������� ������
	void Add(T, Node*&);//����������
	void Delete(T, Node*&);//��������
	void Show(Node*); //�����
	bool Search(T, Node*);//�����
	void PreOrderTravers(vector<T>&, Node*);//������ ����� ��� ������
	void List(vector<T>&, Node*);//������

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
{ //����������� �. ������� �� �����������
	if (root)
	{
		Del_Mem(root->left);
		Del_Mem(root->right);
		delete root;
	}
}

template<class T>
void BinaryTree<T>::Add(T x)//����������
{
	if (!root)
	{ //���� ������ �������, �������� ������ � �������������� ����������
		root = new Node;
		root->data = x;
	}
	else Add(x, root);
}

template<class T>
void BinaryTree<T>::Add(T x, Node*& root)
{
	if (x < root->data)   //���� ������� ������ ��������� �����
	{
		if (root->left) Add(x, root->left); //���� �������� ����� ������, �� ���� ������
		else          //������� ����� ��� ��������
		{
			root->left = new Node;
			root->left->data = x;
		}
	}

	else if (x > root->data)//���������� ������
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
	if (!root) throw "Error";//������� �� ������
	if (x > root->data) Delete(x, root->right); // ���� ������� � ������ ���������
	else if (x < root->data) Delete(x, root->left);//� �����
	else {

		if (root->right && !root->left) root = root->right;//��� ������� 1 ������� ��������� �� ����
		else if (!root->right && root->left) root = root->left;
		else if (root->right && root->left) {//��� �������
			Node* d = root->right;//�������� ����� ������ ��������� ������ ���������
			while (d->left)
				d = d->left;
			root->data = d->data;
			Delete(d->data, root->right);//����������� �������� �������  ������ �� ������ �������

		}
		else root = nullptr;//��� ��������
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
	if (root)//����� ����� �������
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
	if (!root) return false;//���� ���� => ������� �� ������
	else if (root->data == x) return true;
	else if (root->data > x) return Search(x, root->left);//����� �������� �����
	else return Search(x, root->right);//����� �������� ������
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
	if (!root->left && !root->right)//���� �������� ������
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