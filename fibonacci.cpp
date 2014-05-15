#include <cstdio>
#include <stdexcept>
using namespace std;

long long find_nth(int n){
    if(n<0)
        throw logic_error("invalid parameters");
    long long left = 0, right = 1, tp = 3, ans = left;
    if(n == 1)
        return left;
    if(n == 2)
        return right;
    while(tp < n){
        ans = right;
        right = left + right;
        left = ans;
        ++tp;
    }
    return left+right;
}

int main(){
    int n;
    while(~scanf("%d", &n)){
        printf("%lld\n", find_nth(n));
    }
    return 0;
}
