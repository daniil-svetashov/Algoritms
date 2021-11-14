#include<iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void oddEvenSort(int arr[], int n)
{
    bool isSorted;
    do
    {
        isSorted = true;
        for (int i = 1; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }

        // Perform Bubble sort on even indexed element
        for (int i = 0; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
    } while (!isSorted);

    return;
    
}

// A utility function ot print an array of size n

int main() {
    int n=8;
    int a[]= { 6,5,3,1,8,7,2,4 };
    oddEvenSort(a, n);//передаем масисв и кол-во элементов
    cout << "\nSorted Data ";
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
