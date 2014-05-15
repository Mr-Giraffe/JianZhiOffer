#include "sort.h"

template <class T> class Heapsort:public sort<T>{
    public:
        void sort_array(T*, int);
    private:
        void maxHeapFixDown(T*, int, int);
        void makeMaxHeap(T*, int);
};

template <class T> 
void Heapsort<T>::sort_array(T* a, int length){
    makeMaxHeap(a, length);
    for(int i=length-1;i>0;i--){
        this->swap(a[0], a[i]);
        maxHeapFixDown(a, 0, i);
    }
}
template <class T>
void Heapsort<T>::makeMaxHeap(T* a, int length){
    for(int i=length/2-1;i>=0;i--)
        maxHeapFixDown(a, i, length);
}
template <class T>
void Heapsort<T>::maxHeapFixDown(T* a, int i, int length){
    int key = a[i];
    int j = 2*i+1;
    while(j<length){
        if(j+1<length&&a[j+1]>a[j])
            j++;
        if(a[j] <= key)
            break;
        a[i] = a[j];
        i = j;
        j = 2*i+1;
    }
    a[i] = key;
}
