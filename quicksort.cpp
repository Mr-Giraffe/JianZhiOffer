#include <cstdio>
#include <stdexcept>
using namespace std;

inline void swap(int &a, int &b){ 
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int left, int right){
    int key = a[left];
    int i=left, j=right;
    while(1){
        while(a[j]>=key&&i<j)
            j--;
        while(i<j&&a[i]<=key)
            i++;
        if(i == j){
            if(a[i] != a[left])
                swap(a[i], a[left]);
            return i;
        }
        swap(a[i], a[j]);
    }
}

void quicksort(int a[], int left, int right){
    if(a == NULL)
        throw runtime_error("invalide parameter");
    if(left >= right)
        return;
    int key = partition(a, left, right);
    quicksort(a, left, key-1);
    quicksort(a, key+1, right);
}

int main(){
    int n, a[50];
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++)
            scanf("%d", &a[i]);
        quicksort(a, 0, n-1);
        for(int i=0;i<n;i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}
