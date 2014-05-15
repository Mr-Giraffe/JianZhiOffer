#include <cstdio>
using namespace std;

int num1(int n){
    int count = 0, tp_count=0;
    unsigned int flag = 1;
    while(flag<=n){
        if(n & flag)
            count++;
        flag = flag << 1;
        tp_count++;
    }
    return count;
}

int num2(int n){
    int count = 0;
    while(n){
        n = (n-1)&n;
        count++;
    }
    return count;
}

int main(){
    int n;
    while(~scanf("%d", &n)){
        printf("num2:%d\n", num2(n));
        printf("num1:%d\n", num1(n));
    }
    return 0;
}
