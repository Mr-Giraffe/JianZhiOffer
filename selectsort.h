#include "sort.h"
#include <stdexcept>
template <class T> class Selectsort:public sort<T>{
    public:
        void sort_array(T*, int);
};

template <class T> void Selectsort<T>::sort_array(T* a, int length){
    if(a == NULL || length == 0)
        throw std::runtime_error("invalide parameters");
    for(int i=0;i<length-1;i++){
        int min = i;
        for(int j=i+1;j<length;j++){
            if(a[j] < a[min])
                min = j;
        }
        if(min != i)
            this->swap(a[i], a[min]);
    }
}
