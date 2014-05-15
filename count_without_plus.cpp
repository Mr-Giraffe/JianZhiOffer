#include <iostream>
#include <stdexcept>
using namespace std;

template <unsigned int n> class sum_no_plus{
    public:
        enum Value {N = sum_no_plus<n-1>::N+n};
};

template <> class sum_no_plus<1>{
    public:
        enum Value {N = 1};
};

int main(){
    cout<<sum_no_plus<100>::N<<endl;
    return 0;
}
