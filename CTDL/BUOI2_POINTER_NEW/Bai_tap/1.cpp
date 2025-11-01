#include <iostream>
using namespace std;

// Cau 3. Ham tao du lieu cho mang
bool initDataArray(double *a, int &n)
{
    *(a + 0) = 0.8;
    *(a + 1) = -5.6;
    *(a + 2) = 9.1;
    *(a + 3) = 7.3;
    *(a + 4) = 10;

    n = 5;
    return true;
}

// Cau 4. Ham in mang
void printArray(double *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }

    cout << endl;
}

/* Cau 5. Kiem tra mang co toan duong
Input:
    + double* a
    + int n
Output:
    + return bool => true: co, false: khong
*/
bool kiemTraToanDuong(double *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) < 0)
            return false;
    }

    return true;
}

/* Cau 10: Tim gia tri co trong mang
Input:
    + double* a
    + int n
    + double value
Output:
    + return int => neu co thi tra ve vi tri, ko thi -1
*/

int timGiaTri(double *a, int n, double value)
{
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) == value)
            return i;
    }

    return -1;
}

/* Cau 21: Viet ham tim gia tri lon nhat va gia tri nho nhat trong mang
Input:
    + double* a
    + int n
    + double& Max
    + double& Min
Output:
    + double& Max
    + double& Min
*/

void timMaxMin(double* a, int n, double& Max, double& Min) {
    Max = Min = *a;
    for (int i = 0; i < n; i++) {
        if (*(a + i) > Max)
            Max = *(a + i);

        if (*(a + i) < Min)
            Min = *(a + i);
    }
}

/* Cau 13: Tim so lan xuat hien cua phan tu trong mang 
| 0.8 | 5.6 | 0.8 | 7.3 | 7.3 |

   2     1      2    2     2 
Input:
    + double* a
    + int n
Output:
    + int* b
*/

/* Cau 15: Tra ve cac so am trong mang
Input:
    + double* a
    + int n
Output:
    + double* b
    + int& m
*/
void timSoAm(double* a, int n, double* b, int& m) {





}





int main()
{
    double *a = new double[100]; // cap phat dong cho mang
    int n = 0;

    cout << "Test: Cau 3. Ham tao du lieu cho mang." << endl;
    cout << "\t + Ket qua: " << initDataArray(a, n) << endl;

    cout << "\nTest: Cau 4. Ham in mang:" << endl;
    printArray(a, n);

    cout << "\nTest: Cau 5. Ham kiem tra mang toan duong:" << endl;
    bool b = kiemTraToanDuong(a, n);
    cout << "\t + Ket qua: " << b << endl;

    cout << "\nTest: Cau 10. Kiem tra gia tri trong mang:" << endl;
    cout << "\t + Tim 7.3 (3)= " << timGiaTri(a, n, 7.3) << endl;
    cout << "\t + Tim 8 (-1)= " << timGiaTri(a, n, 8) << endl;

    cout << "\nTest: Cau 21. Tim max min:" << endl;
    double Max, Min;
    timMaxMin(a, n, Max, Min);
    cout << "\t + Max(10) = " << Max << endl;
    cout << "\t + Min(-5.6) = " << Min << endl;

    cout << "\nTest: Cau 15. Tim cac so am:" << endl;
    double* am = new double[100];
    int m = 0;
    timSoAm(a, n, am, m);
    
    printArray(am, m);


    delete[] a;
    delete[] am;

    
    system("pause");
    return 0;
}
