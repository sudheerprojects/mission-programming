#include <iostream>
#include <random>

#define N 10
using namespace std;

void swap(int &a, int& b){
    int temp = b;
    b = a;
    a = temp;
}

int partition(int []arr, int lo, int hi){
    int i = lo, j = hi +1;
    while (true){
        while (arr[++i] < arr[lo]){
            if (i==hi) break;
        }
        while (arr[--j) > arr[lo]){
            if (j==lo) break;
        }
        if (i>=j) break;
        swap(a[i], a[j]);
    }
    swap(a[lo], a[j]);
    return j;
};

void sort(int []arr, int lo, int hi){
    if (lo>=hi) return;
    
    int pi = partition(arr, lo, hi);
    sort(arr, lo, pi-1);
    sort(arr, pi+1, hi);
}

void shuffle(int [arr], int N){
    std::default_random_engine generator;
    for (int i=0; i<N; ++i){
        std::uniform_int_distribution<int> distribution(0,i);
        int r = distribution(generator);
        swap(arr[i], arr[r]);
    }
}

void quikSort(int []arr, int N){
    shuffle(arr, N);
    sort(arr, 0, N-1);
}

int main(){
    int Arr[N] = {28, 12, 32, 16, 5, 19, 10, 2, 8, 1};
    quikSort(Arr, N);
}

            