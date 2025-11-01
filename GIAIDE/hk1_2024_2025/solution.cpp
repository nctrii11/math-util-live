#include <iostream>
using namespace std;

//1
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
                swap(a[j - 1], a[j]);                  
        }
    }
}

//2
// Dinh nghia Node
struct Node
{
    int data;
    Node *pNext;
};

//Khoi tao Node
//a
Node *initNode(int value)
{
    Node *p = new Node;

    p->data = value;
    p->pNext = NULL;

    return p;
}

//Dinh nghia List
struct List
{
    Node *pHead;
    Node *pTail;
};

//Khoi tao List
void initList(List &l)
{
    l.pHead = l.pTail = NULL;
}


//b
int cauB(List l, int k)
{
    int thuTu = 0;
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        thuTu += 1;
        if (p->data == k)
        {
            return thuTu;
        }
    }
    return -1;
}

//c
void cauC(List l, int k)
{
    bool found = false;

    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data > k)
        {
            cout << p->data << " ";
            found = true;
        }
    }

    if (found == false)
        cout << "Not found" << endl;
}

//d
void cauD(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = NULL;
    }
    
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}






int main()
{
    /* int a[5] = {7, 4, 12, 20, 8};
    int n = 5; */

    /* cout <<"Mang truoc khi sort: " << endl;
    printArr(a, n);

    cout <<"Mang sau khi sort: " << endl;
    BubbleSort(a, n);
    printArr(a, n); */







    system("pause");
    return 0;
}