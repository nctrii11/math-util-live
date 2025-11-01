#include <iostream>
using namespace std;

// Buoc1: Dinh nghia Cau truc Node
struct Node
{
    int data;
    Node *pNext;
};

// Buoc2: Cap phat dong Node de luu tru gia tri can luu (Khoi tao Node)
Node *initNode(int value)
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
        printf("[p%8p] %d [pNext %8p] ", p, p->data, p->pNext);
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
    Node *p1 = initNode(10);
    Node *p2 = initNode(79);
    Node *p3 = initNode(39);

    addHead(l, p1);
    addTail(l, p2);
    addTail(l, p3);

    addHead(l, initNode(40));
    addHead(l, initNode(29));

    return 5;
}

void popHead(List &l)
{
    if (l.pHead == NULL)
        return;

    if (l.pHead->pNext == NULL)
        l.pTail = NULL;

    Node *p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;
}

void popTail(List &l)
{
    // 1. Xử lý danh sách rỗng
    if (l.pHead == NULL)
        return;

    // 2. Xử lý trường hợp chỉ có 1 node
    if (l.pHead == l.pTail)
    {
        delete l.pHead;
        l.pHead = l.pTail = NULL;
        return;
    }

    // 3. Tìm node trước tail
    Node *p = l.pHead;
    while (p->pNext != l.pTail)
    {
        p = p->pNext;
    }

    // 4. Cập nhật tail và xóa
    Node *oldTail = l.pTail;
    l.pTail = p;
    p->pNext = NULL; // Quan trọng: ngắt liên kết
    delete oldTail;  // Giai phong
}

int main()
{
    List l;
    initList(l);

    initDataList(l);
    // printListFor(l);
    cout << "List goc:" << endl;
    printListWhile(l);

    cout << "List sau khi xoa pHead:" << endl;
    popHead(l);
    printListWhile(l);

    cout << "List sau khi xoa pTail:" << endl;
    popTail(l);
    printListWhile(l);

    system("pause");
    return 0;
}
