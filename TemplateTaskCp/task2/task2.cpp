// 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"BinaryTree.h"
#include <string>

int main()
{
    setlocale(LC_ALL, "Russian");
    BinaryTree<int> Tree;
    Tree.Add(2); Tree.Add(21); Tree.Add(15); Tree.Add(20); Tree.Add(83); Tree.Add(95);
    Tree.Add(71); Tree.Add(75); Tree.Add(82); Tree.Add(40); Tree.Add(32);
    Tree.Print();

    cout << "71 ? " << Tree.Search(71) <<
        "\n82 ? " << Tree.Search(82) << 
        "\n3 ? " << Tree.Search(3) << endl;

    cout << "Обход" << endl;
    vector <int> q1 = Tree.PreOrderTravers();
    for (int i = 0; i < q1.size(); ++i)
        cout << q1[i] << " ";
    cout << endl;

    cout << "\nЛистья" << endl;
    vector <int> q2 = Tree.List();
    for (int i = 0; i < q2.size(); ++i)
        cout << q2[i] << " ";
    cout << endl;
    Tree.Delete(71);
    Tree.Delete(21);
    Tree.Print();
    system("pause");
    return 0;
}