#ifndef mylib_h
#define mylib_h
#include <fstream>
#include "danhba.h"
#include <iostream>
using namespace std;
int ThucDon()
{
    cout << "CHUONG TRINH QUAN LY DANH BA\n";
    cout << "1. Them danh ba\n";
    cout << "2. Danh sach danh ba\n";
    cout << "3. Cap nhat thong tin danh ba\n";
    cout << "4. Xoa thong tin danh ba\n";
    cout << "0. Thoat\n";
    int chon;
    cout << "Moi ban nhap chuc nang:\n";
    cin >> chon;
    return chon;
}
void ThemDanhBa(danhba ds[], int &N)
{
    string ht, sdt, e;
    cout << "Nhap thong tin danh ba: " << endl;
    cout << "Nhap ho va ten: " << endl;
    cin.ignore();
    cin.getline(ht, 50);
    cout << "Nhap so dien thoai: " << endl;
    getline(cin, sdt);
    cout << "Nhap email: " << endl;
    getline(cin, e);
    ds[N].HoTen = ht;
    ds[N].SDT = sdt;
    ds[N].Email = e;
    N++;
}
void HienThiDanhBa(danhba ds[], int N)
{
    cout << "Danh sach danh ba la: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << "\t" << ds[i].HoTen << "\t" << ds[i].SDT << "\t" << ds[i].Email << endl;
    }
}

void Update(danhba ds[], int N)
{
    int tt;
    cout << "Nhap so thu tu danh ba ban can cap nhat: " << endl;
    cin >> tt;
    string ht, sdt, e;
    cout << "Nhap thong tin danh ba moi: " << endl;
    cin.ignore();
    cout << "Nhap ho ten moi: " << endl;
    getline(cin, ht);
    cin.ignore();
    cout << "Nhap so dien thoai moi: " << endl;
    getline(cin, sdt);
    cin.ignore();
    cout << "Nhap email moi: " << endl;
    getline(cin, e);
    ds[tt - 1].HoTen = ht;
    ds[tt - 1].SDT = sdt;
    ds[tt - 1].Email = e;
}

void Delete(danhba ds[], int N)
{
    string ht;
    cout << "Nhap ten danh ba muon xoa: " << endl;
    cin.ignore();
    getline(cin, ht);
    int x = -1;
    for (int i = 0; i < N; i++)
    {
        if (ds[i].HoTen == ht)
        {
            x = i;
            break;
        }
    }
    for (int i = x; i < N - 1; i++)
    {
        ds[i] = ds[i + 1];
    }
    N -= 1;
    cout << "Da xoa thanh cong!!!" << endl;
}

void NapDuLieuTuFile(const char *fileName, danhba ds[], int &N)
{
    ifstream fin(fileName);
    fin >> N;
    for (int i = 0; i < N; i++)
    {
        string ht;
        string sdt;
        string e;
        fin.ignore();
        getline(fin, ht);
        getline(fin, sdt);
        getline(fin, e);
        ds[i].HoTen = ht;
        ds[i].SDT = sdt;
        ds[i].Email = e;
    }
    fin.close();
}
void LuuDuLieu(string fileName, danhba ds[], int N)
{
    ofstream fout(fileName);
    fout << N << endl;
    for (int i = 0; i < N; i++)
    {
        fout << ds[i].HoTen << endl;
        fout << ds[i].SDT << endl;
        fout << ds[i].Email << endl;
    }

    fout.close();
}

#endif