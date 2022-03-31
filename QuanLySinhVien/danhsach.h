#ifndef DB_h
#define DB_h
#include "list.h"
#include "Student.h"
#include <fstream>
using namespace std;

class DanhSach
{
private:
    List<Student> ds;

public:
    DanhSach(){

    };
    void AddStudent(Student c)
    {
        ds.Add(c);
    }
    void DeleteStudent(int pos)
    {
        ds.Delete(pos);
    }
    int Count() const
    {
        return ds.Count();
    }
    Student GetStudent(int pos) const
    {
        return ds.Get(pos);
    }
    void LoadFromFile(const char *fileName)
    {
        ifstream fin(fileName);
        int N;
        fin >> N;
        char t[100];
        fin.getline(t, 100); //đang ở sau số lượng bản ghi, cần xuống dòng
        for (int i = 0; i < N; i++)
        {
            char msv[10], ht[50], tinh[50], huyen[50];
            fin.getline(msv, 100);
            fin.getline(ht, 100);
            fin.getline(tinh, 100);
            fin.getline(huyen, 100);
            ds.Add(Student(msv, ht, tinh, huyen));
        }
        fin.close();
    }
    void SaveToFile(const char *fileName) const
    {
        ofstream fout(fileName);
        fout << ds.Count() << endl;
        for (int i = 1; i <= ds.Count(); i++)
        {
            Student c = ds.Get(i);
            fout << c.GetMaSinhVien() << endl;
            fout << c.GetHoTen() << endl;
            fout << c.GetTinh() << endl;
            fout << c.GetHuyen() << endl;
        }
        fout.close();
    }
    friend ostream &operator<<(ostream &out, const DanhSach &db)
    {
        for (int i = 1; i <= db.ds.Count(); i++)
            out << db.ds.Get(i) << endl;
        return out;
    }
};
#endif