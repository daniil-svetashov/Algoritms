
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int V = 8;
const int INF = 9999999;

int G[V][V] = {
    {INF, INF, 2, 1, INF, 8, INF, INF},
    {INF, INF, 1, 6, INF, 3, 4, INF},
    {2, 1, INF, INF ,INF, INF, INF, 4},
    {1, 6, INF, INF, 4, INF, INF, INF},
    {INF, INF, INF, 4, INF, INF, 7, INF},
    {8, 3, INF, INF, INF, INF, INF, 3},
    {INF, 4, INF, INF, 7, INF, INF, 5},
    {INF, INF, 4, INF, INF, 3, 5, INF}
}; // ìàòðèöà ñâÿçåé

int main()
{
    int selected[V];//an array of visited vertieces
    int size[V];//an array of sizes of vertieces
    int start=0;//index of start vertex
    int end=6;//index of end vertex

    for (int i = 0; i < V; i++)
    {
        selected[i] = 0;
        size[i] = INF;
    }

    int minimum;
    int minindex;
    size[start] = 0;//Because we will be finding shortest paths from this vertex

    do
    {
        minimum = INF;//we will use it to compare the vertieces
        //to choose the vertex with the smallest size
        minindex = INF;//inf just to inizilize the variable

        for (int i = 0; i < V; i++)
        {
            if (!selected[i] && size[i] < minimum)
            {
                //if it is true, we change our variable to the smaller one
                //and we remember it`s index, because we will be looking at the adjent vertieces
                //to it
                minimum = size[i];
                minindex = i;
            }
        }
        //we found the vertex with the smallest size from not visited!



            //after this we will look at all adjent vertieces of this vertex

        if (minindex != INF)
        {
            for (int j = 0; j < V; j++)
            {
                if (G[minindex][j] != INF)
                {
                    size[j] = min(size[j], size[minindex] + G[minindex][j]);
                }
            }
            selected[minindex] = 1;
        }

    } while (minindex < INF);

    for (int i = 0; i < V; i++)
        cout << size[i] << " ";
    // Восстановление пути
    int visited[V]; // массив посещенных вершин
    //int end = 6; // индекс конечной вершины
    visited[0] = end; // начальный элемент - конечная вершина

    int k = 1; // индекс предыдущей вершины
    int weight = size[end]; // вес конечной вершины

    while (end != 0) // пока не дошли до начальной вершины
    {
        for (int i = 0; i < V; i++) // просматриваем все вершины
            if (G[i][end] != INF)   // если связь есть
            {
                // определяем вес пути из предыдущей вершины
                if (weight - G[i][end] == size[i]) // если вес совпал с рассчитанным
                {                 // значит из этой вершины и был переход
                    weight = size[i]; // сохраняем новый вес
                    end = i;       // сохраняем предыдущую вершину
                    visited[k] = i; // и записываем ее в массив
                    k++;
                }
            }
    }

    printf("\nShortest path\n");
    for (int i = k - 1; i >= 0; i--)
        printf("%3d ", visited[i]);


    return 0;
}

