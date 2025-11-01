#include <iostream>
using namespace std;

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "   ";
    }
    cout << endl
         << endl;
}

void insertionSort(int a[], int n)
{
    int x, i, j;
    for (int i = 1; i < n; i++)
    {
        x = a[i];
        j = i - 1;
        while (0 <= j && x < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

int main()
{
    int a[] = {79, 39, 26, 66, 55, 20};
    int n = 6;

    printArr(a, n);

    insertionSort(a, n);

    printArr(a, n);

    system("pause");
    return 0;
}
