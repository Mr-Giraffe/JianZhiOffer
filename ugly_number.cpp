#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::vector;
using std::min;

int getMin(int a, int b, int c){
    int temp = min(a, b);
    return min(temp, c);
}

int getUglyNumbers(int index){
    if(index <= 0)
        throw runtime_error("invalide parameter");
    int *ugly_num = new int[index];
    ugly_num[0] = 1;
    int count = 1;
    int *twob = ugly_num, *threeb = ugly_num, *fiveb = ugly_num;
    while(count < index){
        int new_num = getMin((*twob)*2, (*threeb)*3, (*fiveb)*5);
        ugly_num[count++] = new_num;
        while(2*(*twob)<=new_num)
            ++twob;
        while(3*(*threeb)<=new_num)
            ++threeb;
        while(5*(*fiveb)<=new_num)
            ++fiveb;
    }
    int res = ugly_num[index-1];
    delete [] ugly_num;
    return res;
}

int main(){
    int index;
    while(cin>>index){
        cout<<getUglyNumbers(index)<<endl;
    }
    return 0;
}
