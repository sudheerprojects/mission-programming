#include <iostream>
#include <limits.h>

using namespace std;

int min(int x, int y) { return (x < y)? x: y; } 

int getMinValue(int* st, int qs, int qe, int ss, int se, int si){
    if (ss>=qs && se<=qe)
        return st[si];
    else if (qe<ss || qs>se)
        return INT_MAX;
    
    int mid = ss + (se-ss)/2;
    return min(getMinValue(st, qs, qe, ss, mid, 2*si+1), getMinValue(st, qs, qe, mid+1, se, 2*si+2));
}

void constructST(int* arr, int* st, int ss, int se, int si){
    if (ss == se){
        st[si] = ss;
        return;
    }
    
    int mid = ss + (se-ss)/2;
    constructST(arr, st, ss, mid, 2*si+1);
    constructST(arr, st, mid+1, se, 2*si+2);
    st[si] = min(st[2*si+1], st[2*si+2]);
}

int main(){
    int arr[] = {4, 45, 6, 10, 8, 2};
    int n = size(arr)/size(arr[0]);
    
    int x = ceil(log2(n));
    int sn = int(pow(2, n))*2 - 1;
    int* st = new int[sn];
    for (int i=0; i<sn; ++i)
        st[i] = INT_MAX;
    constructST(arr, st, 0, n-1, 0);
    cout<<"Minimum value in the range (1, 4):"<<getMinValue(st, 1, 4, 0, n-1, 0)<<endl;
    return 0;
}
