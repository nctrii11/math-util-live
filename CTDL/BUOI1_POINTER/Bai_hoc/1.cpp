#include <iostream>
using namespace std;

int main()
{
    int x = 36;

    cout << "Dia chi bien x: " << &x << endl;
    printf("Dia chi cua bien x: %p\n", &x); // %d cho hien thi so nguyen, %f cho so thuc
    printf("Dia chi cua bien x: %x\n", &x); // %x cho he 16
    printf("x = %d\n", x);

    cout << "x = " << *(&x) << endl;

    system("pause");
    return 0;
}