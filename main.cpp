#include <iostream>
#include "DanhSachLienKetDon.h"
using namespace std;

int main()
{
    List<int> a;
    a.Add(5);
    a.Add(6);
    a.Add(7);
    a.Add(88);
    for (int i = 1; i <= a.Count(); i++)
        cout << a.GetItem(i) << " ; ";
    cout << "\n-----------\n";

    a.Delete(3);
    cout << a << endl;

    a.Insert(10, 4);
    a.Insert(15, 2);
    //a.Insert(15,3);
    a.Insert(10, 3);
    //a.Update(3,5);
    cout << a << endl;

    a.Update(66, 1);
    a.Update(4, 3);
    cout << a << endl;

    cout << "So bien bang: " << a.Count(15) << endl;

    cout << "So bien bang: " << a.Count(15, 1, 4) << endl;

    List<int> b(10, 100);
    for (int i = 1; i <= b.Count(); i++)
        cout << b.GetItem(i) << " ; ";
    cout << "\n-----------\n";

    List<int> r;
    r = a.GetListPos(10);
    cout << "Vi Tri =" << r << endl;

    List<int> v;
    v = a.GetSubList(2, 4);
    cout << v << endl;

    List<int> i;
    i = a.Inverse();
    cout << i << endl;

    List<int> n;
    n = a.Inverse(2, 4);
    cout << n << endl;

    // List<int> h;
    // h=a.Giao(b);
    // cout<<h<<endl;
}