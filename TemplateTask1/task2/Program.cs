using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task2
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryTree<int> Tree = new BinaryTree<int>();
            Tree.Add(2); Tree.Add(21); Tree.Add(15); Tree.Add(20); Tree.Add(83); Tree.Add(95);
            Tree.Add(71); Tree.Add(75); Tree.Add(82); Tree.Add(40); Tree.Add(32);

            Tree.Print();

            Console.WriteLine("71 ? " + Tree.Search(71));
            Console.WriteLine("82 ? " + Tree.Search(82));
            Console.WriteLine("3 ? " + Tree.Search(3));

            List<int> Order;
            Console.WriteLine("Обход вершин");
            Order = Tree.PreOrderTravers();
            for (int i = 0; i < Order.Count; ++i)
                Console.Write("{0} ", Order[i]);

            List<int> list;
            Console.WriteLine("\nЛистья");
            list = Tree.List();
            for (int i = 0; i < list.Count; ++i)
                Console.Write("{0} ", list[i]);
            Console.WriteLine();
            Tree.Delete(71);
            Tree.Delete(21);
            Tree.Print();


            Console.ReadKey();
        }
    }
}