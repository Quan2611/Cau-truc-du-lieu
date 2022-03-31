#include <iostream>
using namespace std;
#include "student.h"

int ThucDon()
{
    cout << "\t\t\tCHUONG TRINH QUAN LY SINH VIEN\n";
    cout << "\t1. Them moi\n";
    cout << "\t2. Hien thi tat ca sinh vien\n";
    cout << "\t3. Cap nhat thong tin\n";
    cout << "\t4. Tim sinh vien theo tinh\n";
    cout << "\t0. Thoat\n";
    cout << "Moi chon chuc nang: ";
    int chon;
    cin >> chon;
    return chon;
}
void ThemMoi()
{
    char msv[10], ht[50], tinh[50], huyen[50];
    cout << "Nhap cac thong tin sau de them moi\n";
    cout << "Nhap ma sinh vien: ";
    cin.ignore();
    cin.getline(msv, 10);
    cout << "Nhap ho ten: ";
    cin.getline(ht, 50);
    cout << "Nhap tinh: ";
    cin.getline(tinh, 50);
    cout << "Nhap huyen ";
    cin.getline(huyen, 50);
    s.AddStudent(Student(msv, ht, tinh, huyen));
    cout << "Hoan thanh them mot sinh vien\n";
}
void HienThiTatCa()
{
    cout << "sinh vien\n";
    for (int i = 1; i <= s.Count(); i++)
    {
        Student c = s.GetStudent(i);
        cout << "\tStudent thu " << i << ": \n";
        cout << "\tMa sinh vien: " << c.GetMaSinhVien() << endl;
        cout << "\tHo ten      : " << c.GetHoTen() << endl;
        cout << "\tTinh        : " << c.GetTinh() << endl;
        cout << "\ttHuyen      : " << c.GetHuyen() << endl;
    }
}

void CapNhatThongTin()
{
    char msv[10], ht[50], tinh[50], huyen[50];
    cout << "Nhap cac thong tin sau de them moi\n";
    cout << "Nhap ma sinh vien moi: ";
    cin.ignore();
    cin.getline(msv, 10);
    cout << "Nhap ho ten moi: ";
    cin.getline(ht, 50);
    cout << "Nhap tinh moi: ";
    cin.getline(tinh, 50);
    cout << "Nhap huyen moi:";
    cin.getline(huyen, 50);
    s.AddStudent(Student(msv, ht, tinh, huyen));
    cout << "Hoan thanh them mot sinh vien\n";
}
void TimSinhVienTheoTen()
{
    char tk[10];
    cout << "Moi nhap ten can tim: ";
    cin.ignore();
    cin.getline(tk, 50);
    for (int i = 1; i <= s.Count(); i++)
    {
        Student c = s.GetStudent(i);
        if (strcmp(c.GetHoTen(), tk) == 0)
        {
            cout << "\tStudent thu " << i << ": \n";
            cout << "\tMa sinh vien: " << c.GetMaSinhVien() << endl;
            cout << "\tHo ten      : " << c.GetHoTen() << endl;
            cout << "\tTinh        : " << c.GetTinh() << endl;
            cout << "\ttHuyen      : " << c.GetHuyen() << endl;
        }
    }
}
