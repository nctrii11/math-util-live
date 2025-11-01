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
    cout << endl;
}
//1
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min_pos] < a[j])
            {
                min_pos = j;          
            }
        }
        swap(a[min_pos], a[i]);
    }
}

//2
//Dinh nghia Node
struct Node
{
    double data;
    Node *pNext;
};

//Dinh nghia List
struct List
{
    Node *pHead = NULL;
    Node *pTail = NULL;
};

//caub
double cauB(List l)
{
    double min1 = INT_MAX;
    double min2 = INT_MAX;

    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        double v = p->data;
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

//cau c
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

//cau d
bool cauD(List &l, double k)
{
    //TH1: List rỗng
    if (l.pHead == NULL)
    {
        return false;
    }

    //TH2: Giá trị Node đầu nhỏ hơn k
    if (l.pHead->data < k)
    {
        l.pHead = l.pHead->pNext;
        delete l.pHead;
        return true;
    }
    
    Node *pPrev = l.pHead;
    Node *pCurr = pPrev->pNext;

    while (pCurr != NULL & pCurr->data < k)
    {
        pPrev = pCurr;
        pCurr = pCurr->pNext;
    }
    
    if (pCurr == NULL)
    {
        return false;
    }
    
    //Nếu Node cần xóa là pTail

    if (pCurr == NULL)
    {
        l.pTail = pPrev;
    }
    pPrev->pNext = pCurr->pNext; 
    delete pCurr;
    return true;
}












int main()
{
    int a[5] = {10, 5, 2, 39, 20};
    int n = 5;

    selectionSort(a, n);
    printArr(a, n);




    system("pause");
    return 0;
}