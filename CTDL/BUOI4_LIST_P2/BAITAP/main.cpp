#include <iostream>
using namespace std;

// 1.Khoi tao cau truc sinh vien
struct SinhVien
{
    int maSV;
    string hoTen;
    float diemTB;
    string xepLoai;
};

void printSV(SinhVien SV)
{
    printf("|%5d, %15s, %5.3f, %10s|", SV.maSV, SV.hoTen.c_str(), SV.diemTB, SV.xepLoai.c_str());
    cout << endl;
}

// 2. Khoi tao cau truc node
struct Node
{
    SinhVien data;
    Node *pNext;
};

// 3. Cap phat dong de luu tru gia tri can luu (Khoi tao Node)
Node *initNode(SinhVien SV)
{
    Node *p = new Node;
    p->data = SV;
    p->pNext = NULL;

    return p;
}

// 4. Khoi tao list
struct List
{
    Node *pHead;
    Node *pTail;
};

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
}

void addTail(List &l, Node *p)
{
    if (l.pTail == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }

    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void initPrintListSV(List l)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        printSV(p->data);
    }
    cout << endl;
}

int initDataList(List &l)
{
    SinhVien sv = {123, "Nguyen Cong Tri", 9.0, ".."};
    SinhVien sv1 = {124, "Nguyen Binh Minh", 9.0, ".."};
    SinhVien sv2 = {125, "Lucid Nguyen", 4.5, ".."};
    SinhVien sv3 = {126, "Melekhov Nguyen", 6.2, ".."};

    addHead(l, initNode(sv));
    addHead(l, initNode(sv1));
    addHead(l, initNode(sv2));
    addHead(l, initNode(sv3));

    return 4;
}

/* 8. Ham cap nhat xep loai hoc luc
    Input:
        + List& l
    Output:
        + List& l
*/
void capNhatXLHL(List &l)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data.diemTB >= 9.0)
            p->data.xepLoai = "Xuat sac";

        else if (p->data.diemTB >= 8.0 and p->data.diemTB <= 9.0)
            p->data.xepLoai = "Gioi";

        else if (p->data.diemTB >= 7.0 and p->data.diemTB <= 8.0)
            p->data.xepLoai = "Kha";

        else
            p->data.xepLoai = "Trung binh";
    }
}

/* 9. Ham cap nhat xep loai hoc luc
    Input:
        + List &l
    Output:
        + return float
*/
float timDiemTBCaoNhat(List &l)
{
    float diemCaoNhat = 0;

    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data.diemTB > diemCaoNhat)
            diemCaoNhat = p->data.diemTB;
    }
    return diemCaoNhat;
}

/* 10. Tim kiem sinh vien theo ma sinh
    Input:
        + List &l
        + int maSv
    Output:
        + return bool
*/
bool timKiemTheoMaSV(List &l, int maSV)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data.maSV == maSV)
            return true;
    }
    return false;
}

/* 11. Tim sinh vien co diem trung binh cao nhat
    Input:
        + List &l
    Output:
        + return bool
*/
Node *timSVDtbCaoNhat(List &l)
{
    float diemCaoNhat = 0;
    Node *p1 = new Node;
    
    //List l1;
    //initList(l1);

    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data.diemTB > diemCaoNhat)
            p1 = p;
    }
    return p1;
}

int main()
{
    List l;
    initList(l);

    initDataList(l);

    /* cout << "Danh sach sv truoc khi cap nhat XLHL:" << endl;
    initPrintListSV(l); */

    /* cout << "\nTest: 8. Xep loai hoc luc. Ket qua:" << endl;
    capNhatXLHL(l);
    initPrintListSV(l);

    cout << "\nTest: 9. Tim diem trung binh cao nhat:" << endl;
    float diemCaoNhat = timDiemTBCaoNhat(l);
    cout << "\t + Ket qua(9) = " << diemCaoNhat << endl; */

    /* cout << "\nTest: 10. Tim kiem sinh vien theo ma sinh vien:" << endl;
    bool timSV = timKiemTheoMaSV(l, 123);
    cout << "\t + Ket qua(1) = " << timSV << endl; */

    cout << "\nTest: 10. Tim sinh vien co diem trung binh cao nhat:" << endl;
    Node *timSVDtb = timSVDtbCaoNhat(l);
    cout << "\t + Ket qua = " << timSVDtb << endl;

    system("pause");
    return 0;
}