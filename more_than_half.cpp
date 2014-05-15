#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

bool more_than_half(int *a, int length){
    if(a == NULL || length <=0)
        throw runtime_error("invalide parameter");
    int c_value = a[0], times = 1;
    for(int i=1;i<length;++i){
        if(times == 0){
            c_value = a[i];
            times = 1;
        }else if(a[i] == c_value)
            times++;
        else{
            times--;
        }
    }
    if(times<=0)
        return false;
    return true;
}

int main(){
    int n, a[100];
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<more_than_half(a, n)<<endl;
    }
    return 0;
}
