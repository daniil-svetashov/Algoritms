//https://www.youtube.com/watch?v=yfbdgl9KzSw&ab_channel=prog-cpp

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,("rus"));

    int ar[]={6,5,3,1,8,7,2,4};
    const int size=8;
    int buf;//буфер обмена
    int count=0;//число итераций
    int amount=0;//число всех итераций


    int min;//индекс минимального
    for(int i=0;i<size-1;i++)//i - номер прохода
    {
        min=i;
        for(int j=i+1;j<size;j++)
        {
            if(ar[min]>ar[j])
            {
                min=j;
            }
            amount++;//кол-во итераций в алгоритме для текущей длины массива
        }
        buf=ar[i];
        ar[i]=ar[min];
        ar[min]=buf;
        count++;//для красивого вывода
        printf("%dя итерация: ",count);
        for(int z=0;z<size;z++)
         {
          printf("%d ",ar[z]);
         }
        printf("\n");
    }

    printf("Число всех операций: %d",amount);

    return 0;
}
