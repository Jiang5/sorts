#include <queue>
#include <deque>

#ifndef SORT_H
#define SORT_H

class Sort{
  private:
    std::deque<int> de;
    std::priority_queue<int> heap;
    
    void swap(int i, int j, int *a);
    int* heapsort(int* a, int size);
    int* quicksort(int* a, int high, int low);
    int* mergesort(int *a, int l, int r);
    void merge(int*a, int l, int m, int r);

  public:
    int* sortA(int * a, int size);
    int* sortB(int * b, int size);
    int* sortOptimized(int * a, int size);
};

#endif