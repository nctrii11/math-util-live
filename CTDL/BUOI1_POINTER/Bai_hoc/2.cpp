#include <iostream>
using namespace std;



int main () {
    int x = 36;

    cout << &x << endl; // phep &: lay dia chi
    
    int* p = &x;
    
    cout << sizeof(int) << endl; // sizeof: lay kich thuoc
    cout << sizeof &x << endl;

    float y = 2.3;

    float* p2 = &y;

    int* p3, p4, p5; // p3 la kieu con tro, p4,p5 la kieu so nguyen



    system("pause");
    return 0;
}