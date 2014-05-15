#include "sort.h"

template <class T> class Shellsort:public sort<T>{
    public:
        void sort_array(T*, int);
};

template <class T>
void Shellsort<T>::sort_array(T* a, int length){
    for(int h=length/2;h>0;h/=2){
        for(int j=h;j<length;j++){
           T key = a[j];
           int k = j-h;
           for(;k>=0&&a[k]>a[k+h];k-=h){
                this->swap(a[k], a[k+h]);
           }
           if(a[k+h] != key)
                a[k+h] = key;
        }
    }
}
