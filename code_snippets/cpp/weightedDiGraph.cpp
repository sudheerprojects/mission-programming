#include <iostream>
#include <list>
#include <queue>
#include <limits>

using namespace std;

class DirectedEdge{
private:
    int v;
    int u;
    double weight;
public:
    DirectedEdge(int v, int u, int weight){
        this->v = v;
        this->u = u;
        this->weight = weight;
    }
    
    int from(){
        return v;
    }
    
    int to(){
        return u;
    }
    
    double weight(){
        return weight;
    }
};

class EdgeWeightedDiGraph {
private:
    int V;
    list<DirectedEdge>* adj;
public:
    EdgeWeightedDiGraph(int V){
        this->V = V;
        adj = new list<DirectedEdge>[this->V];
    }
    int V(){
        return V;
    }
    
    void addEdge(const DirectedEdge& e){
        int i = e.from();
        adj[i].push_back(e);
    }
    
    
    list<DirectedEdge>::const_iterator cbegin(v){
        return adj[v].cbegin();
    }
    list<DirectedEdge>::const_iterator cend(v){
        return adj[v].cend();
    }
};

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};
    

class DijkstraSPT {
    DirectedEdge* edgeTo;
    double* distanceTo;
    indexMinPQ pq(mycomparison(true));
    
    void relax(const DirectedEdge& e){
        int v = e.from();
        int w = e.to(v);
        if (distanceTo[w] > distanceTo[v] + e.weight()){
            distanceTo[w] = distanceTo[v] + e.weight();
            edgeTo[w] = e;
            if (pq.contains(w))pq.decreaseKey(w, distanceTo[w]);
            else pq.insert(w, distanceTo[w]);
        }
    }           
    
public:
    DijkstraSPT(const EdgeWeightedDiGraph& G, int s){
        edgeTo = new DirectedEdge[G.V()];
        distanceTo = new DirectedEdge[G.V()];
        
        for (int i=0; i<G.V(); ++i){
            distanceTo[i] = DBL_MAX;
        }
        
        distanceTo[s] = 0.0;        
        pq.insert(s, 0.0);
        while (!pq.empty()){
            int v = pq.deleteMin();
            for (auto it = G.cbegin(v); it != G.cend(v); ++it)
                relax(*it);
        }
    }
        
    