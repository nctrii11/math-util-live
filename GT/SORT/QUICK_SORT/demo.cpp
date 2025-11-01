#include <iostream>
using namespace std;
#define MAX 100

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int a[], int left, int right)
{
    int i, j, x;
    x = a[(left + right) / 2];
    i = left; j = right;

    while (i <= j)
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    if (left < j)
        quickSort(a, left, j);
    
    if (i < right)
        quickSort(a, i, right);

}



int main()
{
    


}