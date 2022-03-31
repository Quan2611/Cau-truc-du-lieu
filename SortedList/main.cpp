#include <iostream>
using namespace std;
#include <string>
using namespace std;
template <class T>
class SortedList
{
private:
    T a[1000];
    int size;

public:
    SortedList()
    {
        size = 0;
    }
    void Add(T so)
    {
        a[size++] = so;
        SelectionSort();
    }
    void swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
    void SelectionSort()
    {
        int vt_min;
        for (int i = 0; i < size; i++)
        {
            vt_min = i;
            for (int j = i + 1; j < size; j++)
            {
                if (a[j] < a[vt_min])
                {
                    vt_min = j;
                }
            }
            swap(a[i], a[vt_min]);
        }
    }
    void Delete(int vt)
    {
        for (int i = vt - 1; i < size - 1; i++)
        {
            a[i] = a[i + 1];
        }
        size--;
    }
    void Insert(T value, int vt)
    {
        size++;
        for (int i = vt - 1; i < size - 1; i++)
        {
            a[i] = a[i + 1];
        }
    }
    friend ostream &operator<<(ostream &out, SortedList<T> ok)
    {
        for (int i = 0; i < ok.size; i++)
        {
            out << ok.a[i] << "; ";
        }
        out << endl;
        return out;
    }
    int Size() const
    {
        return size;
    }
    T GetItem(int vt)
    {
        return a[vt - 1];
    }
};
int main()
{
    SortedList<float> ds; //Danh sách sắp xếp tăng dần
    ds.Add(8);
    ds.Add(9);
    ds.Add(8.5);
    ds.Add(5);
    ds.Add(7);

    cout << ds << endl;
    cout << ds.GetItem(1) << endl; //in ra 5
}