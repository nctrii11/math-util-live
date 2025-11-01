#include <iostream>
using namespace std;

void countingSort(int a[], int b[], int k, int n)
{
    int i, j;
    int c[100];
    for (i = 0; i <= k; i++)
    {
        c[i] = 0;
    }

    for (j = 0; j < n; j++)
    {
        c[a[j]]++;
    }

    int idx = 0;
    for (j = 0; j <= k; j++)
    {
        while (c[j] > 0)
        {
            b[idx++] = j;
            c[j]--;
        }
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "   ";
    }
    cout << endl << endl;
}

int main()
{
    int a[6] = {5, 1, 19, 2, 8, 0};
    int n = 6;
    int b[100];

    printArray(a, n);
    countingSort(a, b, 19, n);

    printArray(b, n);

    system("pause");
    return 0;
}