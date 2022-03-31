#include <iostream>
using namespace std;
template <class T>
class Queue
{
private:
    T a[100];
    int N;

public:
    Queue()
    {
        N = 0;
    }
    void EnQueue(T value)
    {
        a[N++] = value;
    };
    T DeQueue()
    {
        T value = a[0];
        for (int i = 0; i < N; i++)
        {
            a[i] = a[i + 1];
        }
        N--;
        return value;
    };
    T GetTail() const
    {
        return a[N - 1];
    }
    bool IsEmpty() const
    {
        return N == 0;
    };
};

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Queue<int> b;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 1)
        {
            b.EnQueue(a[i]);
        }
    }
    while (!b.IsEmpty())
    {
        cout << b.DeQueue() << " ";
    }
}