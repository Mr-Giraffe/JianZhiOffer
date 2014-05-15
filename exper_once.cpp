#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;

int findOne(int num){
    int index = 0;
    while(!(num&1)&&(index<8*sizeof(int))){
        num = num>>1;
        ++index;
    }
    if(index == 8*sizeof(int))
        return -1;
    return index;
}

bool isBit(int num, int index){
    num = num >> index;
    return (num&1);
}

void exper_once(int *a, int length, int *num1, int *num2){
    if(a == NULL || length<=0)
        throw logic_error("invalide parameter");
    int forBit = 0;
    for(int i=0;i<length;i++)
        forBit ^= a[i];
    int indexOfOne = findOne(forBit);
    if(indexOfOne<0)
        throw logic_error("no two different numbers");
    for(int i=0;i<length;i++){
        if(isBit(a[i], indexOfOne))
            *num1 ^= a[i];
        else
            *num2 ^= a[i];
    }
}

int main(){
    int a[100], n, num1 = 0, num2 = 0;
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>a[i];
        exper_once(a, n, &num1, &num2);
        cout<<num1<<" "<<num2<<endl;
    }
}
