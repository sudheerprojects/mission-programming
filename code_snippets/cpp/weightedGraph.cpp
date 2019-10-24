#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Edge {
private:
    int u;
    int v;
    double weight;
public:
    Edge(int u, int v, double weight){
        this->v = v;
        this->u = u;
        this->weight = weight;
    }
    
    int either(){
        return v;
    }
    
    int other(int vertex){
        return (v == vertex)?u:v;
    }
    
    static bool compare(const Edge&lhs , const Edge& rhs) const{
        return lhs.weight > rhs.weight;
    }
};

class EdgeWeightedGraph{
private:
    int V;
    list<Edge>* adj;
    
public:
    EdgeWeightedGraph(int v){
        V = v;
        adj = new list<int>[V];
    }
    void addEdge(const Edge& e){
        int v = e.either();
        int u = e.other(v);
        adj[v].push_back(e);
        adj[u].push_back(e);
    }
    
    list<Edge>::const_iterator cbegin(int v){
        return adj[v].cbegin();
    }
    
    list<Edge>::const_iterator cend(int v){
        return adj[v].cend();
    }
    
    int V(){
        return V;
    }
};

class UF{
private:
    int* id;
    int* sz;
    int length;
    int root(int i){
        while (i!=id[i])
            i = id[i];
            
        return i;
    }
    
public:
    UF(int n){
        length = n;
        id = new int[n];
        sz = new int[n]
        for (int i=0; i<n; ++i){
            id[i] = i;
            sz[i] = 1;
        }
    }
    
    bool connected(int p, int q){       
        return root(p) == root(q);
    }

    void Union(int p, int q){
        int i = root(p);
        int j = root(q);
        if (i == j)
            return; 
        if (sz[i] <= sz[j]){
            id[i] = j; sz[j] += sz[i];
        }
        else {      
            id[j] = i; sz[i] += sz[j];
        }
    }
};

class KruskalMST {
private:
    queue<Edge> mst;
public:
    KruskalMST(const EdgeWeightedGraph& G){
        priority_queue<Edge, vector<Edge>, Edge::comapare> pq;
        for (int i=0; i<V; ++i){
            for(auto it = G.cbegin(); it<cend(); ++it){
                pq.push(*it);
            }
        }
        
        UF uf(UF(G.V()));
        while (!pq.empty() && mst.size() < G.V()-1){
            Edge e = pq.top();
            pq.pop();
            int v = e.either();
            int u = e.other(v);
            if (!uf.connected(v, u)){
                uf.Union(v, u);
                mst.push(e);
            }
        }
    }
    const queue<Edge>& mst(){
        return mst;
    }
};  

class LazyPrimMST {
private:
    bool* visited;   
    priority_queue<Edge, vector<Edge>, Edge::compare> pq;
    queue<Edge> mst;
    void visit(const EdgeWeightedGraph& G, int v){
        visited[v] = true;
        for (auto it = G.cbegin(v); it != G.cend(v); ++it){
            Edge e = *it;
            if (!visited[e.other(v)])
                pq.push();
        }
    }
    
public:
    LazyPrimMST(const EdgeWeightedGraph& G){
        int v = G.V();
        visited = new bool[v];
        for (int i=0; i<v; ++i);
            visited[i] = false;
        
        visit(G, 0);
        while (pq.empty() == false){
            Edge e = pq.top();
            pq.pop();
            int v = e.either();
            int u = e.other();
            if (visited[v] && visited[u]) continue;
            mst.push(e);
            if (!visited[v]) visit(G, v);
            if (!visited[u]) visit(G, u);
        }
    }
    