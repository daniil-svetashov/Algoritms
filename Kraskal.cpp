//size_t чтобы сравнивать с переменной размера


#include <iostream>
#include <vector>//vector is a dynamic array
#include <algorithm>

using namespace std;
#define edge pair<int,int>//pair - переменная, которая хранит в себе 2 значения
class Graph {
private:
	vector<pair<int, edge>> G; // graph
	vector<pair<int, edge>> T; // minimum spanning tree
	int* parent;//указатель типа int
	int V; // number of vertices/nodes in graph

public:
	Graph(int V);
	void AddWeightedEdge(int u, int v, int w);
	int find_set(int i);
	void union_set(int u, int v);
	void kruskal();
	void print();
};
Graph::Graph(int V) {//:: так как мы вынесли реализацию из класса, а влассе только прототип
	parent = new int[V];//создали динамический массив, указатель на него равен parent
	//        i 0 1 2 3 4 5
	//parent[i] 0 1 2 3 4 5
	for (int i = 0; i < V; i++)
		parent[i] = i;
	G.clear();//очистили вектор графа
	T.clear();//очистили вектор остового дерева
}

void Graph::AddWeightedEdge(int u, int v, int w) {
	G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
	// If i is the parent of itself
	if (i == parent[i])
		return i;
	else
		// Else if i is not the parent of itself
		// Then i is not the representative of his set,
		// so we recursively call Find on its parent
		return find_set(parent[i]);
}
void Graph::union_set(int u, int v) {
	parent[u] = parent[v];
}
void Graph::kruskal() {
	int uRep, vRep;
	sort(G.begin(), G.end()); // отсортировли по возростанию веса ребер графа в векторе
	print();
	for (size_t i = 0; i < G.size(); i++) {//пока не до САМОГО КОНЦА ВЕКТОРА ГРАФ
		uRep = find_set(G[i].second.first);//исходная вершина
		vRep = find_set(G[i].second.second);//в которую направляемся
		if (uRep != vRep) {
			T.push_back(G[i]); // add to tree
			union_set(uRep, vRep);
		}
	}
}
void Graph::print() {
	cout << "Edge :" << " Weight" << endl;
	for (size_t i = 0; i < G.size(); i++) {
		cout << G[i].second.first << " - " << G[i].second.second << " : " << G[i].first;
		cout << endl;
	}
}
int main() {
	Graph g(6);
	g.AddWeightedEdge(0, 1, 3);
	g.AddWeightedEdge(0, 4, 6);
	g.AddWeightedEdge(0, 5, 5);
	g.AddWeightedEdge(1, 0, 3);
	g.AddWeightedEdge(1, 2, 1);
	g.AddWeightedEdge(1, 5, 4);
	g.AddWeightedEdge(2, 1, 1);
	g.AddWeightedEdge(2, 3, 6);
	g.AddWeightedEdge(2, 5, 4);
	g.AddWeightedEdge(3, 2, 6);
	g.AddWeightedEdge(3, 4, 8);
	g.AddWeightedEdge(3, 5, 5);
	g.AddWeightedEdge(4, 2, 4);
	g.AddWeightedEdge(4, 0, 6);
	g.AddWeightedEdge(4, 2, 8);
	g.AddWeightedEdge(4, 5, 2);
	g.AddWeightedEdge(5, 0, 5);
	g.AddWeightedEdge(5, 1, 4);
	g.AddWeightedEdge(5, 2, 4);
	g.AddWeightedEdge(5, 3, 5);
	g.AddWeightedEdge(5, 4, 2);
	g.kruskal();
	return 0;
}
