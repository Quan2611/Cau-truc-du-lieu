#include <iostream>
using namespace std;
#include "list.h"
#include "stack.h"
#include "queue.h"
int main()
{
    Stack<int> s;
    s.push(3);
    s.push(6);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;

    // Queue<string> q;
    // q.EnQueue("Quan");
    // q.EnQueue("Chi");
    // q.EnQueue("HoangAnh");
    // q.EnQueue("Thanh");

    // cout << q.DeQueue() << endl;
    // cout << q.DeQueue() << endl;
}
