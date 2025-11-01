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

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[min_pos]) // < sap xep tang dan, > sap xep giam dan
                min_pos = j;
        }

        if (min_pos != i)
            swap(a[min_pos], a[i]);
    }
}

double timeSort(int a[], int n)
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    selectionSort(a, n);


    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}




int main()
{
    int a[] = {79, 39, 26, 66, 55, 20};
    int n = 6;

    /* printArr(a, n);

    selectionSort(a, n);

    printArr(a, n); */

    cout << timeSort(a, n) << endl;

    system("pause");
    return 0;
}