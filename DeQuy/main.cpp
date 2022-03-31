#include <iostream>
using namespace std;
void F(int a)
{
    if (a >= 1)
    {
        cout << "Hello\n";
        F(a - 1);
    }
}

/*int GiaiThua(int N)
{
  int t = 1;
  for(int i = 1; i<= N; i++)
    t = t * i;
  return t;
}*/
int GiaiThua(int N)
{
    if (N == 0 || N == 1)
        return 1;
    return N * GiaiThua(N - 1);
}
int HaiMu(int n)
{
    if (n == 0)
        return 1;
    return 2 * HaiMu(n - 1);
}
int Fibonaci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return Fibonaci(n - 1) + Fibonaci(n - 2);
}
void ThapHaNoi(int N, char c1, char c2, char c3)
{
    if (N == 1)
    {
        cout << c1 << " -->" << c3 << endl;
    }
    else
    {
        ThapHaNoi(N - 1, c1, c3, c2);
        ThapHaNoi(1, c1, c2, c3);
        ThapHaNoi(N - 1, c2, c1, c3);
    }
}

int main()
{
    // int N = 5;
    // cout << N << "! = " << GiaiThua(N) << endl;
    // cout << HaiMu(6) << endl;
    // cout << Fibonaci(2) << endl;
    // cout << Fibonaci(3) << endl;
    // cout << Fibonaci(4) << endl;
    // cout << Fibonaci(6) << endl;
    int N;
    cout << "Nhap n = ";
    cin >> N;
    ThapHaNoi(N, '1', '2', '3');
}