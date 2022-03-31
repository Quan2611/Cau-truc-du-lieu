#include <iostream>
#include <fstream>
using namespace std;
char bc[12][12];
int N = 8;
ofstream fout("8queen.html", ios::app);
void KhoiTaoBanCo()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            bc[i][j] = '-';
}
void InBanCo()
{
    fout << "<table border=\"1\">" << endl;

    for (int i = 0; i < N; i++)
    {
        fout << "<tr>";
        for (int j = 0; j < N; j++)
        {
            if ((i + j) % 2 == 0)
            {
                fout << "<td width=\"40px\" height=\"40px\">";
            }
            else
            {
                fout << "<td width=\"40px\" height=\"40px\" bgcolor=\"green\">";
            }
            if (bc[i][j] == 'H')
            {
                fout << "<img src=\"h.png\" width=\"40px\" height=\"40px\">";
            }
            fout << "</td>";
        }
        fout << "</tr>";
    }
    fout << "</table>";
    fout << "<br/>";
    fout << "<br/>";
    fout << "<br/>";
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
    fout << "<html>";
    fout << "<head>";
    fout << "	<title>8 Queens title</title>";
    fout << "</head>";
    fout << "<body>";
    fout << "<h1>Các bạn không biết xếp 8 con hậu trên 1 bàn cờ sao hãy nhìn các cách dưới đây nhé</h1>";
    KhoiTaoBanCo();
    XepHau(1);
    fout << "</body>";
    fout << "</html>";
    fout.close();
}