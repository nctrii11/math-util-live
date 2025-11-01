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

// Buoc3: Dinh nghia Queue
struct Queue
{
    Node *pFront;
    Node *pRear;
};

// Buoc4: Khoi tao Queue
void initQueue(Queue &q)
{
    q.pFront = q.pRear = NULL;
}

void enQueue(Queue &q, Node *p)
{
    if (q.pRear == NULL)
    {
        q.pFront = q.pRear = p;
    }

    else
    {
        q.pRear->pNext = p;
        q.pRear = p;
    }
}

void printQueueFor(Queue q)
{
    cout << "Queue Q = pFront<< "; 
    for (Node *p = q.pFront; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << ">>pRear" << endl << endl;
}

void deQueue(Queue &    q)
{
    if (q.pFront == NULL) return;

    if (q.pFront->pNext == NULL)
        q.pRear = NULL;

    Node *p = q.pFront;
    q.pFront = q.pFront->pNext;
    delete p;

}


int main()
{
    Queue q;
    initQueue(q);

    enQueue(q, initNode(10));
    enQueue(q, initNode(50));
    enQueue(q, initNode(30));
    enQueue(q, initNode(20));

    printQueueFor(q);

    deQueue(q);

    printQueueFor(q);


    system("pause");
    return 0;
}
