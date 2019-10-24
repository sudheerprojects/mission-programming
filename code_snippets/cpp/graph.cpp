#include <iostream>
#include <list>
#include <queue>

using namespace std;

class UnDirGraph
{
private:
    int V;
    list<int> *adj;
    void dfsUtil(int v, int visited[]);
    void bfsUtil(int v, int visited[]);
    
public:
    UnDirGraph(int v);
    ~UnDirGraph();
    void addEdge(int s, int d);
    void DFS();
    void BFS();
    list<int>::const_iterator cbegin(int v){
        return adj[v].cbegin();
    }
    list<int>::const_iterator cend(int v){
        return adj[v].cend();
};

UnDirGraph::UnDirGraph(int v)
{
    V = v;
    adj = new list<int>[V];
}

UnDirGraph::~UnDirGraph(){
    delete []V;
}

UnDirGraph::addEdge(int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

UnDirGraph::dfsUtil(int v, int visited[])
{
    visited[v] = true;
    cout<<v<<" ";
    list<int>::iterator it = adj[v].begin();
    for (it != adj[v].end(); ++it)
    {
        if (!visited[*it])
            dfsUtil(*it, visited);
    }
}

void UnDirGraph::DFS()
{
    bool *visited = new bool[v];
    for (int i = 0; i<v; ++i)
        visited[i] = false;
    cout<<"DFS of given graph "<<endl;
    for (int i=0; i<V; ++i)
    {
        if (!visited[i])
            dfsUtil(i, visited);
    }
} 

void UnDirGraph::bfsUtil(int v, int visited[]){
    queue<int> q;
    q.push_back(s);
    visited[s] = true;
    cout<<endl;
    cout<<"BFS of given graph "<<endl;
    iterator::list<int> it;
    while (q.empty() == false){
        int v = q.front();
        cout<<v<<" ";
        q.pop_front();
        for (it = adj[v].begin(); it!=adj[v].end(); ++it){
            if (visited[*it] == false){
                visited[*it] = true;
                q.push_back(*it);
            }
        }
    }
}

void UnDirGraph::BFS(){
    bool* visited = new bool[V];
    memset(visited, 0, sizeof(bool)*V;
    
    for (int i= 0; i<V; ++i){
        if(visited[i] == false)
            bfsUtil(i, visited);
    }
}
        
class CC {
private:
    bool* visited;
    int* id;
    int count;
    int V;
public:
    int count(){
        return count;
    }
    int id(int v){
        return id[v];
    }
    bool connected(int v, int u){
        return id[v] == id[u];
    }
    CC (const UnDirGraph& G){
        V = G.V();
        visited = new bool[V];
        for (int i=0; i<V; ++i)
            visited[i] = false;
        id = new int[V];
        count = 0;
        for (int i=0; i<V; ++i){
            if (visited[i] == false)
                dfs(G, i);
                count++;
        }
    }
    ~CC(){
        delete [] visited;
        delete [] id;
    }
    
    void dfs (const UnDirGraph& G, v){
        visited[v] = true;
        id[v] = count;
        for (auto it=G.cbegin(); it !=G.cend(); ++i){
            if (visited[*it] == false)
                dfs(G, *it);
        }
    }
};    
    
    
    
void main()
{
    UnDirGraph G(6);
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 0);
    G.addEdge(0, 0);
    G.addEdge(4, 5);
    G.DFS();
    G.BFS();
    return 0;
}
    
    
    
