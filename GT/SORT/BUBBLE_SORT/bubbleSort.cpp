#include <iostream>
using namespace std;

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "   ";
    }
    cout << endl << endl;
}

void swap(int &a, int &b) {
    int c;
    c = a;
    a = b;
    b = c;
}

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
            if(a[j - 1] > a[j]) // xet dieu kieu phan tu sau nho hon
                swap(a[j], a[j - 1]);
    }
}

int main()
{
    int a[] = {79, 39, 26, 66, 55, 20};
    int n = 6;

    printArr(a, n);

    bubbleSort(a, n);

    printArr(a, n);

    system("pause");
    return 0;
}
