#include <iostream>
using namespace std;

// Dinh nghia Node
struct Node
{
    int data;
    Node *pNext;
};

// Khoi tao Node
Node *initNode(int value)
{
    Node *p = new Node;

    p->data = value;
    p->pNext = NULL;

    return p;
}

// Dinh nghia List
struct List
{
    Node *pHead;
    Node *pTail;
};

// Khoi tao List
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
        l.pHead = p;
    }
}

void addTail(List &l, Node *p)
{
    if (l.pTail == NULL)
    {
        l.pHead = l.pTail = p;
    }

    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void printList(List l)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

int initDataList(List &l)
{
    addHead(l, initNode(10));
    addHead(l, initNode(11));
    addHead(l, initNode(12));
    addHead(l, initNode(13));

    addTail(l, initNode(21));
    addTail(l, initNode(22));
    addTail(l, initNode(23));
    addTail(l, initNode(24));

    return 5;
}

int gtNhoThuHai(List l)
{
    Node *p = l.pHead;
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    for (p; p != NULL; p = p->pNext)
    {
        int v = p->data;
        if (v < min1)
        {
            min2 = min1;
            min1 = v;
        }
        else if (v > min1 && v < min2)
        {
            min2 = v;
        }
    }
    return min2;
}

void printC(List l, int k)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data > k)
        {
            cout << p->data << " ";
        }
    }
}

bool removeHead(List &l)
{
    if (l.pHead == NULL)
        return false; // DS rong

    Node *p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;

    // Neu danh sach con 0pt, cap nhat pTail = NULL;
    if (l.pHead == NULL)
        l.pTail = NULL;

    return true;
}

bool removeTail(List &l)
{
    if (l.pHead == NULL)
        return false;

    // Neu chi co 1 node
    if (l.pHead == l.pTail)
    {
        delete l.pHead;
        l.pHead = l.pTail = NULL;
        return true;
    }

    // Duyet den node trc Tail
    Node *p = l.pHead;
    while (p->pNext != l.pTail)
    {
        p = p->pNext;
    }
    delete l.pTail;

    l.pTail = p;
    l.pTail->pNext = NULL;
    return true;
}

bool removeNode(List &l, int x)
{
    // TH1 ds rong
    if (l.pHead == NULL)
        return false;

    // TH2 x la node dau
    if (l.pHead->data == x)
    {
        return removeHead(l);
    }

    // Duyet tim Node truoc Node can xoa
    Node *prev = l.pHead;
    Node *curr = l.pHead->pNext;

    while (curr != NULL && curr->data != x)
    {
        prev = curr;
        curr = curr->pNext;
    }

    if (curr == NULL)
        return false;

    // Neu node can xoa la tail
    if (curr == l.pTail)
    {
        l.pTail = prev;
    }

    prev->pNext = curr->pNext;
    delete curr;
    return true;
}

void clearList1(List &l)
{
    while (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
    }

    l.pTail = NULL;
}

void clearList2(List &l)
{
    for (Node *p = l.pHead; p != NULL;)
    {
        Node *temp = p;
        p = p->pNext;
        delete temp;
    }
    l.pHead = NULL;
    l.pTail = NULL;
}

void cauC(List l, double k)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data < k)
        {
            cout << p->data << " ";
        }
    }
}

// cau d đề 2021-2022
void cauD_2021(List &l, double k)
{
    // TH1: Xóa tất cả các node đầu có giá trị < k
    while (l.pHead != NULL && l.pHead->data < k)
    {
        Node *temp = l.pHead;
        l.pHead = l.pHead->pNext;
        delete temp;
    }

    // Nếu list rỗng sau khi xóa
    if (l.pHead == NULL)
    {
        l.pTail = NULL;
        return;
    }

    // TH2: Xóa các node ở giữa và cuối có giá trị < k
    Node *pPrev = l.pHead;
    Node *pCurr = pPrev->pNext;

    while (pCurr != NULL)
    {
        if (pCurr->data < k)
        {
            // Xóa node hiện tại
            pPrev->pNext = pCurr->pNext;

            // Nếu node cần xóa là pTail
            if (pCurr == l.pTail)
            {
                l.pTail = pPrev;
            }

            Node *temp = pCurr;
            pCurr = pCurr->pNext;
            delete temp;
        }
        else
        {
            // Chuyển sang node tiếp theo
            pPrev = pCurr;
            pCurr = pCurr->pNext;
        }
    }
}

int cauB_2024(List l, int k)
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

void cauC_2024(List l, int k)
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

void cauD_2024(List &l, Node *p)
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
    List l;
    // Khởi tạo danh sách trước khi sử dụng
    initList(l);
    initDataList(l);

    cout << "Danh sach ban dau: " << endl;
    printList(l);
    /* cout << "GTNT2: " << gtNhoThuHai(l);
    cout << endl; */

    /* cout << "Danh sach sau khi xoa duoi: " << endl;
    removeTail(l); */

    /* cout << "Danh sach sau khi xoa gia tri 10: " << endl;
    removeNode(l, 10); */

    //cout << "Danh sach sau khi xoa cac node co gia tri nho hon k(): " << endl;
    // clearList2(l);
    //cauD(l, 20);
    /* int thuTu = cauB_2024(l, 10);
    cout << "Thu tu tra ve: " << thuTu << endl; */

    //cauC_2024(l, 30);

    cauD_2024(l, new Node{12, NULL});


    printList(l);

    system("pause");
    return 0;
}