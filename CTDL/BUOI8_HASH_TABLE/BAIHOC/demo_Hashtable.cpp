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

// Buoc 3: Dinh nghia Bucket
struct Bucket
{
    Node *pHead;
    Node *pTail;
};

// Buoc 4: Khoi tao Bucket
void initBucket(Bucket &bk)
{
    bk.pHead = bk.pTail = NULL;
}

// Buoc 5: Dinh nghia Hashtable
const int Size = 5;
struct HashTable
{
    Bucket bucket[Size];
};

// Buoc 6: Khoi tao Hashtable
void initHashTable(HashTable &h)
{
    for(int i = 0; i < Size; i++)
    {
        initBucket(h.bucket[i]);
    }
}

void addTail(Bucket &bk, Node *p)
{
    if (bk.pHead == NULL)
    {
        bk.pHead = bk.pTail = p;
    }
    else
    {
        bk.pTail->pNext = p;
        bk.pTail = p;
    }
}

int hashFunc(int value)
{
    return value % Size;
}

void add(HashTable &h, Node *p)
{
    // Buoc 1: Tim vi tri
    int i = hashFunc(p->data);

    // Buoc 2: Them vao Bucket
    addTail(h.bucket[i], p);    
    
}

void add(HashTable &h, int value)
{
    // Buoc 1: Tim vi tri
    int i = hashFunc(value);

    // Buoc 2: Them vao Bucket
    addTail(h.bucket[i], initNode(value));
}

void printHT(HashTable h)
{   
    cout << "HashTable. Size = " << Size << endl;
    for(int i = 0; i < Size; i++)
    {
        cout << "bucket[" << i << "] ="; 
        for (Node *p = h.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            cout << " " << p->data;
        }
        cout << endl;

    }
    cout << endl;
}

// Ham tim
Node *tim(HashTable h, int value)
{
    // b1:
    int i = hashFunc(value);

    // buoc2:
    for (Node *p = h.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            if (p->data == value)
                return p;
        }

    return NULL;
}



int main()
{
    HashTable h;
    initHashTable(h);

    Node *p1 = initNode(50);

    add(h, p1);
    add(h, initNode(73));

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