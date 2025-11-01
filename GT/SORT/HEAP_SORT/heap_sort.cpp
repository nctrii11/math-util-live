#include <iostream>
using namespace std;


void shift(int a[], int i, int n)
{
    int j = 2 * i + 1;
    if (j >= n) // neu vi tri j khong ton tai trong danh sach thi thoat khoi chuong trinh
        return;
    
    if (j + 1 < n) // neu ton tai vi tri j+1 trong danh sach dang xet
        if (a[j] < a[j + 1]) // neu vi tri j ton tai phan tu a[j] < a[j+1]
            j++; // luu vi tri phan tu lon hon trong hai phan tu la vi tri j

    if (a[i] >= a[j]) // xet a[i] la phan tu lon nhat        
        return; // thoat chuong trinh
    
    else       // a[i] khong phai la phan tu lon nhat
    {          // hoan vi a[i] voi phan tu lon nhat max(a[2*i+1], a[2*i+2])
        int x = a[i];
        a[i] = a[j];
        a[j] = x;
    
        shift(a, j, n); // xet tinh lan truyen tai vi tri phan tu vua hoan doi 
    }
}




void heapSort(int a[], int n)
{
    int i = n / 2 - 1;
    while(i >= 0) // tao heap ban dau
    {
        shift(a, i, n);
        i--;
    }
    int right = n - 1; // right la vi tri cuoi Heap dang xet
    while(right > 0)
    {
        swap(a[0], a[right]); // hoan vi phan tu a[0] cho phan tu cuoi Heap dang xet
        right--; // gioi han lai phan tu cuoi dang xet
        if(right > 0) // kiem tra lai day dang xet con nhieu hon 1 pt
            shift(a, 0, right); // tao heap chen lai tai vi tri 0
    }
}



int main()
{





    system("pause");
    return 0;
}



