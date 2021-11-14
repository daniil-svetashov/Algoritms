#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void qsortRecursive(int*,int);//прототип

int main()
{
    setlocale(LC_ALL, ("rus"));

    int ar[] = { 6,1,3,5,8,7,2,4 };
    const int size = 8;
    qsortRecursive(ar, size);


    //the final result
    printf("\nThe final result");
    for (int z = 0; z < size; z++)
    {
        printf("%d ", ar[z]);
    }
    printf("\n");

    return 0;
}

void qsortRecursive(int* mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левый кусок"
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive(&mas[i], size - i);
    }
}
