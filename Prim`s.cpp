#include <iostream>
#include <cstring>
using namespace std;

const int INF = 999999;//infinity
const int V = 6;//number of vertecies
int G[V][V] = { //adjency matrix
	{INF,3,INF,INF,6,5},
    {3,INF,1,INF,INF,4},
    {INF,1,INF,6,INF,4},
    {INF,INF,6,INF,8,5},
    {6,INF,INF,8,INF,2},
    {5,4,4,5,2,INF}
};


int main(){

    int selected[V];//array of selected vertecies
    for (int i = 0; i < V; i++)//inizialize our array with 0, as we don`t have any vertex selected
    {
        selected[i] = 0;
    }

    selected[0] = true;//we take a random vertex and add it to the selected array
    int no_edge = 0;//number of edges in tree is always V-1
    
    cout << "Edge" << " : " << "Weight" << endl;
    while (no_edge < V - 1)
    {
        int min = INF;//inizialize minimum, because we will have to compare it with weight values
        int x = 0;//row
        int y = 0;//colomn

        for (int i = 0; i < V; i++)//to get thew rows of adjancy matrix
        {
            if(selected[i])//we select a vertex from our array, if(true)
            for (int j = 0; j < V; j++)//to get threw coloms of adjency matrix
            {
                if (!selected[j] && G[i][j])//if we are looking at not selected vertex, we compare the G[i][j] with INF on 1st iteretion
                {
                    if (min > G[i][j])
                    {
                        min = G[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        selected[y] = true;
        cout << x << " - " << y << " : " << min;
        cout << endl;
        no_edge++;
    }

	return 0;
}
