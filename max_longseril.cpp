#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;

int max_serial(int *a, int length){
    if(a == NULL || length<=0)
        throw logic_error("invalide parameters");
    int m_max = a[0], c_max = a[0];
    for(int i=1;i<length;++i){
        if(c_max<=0)
            c_max = a[i];
        else
            c_max += a[i];
        if(c_max>m_max)
            m_max = c_max;
    }
    return m_max;
}

int main(){
    int n, a[10];
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<max_serial(a, n)<<endl;
    }
    return 0;
}
