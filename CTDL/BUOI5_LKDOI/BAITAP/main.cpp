#include <iostream>
using namespace std;

// Dinh nghia Sinh Vien
struct SinhVien
{
    int maSV;
    string hoTen;
    float diemTB;
    string xepLoai;
};

// Ham in thong tin sinh vien
void printSV(SinhVien sv)
{
    printf("|%5d %15s %8.4f %10s|", sv.maSV, sv.hoTen.c_str(), sv.diemTB, sv.xepLoai.c_str());
}

// Dinh nghia Node
struct Node
{
    SinhVien data;
    Node *pPre;
    Node *pNext;
};

// Cap phat dong cho Node de luu tru gia tri
Node *initNode(SinhVien sv)
{
    Node *p = new Node;
    p->data = sv;
    p->pNext = p->pPre = NULL;

    return p;
}

// Dinh nghia List
struct List
{
    Node *pHead;
    Node *pTail;
};

// Khoi tao List
void initList(List &l)
{
    l.pHead = l.pTail = NULL;
}

void addHead(List &l, Node *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;

    else
        p->pNext = l.pHead;
    l.pHead->pPre = p;
    l.pHead = p;
}

void addTail(List &l, Node *p)
{
    if (l.pTail == NULL)
        l.pHead = l.pTail = p;

    else
        l.pTail->pNext = p;
    p->pPre = l.pHead;
    l.pTail = p;
}

int initDataList(List &l)
{
    addHead(l, initNode({123, "Nguyen Van A", 9.0, "..."}));
    addHead(l, initNode({124, "Nguyen Van B", 8.5, "..."}));
    addHead(l, initNode({125, "Nguyen Van C", 5.0, "..."}));
    addHead(l, initNode({126, "Nguyen Van D", 7.2, "..."}));
    addHead(l, initNode({127, "Nguyen Van E", 6.1, "..."}));

    return 5;
}

void printList(List l)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        printSV(p->data);
        cout << endl;
    }
}

int main()
{
    List l;
    initList(l);

    initDataList(l);

    printList(l);

    system("pause");
    return 0;
}