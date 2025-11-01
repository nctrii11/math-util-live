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

void diChuyen(Stack &A, Stack &B, int &dem)
{
    if (A.pTop != NULL && B.pTop == NULL) // A khong rong va B rong
    {
        int x = A.pTop->data;
        pop(A);
        push(B, initNode(x));

        dem++;
    }

    else if (A.pTop != NULL && B.pTop != NULL) // A va B ko rong
    {
        if (A.pTop->data < B.pTop->data) // Top A < Top B thi pop A push B
        {
            int x = A.pTop->data;
            pop(A);
            push(B, initNode(x));

            dem++;
        }
    }
}

int main()
{
    Stack A;
    initStack(A);

    Stack B;
    initStack(B);

    Stack(C);
    initStack(C);

    int dem = 0;
    while (1)
    {
        // system("cls");
        cout << endl;
        cout << "===== Demo Stack =====" << endl;
        cout << "\t0. Init Tower." << endl;
        cout << "\t1. A -> B." << endl;
        cout << "\t2. B -> A." << endl;
        cout << "\t3. B -> C." << endl;
        cout << "\t4. C -> B." << endl;
        cout << "\t5. C -> A." << endl;
        cout << "\t6. A -> C." << endl;
        cout << "\t7. All: 6 1 4 6 2 3 6" << endl;
        cout << "\t8. Cls..." << endl;

        cout << "===========" << endl;
        cout << "A Tower" << endl;
        printStack(A);

        cout << "===========" << endl;
        cout << "B Tower" << endl;

        cout << "===========" << endl;
        cout << "C Tower" << endl;

        cout << "===========" << endl;
        cout << "So lan di chuyen: " << dem << endl;
        cout << "===========" << endl;

        cout << "\tPlease input: ";
        int chon;
        cin >> chon;
        cout << endl << endl;

        switch (chon)
        {
        case 0:
        {
            int tang;
            cout << "Nhap vao so tang: ";
            cin >> tang;
            for (int i = tang; i >= 1; i = i - 1)
            {
                push(A, initNode(i));
            }
            break;
        }
        case 2:
        {
            diChuyen(B, A, dem);
            break;
        }
        case 3:
        {
            diChuyen(B, C, dem);
            break;
        }
        case 4:
        {
            diChuyen(C, B, dem);
            break;
        }
        case 5:
        {
            diChuyen(C, A, dem);
            break;
        }
        case 6:
        {
            diChuyen(A, C, dem);
        }
        case 8:
        {
            system("cls");
        }

        default:
            break;
        }
    }

    system("pause");
    return 0;
}
