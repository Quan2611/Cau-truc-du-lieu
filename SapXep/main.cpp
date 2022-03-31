#include <iostream>
#include <fstream>
#include <ctime>
#include <stdio.h>
using namespace std;
int a[11000000];
int b[20000];
int N;
int M;
int dem = 0;

void SapXep(int a[], int N)
{
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            if (a[i] > a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}
void InRa(int a[], int N)
{
    for (int i = 0; i < N; i++)
        cout << a[i] << "; ";
    cout << endl;
}

void SinhDuLieu(int k, const char *FileName)
{
    srand(time(0));
    ofstream fout(FileName);
    fout << k << endl;
    for (int i = 0; i < k; i++)
    {
        int x = rand() % k;
        fout << x << " ";
    }
    fout.close();
}

void GhiFile(int a[], int N, const char *FileName)
{
    ofstream fout(FileName);
    fout << N << endl;
    for (int i = 0; i < N; i++)
    {
        fout << a[i] << " ";
    }
    fout.close();
}

void DocFile(const char *FileName, int &N, int a[])
{
    ifstream fin(FileName);
    fin >> N;
    for (int i = 0; i < N; i++)
    {
        fin >> a[i];
    }
    fin.close();
}

void Merge(int a[], int s, int f)
{
    int m = (s + f) / 2;
    int *b = new int[f - s + 1];
    int ib = 0;
    int l = s, r = m + 1;
    while (l <= m && r <= f)
    {
        if (a[l - 1] < a[r - 1])
        {
            b[ib] = a[l - 1];
            l++;
        }
        else
        {
            b[ib] = a[r - 1];
            r++;
        }
        ib++;
    }
    for (int i = l; i <= m; i++)
    {
        b[ib] = a[i - 1];
        ib++;
    }
    for (int i = r; i <= f; i++)
    {
        b[ib] = a[i - 1];
        ib++;
    }
    for (int i = 0; i < ib; i++)
    {
        a[s - 1 + i] = b[i];
    }
}

void MergeSort(int a[], int s, int f)
{
    int m = (s + f) / 2;
    if (s < f) //cos nhieu hon 1 phan tu
    {
        MergeSort(a, s, m);
        MergeSort(a, m + 1, f);
        Merge(a, s, f);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high]; // pivot
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && a[left] < pivot)
            left++; // Tìm phần tử >= arr[pivot]
        while (right >= left && a[right] > pivot)
            right--; // Tìm phần tử <= arr[pivot]
        if (left >= right)
            break;                   // Đã duyệt xong thì thoát vòng lặp
        swap(&a[left], &arr[right]); // Nếu chưa xong, đổi chỗ.
        left++;                      // Vì left hiện tại đã xét, nên cần tăng
        right--;                     // Vì right hiện tại đã xét, nên cần giảm
    }
    swap(&a[left], &a[high]);
    return left; // Trả về chỉ số sẽ dùng để chia đổi mảng
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(a, low, high);

        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int BinarySearch(int a[], int N, int x) //Tìm kiếm nhị phân
{

    int left = 0;
    int right = N - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
            return mid; // tìm thấy x, trả về mid là vị trí của x trong mảng A
        if (a[mid] > x)
            right = mid - 1; // Giới hạn khoảng tìm kiếm lại là nửa khoảng trước
        else if (a[mid] < x)
            left = mid + 1; // Giới hạn khoảng tìm kiếm lại là nửa khoảng sau
    }
    return -1; // không tìm thấy x
}

int main()
{

    // SinhDuLieu(1000000, "data1tr.txt");
    DocFile("data1tr.txt", N, a);
    // SapXep(a, N);
    MergeSort(a, 1, N);
    GhiFile(a, N, "data1trsx.txt");

    /*cout<<"So phần tử: ";
  cin>>N;

  for(int i = 1; i<= N; i++)
  {
    cout<<"Nhập phần tử thứ "<<i<<": ";
    cin>>a[i-1];
  }*/

    // cout << a[0] << " " << a[N - 1] << endl;

    // SinhDuLieu(20000, "data1.txt");

    // /*cout<<"So phần tử: ";
    //   cin>>N;

    //   for(int i = 1; i<= N; i++)
    //   {
    //     cout<<"Nhập phần tử thứ "<<i<<": ";
    //     cin>>a[i-1];
    //   }*/
    // SapXep(b, M);

    // // cout << b[0] << " " << b[M - 1] << endl;

    // for (int i = 0; i <= 20000; i++)
    // {
    //     if (BinarySearch(b, 20000, a[i]) != -1 /*nếu tìm thấy x*/)
    //     {
    //         dem++;
    //     }
    // }
    // cout << dem << endl;
}