#include <iostream>

using namespace std;

// Dinh nghia Node
struct Node
{
    int data;
    Node *pPre;
    Node *pNext;
};

// Cap phat dong cho Node de luu tru gia tri
Node *initNode(int value)
{
    Node *p = new Node;

    p->data = value;
    p->pPre = p->pNext = NULL;
    return p;
}

// Dinh nghia Queue
struct Queue
{
    Node *pFont;
    Node *pRear;
};

// Khoi tao Queue
void initQueue(Queue &q)
{
    q.pFont = q.pRear = NULL;
}

/* Cau 3: Viet ham dua mot phan tu vao Queue
Input:
    + Queue &q, Node *p
Output:
    + Queue &q
*/
void enQueue(Queue &q, Node *p)
{
    if (q.pFont == NULL)
    {
        q.pFont = q.pRear = p;
    }
    else
    {
        q.pRear->pNext = p;
        p->pPre = q.pRear;
        q.pRear = p;
    }
}

void printQueue(Queue q)
{
    cout << "qFont ----> qRear:" << endl;
    for (Node *p = q.pFont; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << endl;

    cout << "qRear ----> qFont:" << endl;
    for (Node *p = q.pRear; p != NULL; p = p->pPre)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

int initDataQueue(Queue &q)
{
    enQueue(q, initNode(12));
    enQueue(q, initNode(13));
    enQueue(q, initNode(14));
    enQueue(q, initNode(15));
    enQueue(q, initNode(16));

    return 5;
}

/* Cau2: Viet ham kiem tra Queue rong
Input:
    + Queue
Output:
    + return bool;
*/
bool kiemTraRong(Queue q)
{
    if (q.pFont == NULL)
        return true;

    return false;
}

/* Cau4: Viet ham lay mot phan tu ra khoi Queue
Input:
    + Queue &q
Output:
    + Queue &q
*/
void deQueue(Queue &q)
{
    if (q.pFont == NULL)
        return;

    if (q.pFont == q.pRear)
    {   
        delete q.pFont;
        q.pFont = q.pRear = NULL;
        return ;
    }
    Node *p = q.pFont;
    q.pFont = q.pFont->pNext;
    q.pFont->pPre = NULL;      // ✅ Quan trọng: Ngắt liên kết ngược
    delete p;
}

/* Cau5.1: Viet ham lay ra phan tu Font
    Input: 
        + Queue q
        + int &value
    Output:
        + return bool;
 */
bool layFont(Queue q, int &value)
{
    if (q.pFont == NULL)
        return false;
    value = q.pFont->data;
    return true;
}

bool layRear(Queue q, int &value)
{
    if (q.pRear == NULL)
        return false;
    value = q.pRear->data;
    return true;
}

/* Cau6 : Viet ham tra ve kich thuoc cua queue
Input:
    + Queue q
Output:
    return int
 */
int kichThuoc(Queue q)
{
    int kichThuoc = 0;
    if (q.pFont == NULL) return 0;

    for (Node *p = q.pFont; p != NULL; p = p->pNext)
    {
        kichThuoc += 1;
    }
    return kichThuoc;
}


int main()
{
    Queue q;
    initQueue(q);

    initDataQueue(q);

    /* cout << "\nTest 2: Kiem tra Queue rong:" << endl;
    bool kiemtra = kiemTraRong(q);
    cout << "\tKet qua(0) = " << kiemtra << endl; */

    /* cout << "Truoc khi lay ra phan tu:" << endl;
    printQueue(q);

    cout << "\nTest 4: Lay mot phan tu ra khoi Queue: Ket qua = " << endl;
    deQueue(q);
    printQueue(q); */

    /* cout << "\nTest 5: Lay ra phan tu Font:" << endl;
    int value;
    layFont(q, value);
    cout << "\t Ket qua(12) = " << value << endl;

    cout << "\nTest 5.1: Lay ra phan tu Rare:" << endl;
    int value1;
    layRear(q, value1);
    cout << "\t Ket qua(16) = " << value1 << endl; */

    cout << "\nTest 6: Tra ve kich thuoc Queue:" << endl;
    int kichThuoc1 = kichThuoc(q);
    cout << "\tKet qua(5) = " << kichThuoc1 << endl;
    

    system("pause");
    return 0;
}