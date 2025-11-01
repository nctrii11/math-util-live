#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Tạo các mảng tạm
    int L[n1], R[n2];

    // Copy dữ liệu sang các mảng tạm L[] và R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Gộp các mảng tạm trở lại vào mảng arr[l..r]
    i = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ nhất
    j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    k = l; // Khởi tạo chỉ số bắt đầu của mảng đã gộp
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy các phần tử còn lại của mảng L[] nếu có
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy các phần tử còn lại của mảng R[] nếu có
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // tuong tu (l + r)/2, nhung cach nay tranh tran so khi l va r lon
        int m = l + (r - l) / 2;
        // goi ham de quy de tiep tuc chia doi tung mang
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m , r);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

        // Khởi tạo một mảng chưa được sắp xếp
    int arr[] = {12, 11, 13, 5, 6, 7};
    
    // Tính toán kích thước của mảng
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Mang ban dau la: \n";
    printArray(arr, arr_size);

    // Gọi hàm sắp xếp
    mergeSort(arr, 0, arr_size - 1);

    std::cout << "\nMang sau khi sap xep la: \n";
    printArray(arr, arr_size);


    cout << endl;
    system("pause");
    return 0;
}