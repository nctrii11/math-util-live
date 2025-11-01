#include <iostream>
#include <time.h>
using namespace std;


int main() {
    srand(time(NULL));
    cout << "Random = " << 8 + rand() % 8 << endl; //[8; 15] = 8 + [0; 7]




    system("pause");
    return 0;
}