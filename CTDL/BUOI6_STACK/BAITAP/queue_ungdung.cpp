#include <iostream>

using namespace std;

// Dinh nghia cau truc benh nhan
struct BenhNhan
{
    int maBN;
    string tenBN;
    string loaiBenh;
    float tongTien;
};

// In ra thong tin nguoi benh
void printBN(BenhNhan BN)
{
    printf("|%5d, %15s, %10s, %10.2f|", BN.maBN, BN.tenBN.c_str(), BN.loaiBenh.c_str(), BN.tongTien);
    cout << endl;
}

int maBN = 111;
BenhNhan initDataBenhNhan()
{
    BenhNhan bn;

    maBN++;
    bn.maBN = maBN;

    srand(time(0));
    string arrTen[] = {"Lan", "Diep", "Hong", "Luom", "Teo"};
    // 0;4
    int i = rand() % 5;
    
    bn.tenBN = arrTen[i];

    bn.loaiBenh = "";
    bn.tongTien = 0;

    return bn;
}



// Dinh nghia Node
struct Node
{
    BenhNhan data;
    Node *pNext;
};

// Khoi tao Node
Node *initNode(BenhNhan BN)
{
    Node *p = new Node;
    p->data = BN;
    p->pNext = NULL;

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

// Ham them phan tu vao sau Queue
void enQueue(Queue &q, Node *p)
{
    if (q.pRear == NULL)
    {
        q.pFont = q.pRear = p;
    }

    else
    {
        q.pRear->pNext = p;
        q.pRear = p;
    }   
}

// Ham xoa phan tu dau tien cua Queue
void deQueue(Queue &q)
{
    if (q.pFont == NULL)
    {
        return;
    }

    if (q.pFont->pNext == NULL)
    {
        q.pFont = q.pRear = NULL;
    }

    Node *p = q.pFont;
    q.pFont = q.pFont->pNext;
    delete p;
}

// Ham in ra Queue
void printQueue(Queue q)
{   
    cout << "Thu tu banh nhan tu tren xuong duoi:" << endl;
    for (Node *p = q.pFont; p != NULL; p = p->pNext)
    {
        printBN(p->data);
    }
    cout << endl;
}

// Cai dat List
struct List
{
    Node *pHead;
    Node *pTail;
};

// Buoc4: Khoi tao List
void initList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

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
        printBN(p->data);
    }
    cout << endl;
}

// Ham kham benh
/* void khamBenh(BenhNhan &bn)
{
    //112, "Tuan", "", 0
    string loaiBenh[] = {"Ho", "Cam", "Sot"};
    float tienKham[] = {10000, 80000, 50000};

    int r = rand() % 4;

    bn.loaiBenh = loaiBenh[r];
    bn.tongTien = tienKham[r];

} */

void khamBenh(Queue &bnChoKham, List &bnDaKham)
{
    // Lay bn dang doi
    BenhNhan bn = bnChoKham.pFont->data;
            
    // Kham
    string loaiBenh[] = {"Ho", "Cam", "Sot"};
    float tienKham[] = {10000, 80000, 50000};

    int r = rand() % 4;

    bn.loaiBenh = loaiBenh[r];
    bn.tongTien = tienKham[r];

    // Them bn vao List
    addTail(bnDaKham, initNode(bn));

    // Loai bo
    deQueue(bnChoKham);
}

int main()
{   
    Queue bnChoKham;
    initQueue(bnChoKham);

    List bnDaKham;
    initList(bnDaKham);
    // Tao data cho Queue
    //int khoiTao = initDataQueue(bnChoKham);

    
    int chon = 0;
    BenhNhan bn; // Declare bn before the switch to avoid initialization issues
    while (1)
    {
        system("cls");
        cout << "++++++++++++ MO PHONG KHAM BENH ++++++++++++" << endl;
        cout << "\nBenh nhan dang cho:" << endl;
        printQueue(bnChoKham);

        cout << "Benh nhan dang cho: " << endl;
        printListFor(bnDaKham);

        cout << "Danh sach chuc nang:" << endl;
        cout << "\t0. Don sach man hinh." << endl;
        cout << "\t1. Them benh nhan." << endl;
        cout << "\t2. Goi benh nhan kham benh." << endl;
        cout << "\t. " << endl;
        cout << endl;
        cout << "\tChon chuc nang: ";
        cin >> chon;

        switch (chon)
        {
        case 1 :
            enQueue(bnChoKham, initNode(initDataBenhNhan()));
            break;
        
        case 2 :
            khamBenh(bnChoKham, bnDaKham);
            break;


        default:
            
            break;
        }

        /* if(bnChoKham.pFont == NULL)
            break; */
    
    }
        


    system("pause");
    return 0;
}
