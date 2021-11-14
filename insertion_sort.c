//https://habr.com/ru/post/181271/


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

    //сортировка пузырьком
    for(int i=1;i<size;i++)//i - номер прохода
    {
        for(int j=i;j>0;j--)
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
