#include<iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void ShakerSort(int a[], int n)
{
    int Left, Right;
    Left = 1;//в проге он пишет, что Left=1;
    Right = n - 1;
    while (Left < Right)//границу left и right будем уменьшать
    {

        for (int i = Left; i <= Right; i++)
            if (a[i] < a[i - 1]) swap(&a[i], &a[i - 1]);
        Right--;
        for (int i = Right; i >= Left; i--)
            if (a[i] < a[i - 1]) swap(&a[i], &a[i - 1]);
        Left++;

    }

}
int main() {
    int n = 8;
    int a[] = { 6,5,3,1,8,7,2,4 };
    ShakerSort(a, n);//передаем масисв и кол-во элементов
    cout << "\nSorted Data ";
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
