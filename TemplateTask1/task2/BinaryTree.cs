using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task2
{
    //    Разработайте generic-класс бинарного дерева.Реализуйте функции построения
    //дерева, добавления новой вершины, удаления вершины, обхода вершин дерева,
    //получения списка листьев, поиска по дереву.
    class BinaryTree<T> where T : IComparable<T>
    {
        class Node
        {
            public T data;//значение узла
            public Node left; //левое звено
            public Node right;//правое звено

            public Node(T _data)
            {
                left = right = null;
                data = _data;
            }
        }

        Node root;
        public BinaryTree() { root = null; }
        public void Add(T _data) //добавление
        {
            if (root == null) //если 1элемент дерева
                root = new Node(_data);
            else
                Add(_data, ref root);
        }
        private void Add(T _data, ref Node root)
        {
            if (_data.CompareTo(root.data) < 0) //если элемент меньше добавляем влево
            {
                if (root.left != null)  //если дочерние места заняты, то идем дальше
                    Add(_data, ref root.left);
                else//Найдено место для элемента
                    root.left = new Node(_data);
            }
            else if (_data.CompareTo(root.data) > 0)//записываем вправо
            {
                if (root.right != null)
                    Add(_data, ref root.right);
                else
                    root.right = new Node(_data);
            }
            else throw new ArgumentException();
        }
        public void Delete(T _data)//удаление
        {
            Delete(_data, ref root);
        }
        private void Delete(T _data, ref Node root)
        {
            if (root == null) throw new ArgumentException();
            else if (_data.CompareTo(root.data) > 0) Delete(_data, ref root.right);//ищем элемент в правом поддереве
            else if (_data.CompareTo(root.data) < 0) Delete(_data, ref root.left); //в левом
            else
            {
                if (root.right != null && root.left == null) root = root.right;//при наличии только правого потомка ссылаемся на него
                else if (root.right == null && root.left != null) root = root.left;//при наличии только левого потомка ссылаемся на него
                else if (root.right != null && root.left != null)
                {//два потомка. Заменяем самым правым элементом левого поддерева
                    Node d = root.right;
                    while (d.left != null)
                        d = d.left;
                    root.data = d.data;
                    Delete(d.data, ref root.right);//аналогичным способом удаляем  взятый на замену элемент
                }
                else root = null;//нет потомков

            }
        }
        public void Print() //вывод
        {
            Show(ref root);
            Console.WriteLine();
        }
        private void Show(ref Node root)
        {
            if (root != null)
            {//вывод сверху вниз
                Console.Write(root.data + " ");
                Show(ref root.left);
                // Console.Write(root.data + "\t");
                Show(ref root.right);
            }
        }

        public bool Search(T _data)//поиск
        {
            return Search(_data, ref root);
        }
        private bool Search(T _data, ref Node root)
        {
            if (root == null) return false; //узел пуст => элемент не найден
            else if (_data.CompareTo(root.data) == 0)
                return true;
            else if (_data.CompareTo(root.data) > 0)//поиск элемента справа
                return Search(_data, ref root.right);
            else
                return Search(_data, ref root.left);//поиск элемента слева

        }
        public List<T> PreOrderTravers()//Прямой обход бин дерева
        {
            if (root != null)
            {
                List<T> ou = new List<T>();
                PreOrderTravers(ou, ref this.root);
                return ou;
            }
            else throw new Exception();
        }

        private void PreOrderTravers(List<T> ou, ref Node root)
        {
            if (root != null)
            {
                ou.Add(root.data);
                PreOrderTravers(ou, ref root.left);
                PreOrderTravers(ou, ref root.right);
            }
        }
        public List<T> List()//листья
        {
            if (root != null)
            {
                List<T> ou = new List<T>();
                List(ou, ref this.root);
                return ou;
            }
            else throw new Exception();
        }

        private void List(List<T> ou, ref Node root)
        {
            if (root.left == null && root.right == null)// если является листом
                ou.Add(root.data);
            else
            { //если есть потомки
                if (root.left != null)
                    List(ou, ref root.left);
                if (root.right != null)
                    List(ou, ref root.right);
            }
        }
    }
}