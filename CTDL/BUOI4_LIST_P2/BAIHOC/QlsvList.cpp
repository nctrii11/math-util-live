#include <iostream>

using namespace std;

struct SinhVien
{
    int maSV;
    string hoTen; // char hoT[30]; //char *ht;
    float diemTB;
    string xepLoai;
};

void printSV(SinhVien sv)
{
    printf("|%5d, %15s, %4.2f, %10s|\n", sv.maSV, sv.hoTen.c_str(), sv.diemTB, sv.xepLoai.c_str());
}

// Buoc1: Dinh nghia Cau truc Node
struct Node
{
    SinhVien data;
    Node *pNext;
};

// Buoc2: Cap phat dong Node de luu tru gia tri can luu (Khoi tao Node)
Node *initNode(SinhVien value)
{
    Node *p = new Node;

    p->data = value;
    p->pNext = NULL;

    return p;
}

// Buoc3: Dinh nghia Danh sach List
struct List
{
    Node *pHead;
    Node *pTail;
};

// Buoc4: Khoi tao List
void initList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

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

// 6. Viet ham khoi tao du lieu cho danh sach SinhVien
int initDataListSV(List &dsSv)
{
    SinhVien sv1 = {123, "Nguyen Cong Tri", 9, "..."};
    SinhVien sv2 = {124, "Nguyen Van B", 5.7, "..."};
    SinhVien sv3 = {125, "Nguyen Van C", 8.4, "..."};
    SinhVien sv4 = {126, "Nguyen Van D", 7.5, "..."};
    SinhVien sv5 = {127, "Nguyen Van E", 6.2, "..."};

    addHead(dsSv, initNode(sv1));
    addHead(dsSv, initNode(sv2));
    addHead(dsSv, initNode(sv3));

    addHead(dsSv, initNode({126, "Nguyen Van D", 7.5, "..."}));
    addHead(dsSv, initNode({127, "Nguyen Van E", 6.2, "..."}));

    return 5;
}

// 7. Viet ham in danh sach sinh vien
void printListSinhVien(List l)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        printSV(p->data);
    }
    cout << endl;
}

/* 8. Viet ham cap nhat xep loai hoc luc
    Input: 
        + List &dsSv
    Output:
        + List &dsSv
*/
void capNhatXLHL(List &ds)
{
    for (Node *p = ds.pHead; p != NULL; p = p->pNext)
    {
        if(p->data.diemTB >= 9)
            p->data.xepLoai = "Xuat sac";
        
        
    }
}


int main()
{
    List dsSv;
    initList(dsSv);

    cout << "Test: 6. Tao du lieu danh sach sinh vien:" << endl;
    int sl = initDataListSV(dsSv);
    cout << "\t + Ket qua = " << sl << " sinh vien." << endl;

    cout << "\nTest: 7. In danh sach sinh vien:" << endl;
    printListSinhVien(dsSv);

    cout << "\nTest: 8. Xep loai hoc luc. Ket qua:" << endl;
    capNhatXLHL(dsSv);
    printListSinhVien(dsSv);


    cout << "Test: .";
    cout << "Test: .";
    cout << "Test: .";

    system("pause");
    return 0;
}
