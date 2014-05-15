#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;

int count_ones(int n){
    int count = 0;
    int current = 0, before = 0, after = 0;
    int i = 1;
    while((n/i) != 0){
        current = (n/i)%10;
        before = n/(i*10);
        after = n%i;
        if(current == 0)
            count += before*i;
        if(current == 1)
            count += before*i+after+1;
        if(current > 1)
            count += (before+1)*i;
        i *= 10;
    }
    return count;
}

int main(){
    int n;
    while(cin>>n){
        cout<<count_ones(n)<<endl;
    }
    return 0;
}
