#include <iostream>
#include <vector>

using namespace std;

template <typename Key>
class mycomparison
{
  bool reverse;
public:
  mycomparison(bool revparam=false)
    {reverse=revparam;}
  bool operator() (const Key& lhs, const Key&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

template <typename Key, typename Container = vector<Key>, typename Compare = mycomparison<typename Container::value_type> >
class MinPQ{
    Container heap;
    Compare compare;
    int size;
    void sink(int k){
        while (2*k<=size){
            int j = 2*k;
            if (j<size && compare(heap[j+1], heap[j])) j++;
            if (compare(heap[k], heap[j])) break;
            exchange(j, k);
            k = j;
        }
    }
    void swim(int k){
        while(k>1 && compare(heap[k], heap[k/2])){
            exchange(k, k/2);
            k = k/2;
        }
    }
    void exchange(int i, int j){
        int t = heap[j];
        heap[j] = heap[i];
        heap[i] = t;
    }
    
public:
    MinPQ(const Compare& comp = Compare()):heap(), compare(comp), size(0){heap.push_back(Key());};
    void insert (const Key& key){
        heap.push_back(key);
        size++;
        swim(size);
    }
    Key delMin(){
        if (size == 0)
            return Key();
        Key min = heap[1];
        exchange(1, size);
        heap.pop_back();
        size = size-1;
        sink(1);
        return min;
    }
    bool empty(){
        return size == 1;
    }
    void print(){
        for (int i=0; i<=size; ++i){
            cout<<i<<"->"<<heap[i]<<" ";
        }
    }
} ;

template <typename Key, typename Container = vector<Key>, typename Compare = mycomparison<typename Container::value_type> >
class MaxPQ {
    Container heap;
    Compare compare;
    int size;
    void sink(int k){
        while (2*k<= size){
            int j = 2*k;
            if (j<size && compare(heap[j+1], heap[j])) j++;
            if (compare(heap[k], heap[j])) break;
            exchange(k, j);
            k = j;
        }
    }
    void swim(int k){
        while (k>1 && compare(heap[k], heap[k/2])){
            exchange(k, k/2);
            k = k/2;
        }
    }
    void exchange(int i, int j){
        int t = heap[j];
        heap[j] = heap[i];
        heap[i] = t;
    }
    
public:
    MaxPQ(const Compare& comp = Compare(true)):heap(), compare(comp), size(0){heap.push_back(Key());};
    void insert (const Key& key){
        heap.push_back(key);
        size++;
        swim(size);
    }
    Key delMax(){
        if (size == 0)
            return Key();
        Key max = heap[1];
        exchange(1, size);
        heap.pop_back();
        size = size-1;
        sink(1);
        return max;
    }
    bool empty(){
        return size == 0;
    }
    void print(){
        for (int i=0; i<=size; ++i){
            cout<<i<<"->"<<heap[i]<<" ";
        }
    }
};

template<typename Key, typename Compare=mycomparison<Key> >
class Heap{
private:
    static void sink(Key* pq, int k, int N, const Compare& compare = Compare(true)){
        while (2*k + 1<= N){
            int j = 2*k + 1;
            if (j<N && compare(pq[j+1], pq[j])) j++;
            if (compare(pq[k], pq[j])) break;
            exchange(pq, k, j);
            k = j;
        }
    }
    static void exchange(Key *pq, int i, int j){
        int t = pq[j];
        pq[j] = pq[i];
        pq[i] = t;
    }
        
public:
    static void sort(Key *pq, int N, const Compare& compare = Compare(true)){
        for (int k=N/2; k>=0; --k){
            sink(pq, k, N, compare);
        }
        while (N>0){
            exchange(pq, 0, N);
            N = N-1;
            sink(pq, 0, N, compare);
        }
    }
};  
    
int main(){
    int arr[6] = {15, 30, 25, 14, 50, 18}
    Heap<int, mycomparison<int>>::sort(arr, 5);
    for (int i=1; i<=5; ++i){
        cout<<arr[i]<<" ";
    return 1;
}
    
   
        
        
    
    