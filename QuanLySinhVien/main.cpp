#include <iostream>
using namespace std;
#include "danhsach.h"
#include "student.h"
#include <string.h>
DanhSach s;
#include "mylib.h"
int main()
{
    s.LoadFromFile("dssv.dat"); //Đọc dữ liệu đã có từ file dulieu.db
    int chon;
    do
    {
        chon = ThucDon();
        switch (chon)
        {
        case 1:
            ThemMoi();
            break;
        case 2:
            HienThiTatCa();
            break;
        case 3:
            CapNhatThongTin();
            break;
        case 0:
            cout << "Cam on ban da su dung chuong trinh\n";
            break;
        }
        char ch;
        cout << "Nhan phim bat ky roi enter de tiep tuc\n";
        cin >> ch;
        system("clear");
    } while (chon != 0);
    s.SaveToFile("dssv.dat");
}