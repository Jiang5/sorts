#include <iostream>
#include <queue>
#include <deque>
#include "Sort.h"

using namespace std;

    int* Sort::heapsort(int* a, int size){
        while(!heap.empty()) heap.pop();
        for(int i = 0; i < size; i++){
            heap.push(a[i]);
        }
        while(!de.empty()) de.pop_front();
        for(int i = 0; i < size; i++){
             de.push_front(heap.top());
             heap.pop();
        }
        for(int i = 0; i < size; i++){
            a[i] = de.front();
            de.pop_front();
        }
        return a;
    }
    
    int* Sort::quicksort(int* a, int high, int low) {
        int size = high + 1;
        int i = low, j = high;
        int tmp;
        int pivot = a[(low + high) / 2];
        while (i <= j) {
            while (a[i] < pivot)
                  i++;
            while (a[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = a[i];
                  a[i] = a[j];
                  a[j] = tmp;
                  i++;
                  j--;
            }
        }
      if (low < j)
            quicksort(a, j, low);
      if (i < high)
            quicksort(a, high, i);
    return a;
}

    void Sort::merge(int* a, int l, int m, int r){
        int i, j, k;
        int a1 = m - l + 1;
        int a2 =  r - m;
        int L[a1], R[a2];
        for (i = 0; i < a1; i++) L[i] = a[l + i];
        for (j = 0; j < a2; j++) R[j] = a[m + 1+ j];
        i = 0; 
        j = 0; 
        k = l; 
        while (i < a1 && j < a2){
            if (L[i] <= R[j]){
                a[k] = L[i];
                i++;
            }
            else{
                a[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < a1){
            a[k] = L[i];
            i++;
            k++;
        }
        while (j < a2){
            a[k] = R[j];
            j++;
            k++;
        }
    }

    int* Sort::mergesort(int *a, int l, int r){
        if (l < r){
            int m = l+(r-l)/2;
            mergesort(a, l, m);
            mergesort(a, m+1, r);
            merge(a, l, m, r);
        }
        return a;
    }
    
    
    
    
    
    
    
    int* Sort::sortA(int * a, int size){
        return heapsort(a,size);
    }
    
    int* Sort::sortB(int * b, int size){
        return mergesort(b,0,size-1);
    }
    
    int * Sort::sortOptimized(int * a, int size){
        
        return quicksort(a,size-1,0);
    }
 