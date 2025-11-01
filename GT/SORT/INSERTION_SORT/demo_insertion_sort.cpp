#include <iostream>
#include <time.h>


using namespace std;

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "   ";
    }
    cout << endl << endl;
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int item = a[i];
        int j;
        for (j = i -1; j >= 0; j--)
        {
            if (a[j] < item)
                break;

            a[j + 1] = a[j];
        }
        a[j + 1] = item;
    }
}

double timeSort(int a[], int n)
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    insertionSort(a, n);


    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}



int main()
{
    int a[] = {79, 39, 26, 66, 55, 20};
    int n = 6;

    printArr(a, n);

    cout << timeSort(a, n) << endl;

    system("pause");
    return 0;
}

