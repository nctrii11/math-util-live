#include <iostream>
using namespace std;

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





