#include <iostream>

using namespace std;

// Buoc 1: Dinh nghia node
struct Node
{
    int data;
    Node *pPre;
    Node *pNext;
};

// Buoc 2: Cap phat dong Node de luu gia tri
Node *initNode(int value)
{
    Node *p = new Node;

    p->data = value;
    p->pPre = p->pNext = NULL;

    return p;
}

// Buoc 3: Dinh nghia List
struct List
{
    Node *pHead;
    Node *pTail;
};

// Buoc 4: Khoi tao danh sach
void initList(List &l)
{
    l.pHead = l.pTail = NULL;
}

void addHead(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }

    else
    {
        p->pNext = l.pHead;
        l.pHead->pPre = p;
        l.pHead = p;
    }
}

void addTail(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }

    else
    {
        l.pTail->pNext = p;
        p->pPre = l.pTail;
        l.pTail = p;
    }
}

void printList(List l)
{
    cout << "pHead -----> pTail" << endl;
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }

    cout << endl << endl;

    cout << "pTail -----> pNext" << endl;
    for (Node *p = l.pTail; p != NULL; p = p->pPre)
    {
        cout << p->data << " ";
    }
}

int main()
{
    List l;
    initList(l); // Danh sach rong

    addHead(l, initNode(10));
    addHead(l, initNode(39));
    addTail(l, initNode(79));
    addTail(l, initNode(80));
    addTail(l, initNode(56));
    addTail(l, initNode(23));
    addHead(l, initNode(67));

    printList(l); // 67 39 10 79 80 56 23


    system("pause");
    return 0;
}
