#include<iostream>

using namespace std;
#define N 10

void merge(int []arr, int []aux, int lo, int mid, int hi){
    for (int k=lo; k<=hi; ++k){
        aux[k] = arr[k];
    }
    int i = lo;
    int j = mid+1;
    for (int k=lo; k<=hi; ++k){
        if (i>mid) arr[k] = aux[j++];
        else if(j>hi) arr[k] = aux[i++];
        else if(aux[j] < aux[i]) arr[k] = aux[j++];
        else  arr[k] = aux[i++];
    }
}


void sort(int []arr, int []aux, int lo, int hi){
    if (hi>low){
        int mid = lo + (hi - lo)/2;
        sort(arr, aux, low, mid);
        sort(arr, aux, mid+1, hi);
        merge(arr, aux, lo, mid, hi);
    }
}
        

void MergeSort(int []arr, int n){
    int* aux = new int[n];
    sort(arr, aux, 0, n-1);
}

int main(){
    int Arr[N] = {28, 12, 32, 16, 5, 19, 10, 2, 8, 1};
    mergeSort(Arr, N);
}