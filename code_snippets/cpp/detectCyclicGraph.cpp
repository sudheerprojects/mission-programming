#include <iostream>
#include <cstring>

using namespace std;

class Graph{
private: 
    int V;
    list<int>* adj;
    bool isCyclicUtil(bool* visited, int v, int parent);
public:
    Graph(int v){
        this->V = v;
        adj = new list<int>[v];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isCyclic();
};

bool Graph::isCyclicUtil(bool* visited, int v, int parent){
    if (visited[v] == false){
        visited[v] = true;
        iterator::list<int> it = adj[v].begin();
        for(; it!=adj[v].end(); ++it){
            if (!visited[*it]){
                if(isCyclicUtil(visited, *it, v))
                    return true;
            if (*it != parent)
                return true;
        }
    }
    return false;
}

bool Graph::isCyclic(){
    bool* visited = new bool[V];
    memset(visited, 0, sizeof(bool)*V);
    
    for (int i=0; i<V; ++i){
        if(isCyclicUtil(visited, i, -1))
            return true;
    }
    return false;
}


class DiGraph{
private: 
    int V;
    list<int>* adj;
    bool isCyclicUtil(bool* visited, bool* rec, int v);
public:
    DiGraph(int v){
        this->V = v;
        adj = new list<int>[v];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
    bool isCyclic();
};

bool DiGraph::isCyclicUtil(bool* visited, bool* rec, int v){
    if (visited[v] == false){
        visited[v] = true;
        rec[v] = true;
        iterator::list<int> it = adj[v].begin();
        for(; it!=adj[v].end(); ++it){
            if (!visited[*it] && isCyclicUtil(visited, rec, *it))
                return true;
            if (rec[*it] == true)
                return true;
        }
    }
    rec[v] = false;
    return false;
}

bool DiGraph::isCyclic(){
    bool* visited = new bool[V];
    bool* rec = new bool[V];
    memset(visited, 0, sizeof(bool)*V);
    memset(rec, 0, sizeof(bool)*V);
    
    for (int i=0; i<V; ++i){
        if(isCyclicUtil(visited, rec, i))
            return true;
    }
    return false;
}


int main() 
{ 
	// Create a graph given in the above diagram 
	DiGraph dg(4); 
	dg.addEdge(0, 1); 
	dg.addEdge(0, 2); 
	dg.addEdge(1, 2); 
	dg.addEdge(2, 0); 
	dg.addEdge(2, 3); 
	dg.addEdge(3, 3); 

	if(dg.isCyclic()) 
		cout << "Directed Graph contains cycle"; 
	else
		cout << "Directed Graph doesn't contain cycle"; 
    
    Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 3); 
 

	if(g.isCyclic()) 
		cout << "Graph contains cycle"; 
	else
		cout << "Graph doesn't contain cycle"; 
	return 0; 
} 
