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
    int i, j, min_pos;
    for (i = 0; i < n - 1; i++)
    {
        min_pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min_pos] > a[j])
                min_pos = j;
        }

        if (min_pos != i)
            swap(a[min_pos], a[i]);
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
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        
        if (i <= j)
        {
            swap(a[i], a[j]);// doi cho a[i] va a[j]
            i++; j--;
        }
    }
    if (left < j) quickSort(a, left, j);
    if (i < right) quickSort(a, i, right);
}

void countingSort(int a[], int b[], int k, int n)
{
    int i, j;
    int c[100];
    for (i = 0; i <= k; i++)
        c[i] = 0;
    
    for (j = 0; j < n; j++)
        c[a[j]]++;

    int idx = 0;

    for (int j = 0; j < k; j++)
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
    int a[6] = {5, 1, 19, 2, 8, 0};
    int n = 6;

    printArray(a, n);
    quickSort(a, 0, 5);

    printArray(a, n);

    system("pause");
    return 0;
}
