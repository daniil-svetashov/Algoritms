#include <iostream>

using namespace std;

const int V = 8;
const int INF = 9999999;


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

int main()
{
	bool visited[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	
	int start=0;//It will be our start vertex
	//for this example our start vertex will be 0
	
	//!!!!!!/////visited[start]=true; WE DONT NEED IT !
	
	//we go threw the colomns and find valuebalse which are not
	//equel infinity
	//if vertex has valueble but it is connected to the vertex
	//which we have visited, we go threw other adjent vertexes
	//if they are also all visited, we go back to the previous 
	//vertex
	

	//I will choose the first vertex from the adjency matrix

	int current=start;//In the end of the algorithm we need
	//go back to the vertex which we started from, while
	//checking if there are no adjent and not visited vertexes
        
	//I think that i should save the path at the array or smth
	int path[V];
	path[0]=start;//Our first element of our path is our start
	//I also need to track the index of last element(vertex),
	//so i add variable wich will have the index of last vertex
	//when i add element to my path array i increment this
	//variable
	int path_index=0;
        int counter;//i add the counter, because if we didn`t
	//change our vertex, we need to go to the previous one

	bool all_visited;

	cout<<"WE START FROM: "<<start<<" ,then"<<endl;
	do
	{
		//counter=0;
		all_visited=true;


	for(int i=0;i<V;i++,counter=0)
	{
		if(G[current][i]!=INF && visited[i]==false)
	  {
		  current=i;
		  cout<<"we are in vertex: "<<i<<endl;
		  visited[i]=true;
		  path_index++;
		  path[path_index]=i;
		  counter++;
		  i=0;
	  }
	}
          if(counter==0 && current!=start)//because if we at the
		  //the start and dont have adjent vertexes,we have
		  //finished th ealgorithms 
	  {
		  path_index--;
		  current=path[path_index];
	           cout<<"We came to the previous vertex:"<<path[path_index]<<endl;

	  }


	  for(int i=0;i<V;i++)
	  {
		  if(visited[i]==false)
			  all_visited=false;
	  }
	}while(!all_visited);



	return 0;
}
