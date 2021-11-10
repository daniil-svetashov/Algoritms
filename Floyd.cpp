#include <iostream>
#include <cstdlib>//library for min and max
//min(a,b); Returns the argument which is smaller than another one 

using namespace std;

const int INF = 999999;
const int V = 8;

int G[V][V] = { //adjency matrix
    {INF, INF, 2, 1, INF, 8, INF, INF},
    {INF, INF, 1, 6, INF, 3, 4, INF},
    {2, 1, INF, INF ,INF, INF, INF, 4},
    {1, 6, INF, INF, 4, INF, INF, INF},
    {INF, INF, INF, 4, INF, INF, 7, INF},
    {8, 3, INF, INF, INF, INF, INF, 3},
    {INF, 4, INF, INF, 7, INF, INF, 5},
    {INF, INF, 4, INF, INF, 3, 5, INF}
};

int D[V][V] = {
    {INF,1,2,3,4,5,6,7},
    {0,INF,2,3,4,5,6,7},
    {0,1,INF,3,4,5,6,7},
    {0,1,2,INF,4,5,6,7},
    {0,1,2,3,INF,5,6,7},
    {0,1,2,3,4,INF,6,7},
    {0,1,2,3,4,5,INF,7},
    {0,1,2,3,4,5,6,INF}
};

int main()
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)//переходим на следующую строку, когда на текущей все уже просмотрели
        {
            for (int j = 0; j < V; j++)//пробегаем столбцы
            {
                if (i!=j && G[i][j] > G[i][k] + G[j][k]) 
                {
                    G[i][j] = G[i][k] + G[j][k];
                    D[i][j] = k;
                }
            }
        }
    }

        cout << "Adjency matrix" << endl;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i != j)
                    cout << G[i][j] << "  ";
                else cout << "-  ";
                cout << "\t";
            }
            cout << endl;
        }


        
        cout << "Distance matrix" << endl;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << D[i][j] << " ";
            }
            cout << endl;
        }
      

        return 0;
   }
