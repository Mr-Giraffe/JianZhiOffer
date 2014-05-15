#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

inline void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *a, int start, int end){
    int i=start+1, j = end;
    int val = a[start];
    while(i<j){
        while(a[j]>=val&&j!=i)
            --j;
        while(i!=j&&a[i]<=val)
            ++i;
        if(i!=j)
            swap(a[i], a[j]);
    }
    swap(a[i], a[start]);
    return i;
}

void leatest_k(int *a, int length, int k){
    if(a == NULL || length <=0 || k<=0 || k>length)
        throw runtime_error("invalide parameter");
    int start = 0, end = length-1;
    int index = partition(a, start, end);
    while(index != k-1){
        if(index > k-1){
            end = index-1;
        }else{
            start = index+1;
        }
        index = partition(a, start, end);
    }
    for(int i=0;i<k;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int n, k, a[10];
    while(cin>>n>>k){
        for(int i=0;i<n;i++)
            cin>>a[i];
        leatest_k(a, n, k);
    }
    return 0;
}
