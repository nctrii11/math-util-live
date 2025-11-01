#include <iostream>
using namespace std;

// Buoc1: Dinh nghia Cau truc Node
struct Node
{
    int data;
    Node *pNext;
};

// Buoc2: Cap phat dong Node de luu tru gia tri can luu (Khoi tao Node)
/* Node *initNode(int value)
{
    Node *p = new Node;

    p->data = value;
    p->pNext = NULL;

    return p;
} */

// Buoc3: Dinh nghia Danh sach List
struct List
{
    Node *pHead = NULL;
    Node *pTail = NULL;
};

/* // Buoc4: Khoi tao List
void initList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
} */
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


int main()
{
    //Node *p1 = initNode(10);
    //List l;
    Node* p2 = new Node({15, NULL});

    List l2 = {NULL, NULL};
    //initList(l);
    initDataList(l2);
    printListFor(l2);



    system("pause");
    return 0;
}


