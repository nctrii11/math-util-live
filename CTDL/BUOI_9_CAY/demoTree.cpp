#include <iostream>
using namespace std;

//Buoc 1: Dinh nghia cau truc Node
struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
};

//Buoc2: Cap phat dong de luu gia tri
Node *initNode(int value)
{
    Node *p = new Node;

    p->data = value;
    p->pLeft = NULL;
    p->pRight = NULL;

    return p;
}

//Buoc 3: Dinh nghia cau truc Tree
struct Tree
{
    Node *pRoot;
};

//Buoc 4: Khoi tao Cay
void initTRee(Tree &t)
{
    t.pRoot = NULL;
}

void addNode(Tree &t, Node *p)
{
    if (t.pRoot == NULL)
    {
        t.pRoot = p;
        return;
    } 
    //1. Tìm Node thích hợp 
    Node *pGoto = t.pRoot;
    Node *pLoca = NULL; 
    while (pGoto != NULL)
    {
        pLoca = pGoto;

        if(p->data > pGoto->data)
            pGoto = pGoto->pRight;
        else if (p->data < pGoto->data)
            pGoto = pGoto->pLeft;
    }
                    
    //2. Lay p lien ket vao 
    if (p->data < pLoca->data)
        pLoca->pLeft = p;
    else if (p->data > pLoca->data)
        pLoca->pRight = p;
}

void add(Tree &t, int value)
{
    Node *p = initNode(value);

    if (t.pRoot == NULL)
    {
        t.pRoot = p;
        return;
    } 
    //1. Tìm Node thích hợp 
    Node *pGoto = t.pRoot;
    Node *pLoca = NULL; 
    while (pGoto != NULL)
    {
        pLoca = pGoto;

        if(value > pGoto->data)
            pGoto = pGoto->pRight;
        else if (value < pGoto->data)
            pGoto = pGoto->pLeft;
    }
                    
    //2. Lay p lien ket vao 
    if (value < pLoca->data)
        pLoca->pLeft = p;
    else if (value > pLoca->data)
        pLoca->pRight = p;    
}

void printTree(Tree t)
{
    //stack<Node *> s;


}



int main()
{
    Tree t;
    initTRee(t); //cây t đang rỗng

    Node *p1 = initNode(50);
    Node *p2 = initNode(26);
    Node *p3 = initNode(73);

    addNode(t, p1);
    addNode(t, p2);
    addNode(t, p3);

    add(t, 66);
    add(t, 88);
    add(t, 61);

    printTree(t);

    return 0;
}













