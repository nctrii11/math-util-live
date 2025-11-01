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

void selectionSort(int a[], int n) {
    int min_pos, i, j;
    for ( int i = 0; i < n -1; i++)
    {
        min_pos = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min_pos])
                min_pos = j; //min_pos la vi tri chua gia tri nho nhat 

        swap(a[min_pos], a[i]);
        
    }
}

int main()
{
    int a[] = {79, 39, 26, 66, 55, 20};
    int n = 6;

    printArr(a, n);

    selectionSort(a, n);

    printArr(a, n);

    system("pause");
    return 0;
}

