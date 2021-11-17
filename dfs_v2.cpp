#include <iostream>

using namespace std;

const int V = 8;
const int INF = 9999999;
const int start=0;

//matrix from page 12 TA_6_1_21.pdf
int G[V][V] = {
    {INF, 1, 1, 1, INF, INF, INF, INF},
    {1, INF, INF, INF, 1, INF, INF, INF},
    {1, INF, INF, INF ,INF, INF, INF, INF},
    {1, INF, INF, INF, INF, 1, INF, INF},
    {INF, 1, INF, INF, INF, 1, INF, INF},
    {INF, INF, INF, 1, 1, INF, 1, 1},
    {INF, INF, INF, INF, INF, 1, INF, INF},
    {INF, INF, INF, INF, INF, 1, INF, INF}
};


void recursion(bool*,int*,int,int);


int main()
{
	bool visited[V];
	int current=start;
	int path[V];
        path[0]=start;
        int path_index=0;
	for(int i=0;i<V;i++)
        {
                visited[i]=false;
        }
	visited[start]=true;

	recursion(visited,path,path_index,current);



     return 0;
}

void recursion(bool* visited,int* path,int path_index,int current)
{
	int counter=0;
	for(int i=0;i<V;i++)
        {
                if(G[current][i]!=INF && visited[i]==false)
          {
                  current=i;
                  cout<<"we are in vertex: "<<i<<endl;
                  visited[i]=true;
                  path_index++;
                  path[path_index]=i;
                  counter++;
                  recursion(visited,path,path_index,current);
          }
        }
        if(counter==0 && current!=start)//because if we at the
                  //the start and dont have adjent vertexes,we have
                  //finished th ealgorithms
         {
                  path_index--;
                  current=path[path_index];
                  cout<<"We came to the previous vertex:"<<path[path_index]<<endl;
	          recursion(visited,path,path_index,current);
	}
}

