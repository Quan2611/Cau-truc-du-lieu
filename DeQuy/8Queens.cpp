#include <iostream>
using namespace std;
char bc[12][12];
int N = 8;
void KhoiTaoBanCo()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            bc[i][j] = '-';
}
void InBanCo()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << bc[i][j] << "  ";
        cout << endl;
    }
}

bool XepDuocHau(int d, int c)
{
    for (int x = 1; x < c; x++)
        if (bc[d - 1][x - 1] == 'H')
            return false;
    for (int x = d - 1, y = c - 1; x >= 1 && y >= 1; x--, y--)
    {
        if (bc[x - 1][y - 1] == 'H')
            return false;
    }
    for (int x = d + 1, y = c - 1; x <= N && y >= 1; x++, y--)
        if (bc[x - 1][y - 1] == 'H')
            return false;
    return true;
}
void XepHau(int c)
{
    if (c > N)
    {
        InBanCo();
        cout << "**********************\n";
    }
    else
    {
        for (int d = 1; d <= N; d++)
        {
            if (XepDuocHau(d, c))
            {
                bc[d - 1][c - 1] = 'H';
                XepHau(c + 1);
                bc[d - 1][c - 1] = '-';
            }
        }
    }
}
int main()
{
    KhoiTaoBanCo();
    XepHau(1);
}