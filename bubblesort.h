#include "sort.h"

template <class T> class Bubblesort:public sort<T>{
    public:
        void sort_array(T*, int);
};

template <class T>
void Bubblesort<T>::sort_array(T* a, int length){
    int i, j, k, h;
    for(i=length-1;i>0;i=k){
        for(j=0, k=0;j<i;j++){
            if(a[j]>a[j+1]){
                this->swap(a[j], a[j+1]);
                k = j;
            }
        }
    }
}
