#include <iostream>
using namespace std;
int a[100];
void SinhXauNhiPhan(int x, int a[], int N)
{
    if (x > N)
    {
        for (int i = 0; i < N; i++)
        {
            if (a[i] < 9)
            {
                cout << a[i];
            }
            else
            {
                cout << char('A' + a[i] - 10);
            }
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i <= 15; i++) // thập lục phân
        {
            a[x - 1] = i;
            SinhXauNhiPhan(x + 1, a, N);
        }
    }
}
int main()
{
    int N;
    cout << "Nhap N = ";
    cin >> N;

    SinhXauNhiPhan(1, a, N);
    return 0;
}