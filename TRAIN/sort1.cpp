#include <iostream>
using namespace std;

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_pos])
            {
                min_pos = j;
            }
        }
        if (min_pos != i)
        {
            swap(a[min_pos], a[i]);
        }
    }
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int value = a[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] < value)
                break;

            a[j + 1] = a[j];
        }
        a[j + 1] = value;
    }
}

void quickSort(int a[], int left, int right)
{
    int x = a[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        while (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(a, left, i);
    if (i < right)
        quickSort(a, i, right);
}

void countingSort(int a[], int b[], int k, int n)
{
    int c[100];
    int i, j;
    for (i = 0; i < k; i++)
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

int main()
{
    int a[100] = {20, 9, 1, 25, 8};
    int n = 5;
    int b[100];

    cout << "Mang truoc khi sap xep: " << endl;
    printArray(a, n);

    cout << "Mang sau khi sap xep: " << endl;
    // selectionSort(a, n);
    // insertionSort(a, n);

    // quickSort(a, 0, n);
    countingSort(a, b, 26, n);
    printArray(b, n);

    system("pause");
    return 0;
}