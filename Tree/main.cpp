#include <iostream>
#include <ctime>
using namespace std;
#include "BinarySearchTree.h"
#include "AVL.h"
int main()
{
    // srand(time(0));
    // cout << "Start ... ";
    // BST<int> l;
    // for (int i = 1; i <= 30000; i++)
    // {
    //     int s = random() % 5000000;
    //     l.Add(s);
    // }
    // int dem = 0;
    // for (int i = 1; i <= 10000; i++)
    // {
    //     int s = random() % 6000000;
    //     if (l.Search(s))
    //         dem++;
    // }
    // cout << dem << endl
    //      << "END!" << endl;

    // BST<int> b;
    // b.Add(10);
    // b.Add(15);
    // b.Add(7);
    // b.Add(9);
    // b.Add(17);
    // b.Add(16);
    // b.Add(5);
    // b.Add(12);
    // b.Add(3);
    // b.Add(2);
    // b.Add(1);

    // cout << b.Search(18) << endl;

    Tree<int> t;
    t.Add(10);
    t.Add(20);
    t.Add(30);
    // t.Add(40);
    // t.Add(50);
    // t.Add(25);
    cout << "Từ trái sang phải được cây như sau: \n";
    t.GetLeftToRight();

    //       30
    //     /    \
//   20      40
    // /    \   /  \
// 10   25     50

    t.Add(40);
    t.Add(50);
    t.Add(25);
    t.Add(9);
    t.Add(2);
    t.GetLeftToRight();
    //         30
    //       /    \
//     20      40
    //   /    \   /  \
//   9   23     50
    // /  \
// 2  10
}