#include <iostream>
using namespace std;

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(a + i) << endl;
    }
}

void initDataArray(int* a, int& n){
    *(a + 0) = 24;
    *(a + 1) = 34;
    *(a + 2) = 39;

    n = 3;
}




int main() {
    int* a = new int[100]; // cap phat 100 vung nho kieu so nguyen 
    int n = 0;

    initDataArray(a, n); 

    printArray(a, n);
    


    delete[] a;

    system("pause");
    return 0;
}