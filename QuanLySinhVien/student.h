#ifndef Student_h
#define Student_h
#include <string.h>
class Student
{
private:
    char msv[100];
    char ht[100];
    char tinh[100];
    char huyen[100];

public:
    Student(){

    };
    const char *GetMaSinhVien() const
    {
        return msv;
    }
    const char *GetHoTen() const
    {
        return ht;
    }
    const char *GetTinh() const
    {
        return tinh;
    }
    const char *GetHuyen() const
    {
        return huyen;
    }
    Student(const char *m, const char *h, const char *t, const char *hu)
    {
        strcpy(msv, m);
        strcpy(ht, h);
        strcpy(tinh, t);
        strcpy(huyen, hu);
    }
    friend ostream &operator<<(ostream &out, const Student &c)
    {
        out << c.msv << "\t" << c.ht << "\t" << c.tinh << "\t" << c.huyen;
        return out;
    }
};
#endif