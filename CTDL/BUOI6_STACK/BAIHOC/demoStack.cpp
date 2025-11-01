#include <iostream>

using namespace std;

// Buoc 1: Dinh nghia Node
struct Node
{
    int data;
    Node *pNext;
};

// Buoc 2: Cap phat dong cho Node de luu gia tri
Node *initNode(int value)
{
    Node *p = new Node;

    p->data = value;
    p->pNext = NULL;

    return p;
}

// Buoc 3: Dinh nghia Stack
struct Stack
{
    Node *pTop;
};

// Buoc 4: Khoi tao Stack
void initStack(Stack &s)
{
    s.pTop = NULL;
}

void push(Stack &s, Node *p)
{
    if (s.pTop == NULL)
        s.pTop = p;

    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
}

void printStack(Stack s)
{
    cout << "Stack = pTop<<  ";
    for (Node *p = s.pTop; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << ">>" << endl;
}

void pop(Stack &s)
{
    if (s.pTop == NULL)
        return;

    if (s.pTop->pNext == NULL)
        s.pTop = NULL;

    Node *p = s.pTop;
    s.pTop = s.pTop->pNext;
    delete p;
}

/* Node *getTop(Stack s)
{
    return s.pTop;
}
 */

void convert10to2(int value, Stack &s)
{
    while (value != 0)
    {
        int d = value % 2;
        
        push(s, initNode(d));
        value = value / 2;
    }
}

int main()
{
    Stack s;
    initStack(s); // s dang rong

    push(s, initNode(10));
    push(s, initNode(11));
    push(s, initNode(12));
    push(s, initNode(13));
    push(s, initNode(14));

    printStack(s);

    pop(s);
    printStack(s);

    cout << "Test: Tu he 10 sang he nhi phan:" << endl;

    Stack s2;
    initStack(s2);

    convert10to2(13, s2);
    printStack(s2);

    system("pause");
    return 0;
}