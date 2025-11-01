#include <iostream>

using namespace std;

struct Toado {


};


int main () {
/*     int x, y; // dang tao ra vung nho cho x, y
    
    cout << new int; // in ra dia chi 
    int* p = new int; // cap phat ra 1 vung nho kieu so nguyen

    *p = 6789;

    //Toado* p2 = new Toado;
    int *p2 = new int(1234);
    cout << p2 << endl;
    cout << *p2 << endl; // toan tu * de lay du lieu vung nho  */

    int* p = new int(6789);

    cout << "Dia chi truoc khi thu hoi p= " << p << endl;
    cout << "Gia tri truoc khi thu hoi = " << *p << endl;
    delete p;

    cout << "Dia chi sau khi thu hoi p= " << p << endl;
    cout << "Gia tri sau khi thu hoi = " << *p << endl;
// Dia chi van con luu, nhung gia tri thi khong!.

    system("pause");
    return 0;
}