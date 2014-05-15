#include <iostream>
using std::cin;
using std::cout;
using std::endl;

inline bool isEven(int t){
    return t%2 == 0;
}

inline void swap(int&a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void switch_array(int* a, int len, bool (*condition)(int)){
    int le = 0, ri = len - 1;
    while(le != ri){
        while(!condition(a[le]) && le != ri)
            ++le;
        while(ri != le && condition(a[ri]))
            --ri;
        if(le == ri)
            return;
        swap(a[le], a[ri]);
    }
}

int main(){
    int n, a[100];
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>a[i];
        switch_array(a, n, isEven);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}

