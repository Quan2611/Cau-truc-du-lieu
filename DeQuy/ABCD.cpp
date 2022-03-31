#include <iostream>
using namespace std;
char a[100];
void SinhXauChuCai(int x, char a[], int N)
{
    if (x > N)
    {
        for (int i = 0; i < N; i++)
            cout << a[i];
        cout << endl;
    }
    else
    {
        for (char i = 'A'; i <= 'D'; i++)
        {
            a[x - 1] = i;
            SinhXauChuCai(x + 1, a, N);
        }
    }
}
int main()
{
    int N;
    cout << "Nhap N:";
    cin >> N;
    SinhXauChuCai(1, a, N);
    return 0;
}