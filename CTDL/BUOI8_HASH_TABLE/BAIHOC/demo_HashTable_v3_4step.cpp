#include <iostream>
using namespace std;

// Buoc 1: Dinh nghia Node
struct Node
{
    int data;
    Node *pNext;
};

// Buoc 2: Cap phat Node de luu gia tri
Node *initNode(int value)
{
    Node *p = new Node;

    p->data = value;
    p->pNext = NULL;

    return p;
}

// Buoc 3: Dinh nghia bang bam
const int Size = 5;
struct HashTable
{
    struct Bucket
    {
        Node *pHead;
        Node *pTail;
    };

    Bucket bucket[Size];
};

// Buoc 4: Khoi tao bang bam
void initHashTable(HashTable &h)
{
    for (int i = 0; i < Size; i++)
    {
        h.bucket[i].pHead = NULL;
        h.bucket[i].pTail = NULL;
    }
}

// Ham bam
int hashFunc(int value)
{
    return value % Size;
}

// Ham them
void add(HashTable &h, int value)
{
    // Buoc 1: Tim vi tri
    int i = hashFunc(value);

    // Buoc 2: Them vao bucket
    Node *p = initNode(value);
    
    //h.bucket[i]
    if (h.bucket[i].pHead == NULL)
    {
        h.bucket[i].pHead = p;
        h.bucket[i].pTail = p;
    }
    else
    {
        h.bucket[i].pTail->pNext = p;
        h.bucket[i].pTail = p;
    }
}

// Ham in
void printHT(HashTable h)
{
    cout << "HashTable. Size = " << Size << endl;
    for (int i = 0; i < Size; i++)
    {
        cout << "\tbuclet[" << i << "] =";
        for (Node *p = h.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            cout << "   " << p->data;
        }
        cout << endl;
    }
}


int main()
{
    HashTable h;
    initHashTable(h);

    add(h, 50);
    add(h, 73);
    add(h, 35);
    add(h, 36);
    add(h, 64);
    add(h, 28);
    add(h, 90);
    add(h, 21);
    add(h, 53);
    add(h, 13);

    printHT(h);

    system("pause");
    return 0;
}