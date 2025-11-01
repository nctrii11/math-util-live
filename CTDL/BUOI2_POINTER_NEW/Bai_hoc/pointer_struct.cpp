#include <iostream>

using namespace std;

struct Diem
{
    int x;
    int y;
};

void inDiem(Diem a)
{
    // A(1; 2)
    cout << "(" << a.x << "; " << a.y << ")" << endl;
}

void inDiemVer2(Diem *a)
{
    cout << "(" << a->x << "; " << a->y << ")" << endl;
}

int main()
{
    /* float x = 3.6;
    cout << x << endl; */

    Diem a = {1, 2};
    Diem *p1 = &a;
    //inDiem(*p1); lay du lieu

    // cout << a.x << endl;
    // inDiem(a);

    Diem b = {2, 1};
    // inDiem(b);

    new float(3.5);

    Diem *p = new Diem;

    //(*p).x = 3; toan tu * di vao vung nho roi sau do dung toan tu (.) de goi
    //(*p).y = 5;

    p->x = 6; // p la dia chi, goi du lieu cua thanh phan ben trong nen dung toan tu mui ten (->)
    p->y = 7;

    inDiem(*p); // du lieu
    inDiemVer2(p); // vung nho

    system("pause");
    return 0;
}
