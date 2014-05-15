#include "sort.h"

template <class T> class Insertsort:public sort<T>{
    public:
        void sort_array(T*, int);
};

template <class T> 
void Insertsort<T>::sort_array(T* a, int length){
    for(int i=1;i<length;i++){
        T key = a[i];
        int j=i-1;
        for(;j>=0&&a[j]>key;j--){
            this->swap(a[j+1],a[j]);
        }
        if(a[j+1] != key)
            a[j+1] = key;
    }
}
