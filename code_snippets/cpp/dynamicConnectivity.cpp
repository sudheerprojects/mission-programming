#include <iostream>

using namespace std;

class QuickFindUF{
private:
    int* id;
    int length;
public:
    QuickFindUF(int n){
        length = n;
        id = new int[n];
        for (int i=0; i<n; i++)
            id[i] = i;
    
    bool connected(int p, int q){
        return id[p] == id[q]
    }
    
    void Union(int p, int q){
        int idp = id[p];
        int idq = id[q];
        for (int i = 0; i<length; ++i){
            if (id[i] == idp)
                id[i] = idq;
        }
    }
};


class QuickUnionUF{
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
    QuickUnionUF(int n){
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

       