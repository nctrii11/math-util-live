#include <iostream>
using namespace std;


int main () 
{       //index   0  1  2  3  4
    int a[100] = {5, 8, 9, 1, 6};
    int n = 5;

    cout << a << endl;


    for (int i = 0; i < n; i++) 
    {
        cout << a[i] << " " << &a[i] << endl;
    }

    cout << endl << endl;
    for (int i = 0; i < n; i++) // a la dia chi cua phan tu dau tien tuc la a[0]
    {
        cout << *(a + i) << endl;
    }






    system("pause");
    return 0;
}