//bubble sort (справа на лево)

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,("rus"));

    int ar[]={19,992,32,11,91,29};
    const int size=6;
    int buf;//буфер обмена
    int count=0;//число итераций
    int amount=0;//число всех итераций

    //сортировка пузырьком
    for(int i=0;i<size;i++)//i - номер прохода
    {
        for(int j=size-1;j>i;j--)
        {
            if(ar[j-1]>ar[j])
            {
                buf=ar[j-1];
                ar[j-1]=ar[j];
                ar[j]=buf;
            }
            amount++;
        }

        count++;
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


//то же самое, но слева на право 
/*
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,("rus"));

    int ar[]={19,992,32,11,91,29};
    const int size=6;
    int buf;//буфер обмена
    int count=0;//число итераций
    int amount=0;//число всех итераций

    //сортировка пузырьком
    for(int i=size-1;i>0;i--)//i - номер прохода
    {
        for(int j=0;j<i;j++)
        {
            if(ar[j]>ar[j+1])
            {
                buf=ar[j+1];
                ar[j+1]=ar[j];
                ar[j]=buf;
            }
            amount++;
        }

        count++;
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
*/
