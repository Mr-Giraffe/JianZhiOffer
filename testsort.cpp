#include "selectsort.h"
#include "insertsort.h"
#include "bubblesort.h"
#include "shellsort.h"
#include "heapsort.h"
#include <cstdio>
using namespace std;

void print_array(int a[], int length){
    for(int i=0;i<length;i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int data1[] = {5, 4, 6, 9, 0, 4, 2, 8};
    int data2[] = {4, 4, 4, 4, 4, 4, 4, 4};
    int data3[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int data4[] = {8, 7, 6, 5, 4, 3, 2, 1};

    sort<int>* fs = new Heapsort<int>;
    int size = sizeof(data1)/sizeof(data1[0]);

    fs->sort_array(data1, size);
    fs->sort_array(data2, size);
    fs->sort_array(data3, size);
    fs->sort_array(data4, size);
    print_array(data1, size);
    print_array(data2, size);
    print_array(data3, size);
    print_array(data4, size);
}
