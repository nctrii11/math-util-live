#include <iostream>
#include <forward_list>

using namespace std;

int main ()
{
    forward_list<int> ds;
    ds.push_front(12);
    ds.push_front(89);
    ds.push_front(50);

    for (int item: ds)
    {
        cout << item << " ";
    }

    system("pause");
    return 0;
}