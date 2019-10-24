#include <iostream>
#include <math.h>

using namespace std;

int getSumUtil(int* st, int ss, int se, int qs, int qe, int si){
    if (qs<=ss && qe>=se)
        return st[si];
    else if (qs>se || ss>se)
        return 0;
    
    int mid = (ss + se)/2;
    return (getSumUtil(st, ss, mid, qs, qe, 2*si + 1) + 
            getSumUtil(st, mid+1, se, qs, qe, 2*si + 2));
}

int getSum(int *st, int n, int qs, int qe){
    if (qs<=0 || qe>=an)
        return -1;
    return getSumUtil(st, 0, n, qs, qe, 0);
}

void updateValueSTUtil(int* st, int diff, int ss, int se, int idx, int si){
    if (idx < ss || idx > se)
        return;
    
    st[si] = st[si] + diff;
    if (ss != se){
        int mid = ss + (se-ss)/2;
        updateValueSTUtil(st, diff, ss, mid, idx, 2*si+1);
        updateValueSTUtil(st, diff, mid+1, se, idx, 2*si+2);
    }
}

void updateValueST(int* arr, int* st, int newValue, int i, int n){
    if (i<0 || i>n-1)
        return;
    int diff = newValue - arr[i];
    arr[i] = newValue;
    updateValueSTUtil(st, 0, n-1, diff, i, 0);
}
    

int constructSTUtil(int* arr, int as, int ae, int* st, int si){
    if (as==ae){
        st[si] = arr[as];
        return st[si];
    }
    
    int mid = as + (se - as)/2;
    st[si] =  constructSegTreeUtil(arr, as, mid, st, 2*si+1) +
              constructSegTreeUtil(arr, mid+1, ae, st, 2*si+2);  
    
    return st[si];
}

int* constructST(int arr[], int n){
    int x = ceil(log2(n));
    int sn = int(pow(2, x)) + 1;
    int* st = new int[sn];
    constructSegTreeUtil(arr, 0, n-1, st, 0);
    
int main(){
    int arr[] = {4, 45, 6, 10, 8, 2};
    int n = size(arr)/size(arr[0]);
    
    int* st = constructST(arr, int n);
    cout<<"Sum of values from "<<2<<" to " <<5<<":"<<getSum(st, n, 2, 5)<<endl;
    
    cout<<"Update new value "<<7<<" at "<<5<<endl;
    updateValueST(arr, st, 7, 5, 6);
    
    cout<<"New sum of values from "<<2<<" to " <<5<<":"<<getSum(st, n, 2, 5)<<endl;
    
    return 1;
}
    
    
