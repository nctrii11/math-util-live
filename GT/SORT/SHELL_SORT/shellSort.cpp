#include <iostream>
using namespace std;

void shellSort(int a[], int n)
{
    for (int interval = n / 2; interval > 0; interval /= 2)
    {   
        for (int i = interval; i < n; i++)
        {
            int j = i;
            int value = a[i];

            for ( j = i; j >= interval && a[j - interval] > value; j -= interval)
            {
                a[j] = a[j - interval];
            }
            a[j] = value;
        }
    }
}




int main() {

}