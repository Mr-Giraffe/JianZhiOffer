#ifndef SORT_H
#define SORT_H
template <class T> class sort{
    public:
        void swap(T &a, T &b){
            T temp = a;
            a = b;
            b = temp;
        }
        virtual void sort_array(T*, int) = 0;
};
#endif
