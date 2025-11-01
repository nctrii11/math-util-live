#include <iostream>
using namespace std;

// Buoc1: Dinh nghia Cau truc Node
struct Node
{
    int data;
    Node *pNext;
};

// Buoc3: Dinh nghia Danh sach List
struct List
{
    Node *pHead;
    Node *pTail;
};

void addHead(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
};

void addTail(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
};

void printListFor(List l)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

void printListWhile(List l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << endl;
}

int initDataList(List &l)
{
    // 10   79  39
    Node *p1 = new Node({10, NULL});
    Node *p2 = new Node({79, NULL});
    Node *p3 = new Node({39, NULL});

    addHead(l, p1);
    addTail(l, p2);
    addTail(l, p3);

    addHead(l, new Node({50, NULL}));
    addHead(l, new Node({29, NULL}));

    return 5;
}

/* Yeu cau: Viet ham tim kiem mot gia tri co trong List hay khong?
Input:
    + List l
    + int value
Output:
    + return bool => true la co, false la khong
*/
bool timGiatri(List l, int value)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data == value)
            return true;
    }
    return false;
}

/* Yeu cau: Viet ham tim kiem mot gia tri co trong List hay khong? (Dia chi)
Input:
    + List l
    + int value
Output:
    + return &p
*/
Node *timDiaChi(List l, int value)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data == value)
            return p;
    }
    return NULL;
}

/* Yeu cau: Viet ham tim GTLN
Input:
    + List l
Output:
    + return GTLN
*/
int maxList(List l)
{
    int m = l.pHead->data;

    for (Node *p = l.pHead->pNext; p != NULL; p = p->pNext)
    {
        if (p->data > m)
            m = p->data;
    }
    return m;
}

/* Yeu cau: Viet ham tim so luong so chan
Input:
    + List l
Output:
    + return soluong
*/
int demSoChan(List l)
{
    int dem = 0;

    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if ((p->data) % 2 == 0)
            dem++;
    }
    return dem;
}

/* Yeu cau: Viet ham tinh tong
Input:
    + List l
Output:
    + return tong
*/
int tinhTong(List l)
{
    int tong = 0;
    Node *p = l.pHead;

    while (p != NULL)
    {
        tong += p->data;
        p = p->pNext;
    }
    return tong;
}

/* Yeu cau: Viet ham tim kiem gia tri Node ke cuoi
Input:
    + List l
Output:
    + return gia_tri
*/
int giatriKeCuoi(List l)
{
    int gtKeCuoi;

    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->pNext == l.pTail)
            gtKeCuoi = p->data;
    }
    return gtKeCuoi;
}

int main()
{
    List l = {NULL, NULL};
    //initList(l); // List rong

    cout << "Test: 1. Tao du lieu cho List:" << endl;
    cout << "\t + Ket qua: " << initDataList(l) << endl;

    // cout << "Test: 2. In danh sach:" << endl;
    //  29   40   10    79     39
    /*     printListFor(l);
        printListWhile(l); */

    /* cout << "\nTest: Yeu cau 1. Kiem tra gia tri (bool):" << endl;
    bool kiemtra = timGiatri(l, 11);
    cout << "\t + Tim 11 = " << kiemtra << endl;

    cout << "\nTest: Yeu cau 2. Kiem tra gia tri (Node* ):" << endl;
    Node *diachi = timDiaChi(l, 10);
    cout << "\t + Tim 10 = " << diachi << endl;
 */

    /* cout << "\nTest: Yeu cau 3. Tim GTLN:" << endl;
    int m = maxList(l);
    cout << "\t + Ket qua: GTLN (79) = " << m << endl; */

    /* cout << "\nTest: Yeu cau 4. Tim so luong so chan:" << endl;
    int so_luong = demSoChan(l);
    cout << "\t + So luong so chan (2) = " << so_luong << endl;

    cout << "\nTest: Yeu cau 5. Ting tong:" << endl;
    int tong = tinhTong(l);
    cout << "\t + Tong (197) = " << tong << endl; */

    cout << "\nTest: Yeu cau 6. Tim gia tri ke cuoi:" << endl;
    int keCuoi = giatriKeCuoi(l);
    cout << "\t + Gia tri ke cuoi (79) = " << keCuoi << endl;

    //    delete p1, p2, p3;
    system("pause");
    return 0;
}