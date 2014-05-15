#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;

int spe_sum(int a, int b){
   int sum, carry;
   do{
       sum = a^b;
       carry = (a&b)<<1;
       a = sum;
       b = carry;
   }while(b);
   return a;
}

int main(){
    int a, b;
    while(cin>>a>>b){
        cout<<spe_sum(a,b)<<endl;
    }
    return 0;
}
