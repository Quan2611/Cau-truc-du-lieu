#include <iostream>
#include "danhba.h"
#include "mylib.h"
using namespace std;
danhba ds[1000];
int N = 0;
int main()
{
    NapDuLieuTuFile("dulieu.db", ds, N);
    int chon;
    do
    {
        chon = ThucDon();
        switch (chon)
        {
        case 1:
            ThemDanhBa(ds, N);
            break;
        case 2:
            HienThiDanhBa(ds, N);
            break;
        case 3:
            Update(ds, N);
            break;
        case 4:
            Delete(ds, N);
            break;
        case 0:
            cout << "Cam on ban da su dung chuong trinh\n";
            break;
        };
    } while (chon != 0);
    LuuDuLieu("dulieu.db", ds, N);
}