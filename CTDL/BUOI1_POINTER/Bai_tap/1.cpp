#include <iostream>
using namespace std;

void initDataArray(double* a, int& n) {
    *(a + 0) = 0.8;
    *(a + 1) = 5.6;
    *(a + 2) = 9.1;
    *(a + 3) = 7.3;
    *(a + 4) = 10;
    *(a + 5) = 5.9;
    *(a + 6) = 7.2;
    *(a + 7) = 9.3;
    *(a + 8) = 8.0;
    *(a + 9) = 8.7;

    n = 10;
}

void printArray(double* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(a + i) << endl;
    }
}




int main() {
    double* a = new double[100];
    int n = 0;

    initDataArray(a, n); 

    printArray(a, n);
    


    delete[] a;



    system("pause");
    return 0;
}





