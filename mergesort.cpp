#include <iostream>
#include <cstring>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;
using std::memcpy;

int m_max = 0;
int merge(int *a, int *b, int la, int length){
    int temp[length];
    int i=0, j=0, k=0;
    int count = 0;
    while(i<la&&j<length-la){
        if(a[i]<=b[j])
            temp[k++] = a[i++];
        else{
            temp[k++] = b[j++];
            if(la-i>m_max)
                m_max = la-i;
            count += la-i;
        }
    }
    if(i<la)
        memcpy(temp+k, a+i, (la-i)*sizeof(int));
    else if(j<length-la)
        memcpy(temp+k, b+j, (length-la-j)*sizeof(int));
    memcpy(a, temp, length*sizeof(int));
    return count;
}

int merge_sort(int *a, int length){
    int left = 0, right = 0, mer = 0;
    if(length>=2){
        int m = length/2;
        left = merge_sort(a, m);
        right = merge_sort(a+m, length-m);
        mer = merge(a, a+m, m, length);
    }
    return left+right+mer;
}

int main(){
    int n, a[100];
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>a[i];
        int res = merge_sort(a, n);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        cout<<"pairs: "<<res<<endl;
        cout<<m_max<<endl;
    }
    return 0;
}
