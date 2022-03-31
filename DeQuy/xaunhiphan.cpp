#include <iostream>
using namespace std;
int a[100];
void SinhXauNhiPhan(int x, int a[], int N)
{
    if (x > N)
    {
        for (int i = 0; i < N; i++)
        {
            cout << a[i];
        }
        cout << endl;
    }
    else
    {

        //     // a[x - 1] = 0;
        //     // SinhXauNhiPhan(x + 1, a, N);
        //     // a[x - 1] = 1;
        //     // SinhXauNhiPhan(x + 1, a, N);
        for (int i = 0; i <= 1; i++) // nhị phân
        {
            a[x - 1] = i;
            SinhXauNhiPhan(x + 1, a, N);
        }

        //     for (int i = 0; i <= 2; i++) // tam phân
        //     {
        //         a[x - 1] = i;
        //         SinhXauNhiPhan(x + 1, a, N);
        //     }

        //     for (int i = 0; i <= 7; i++) // bát phân
        //     {
        //         a[x - 1] = i;
        //         SinhXauNhiPhan(x + 1, a, N);
        //     }

        //     for (int i = 0; i <= 9; i++) // thập phân
        //     {
        //         a[x - 1] = i;
        //         SinhXauNhiPhan(x + 1, a, N);
        //     }
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