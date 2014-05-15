#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;

void just_sum(int *a, int length, int sum, int *num1, int *num2){
    if(a == NULL || length <=0)
        throw logic_error("invalide parameter");
    int before = 0, end = length-1;
    while(before != end){
        int tp_sum = a[before] + a[end];
        if(tp_sum == sum){
            *num1 = a[before];
            *num2 = a[end];
            return;
        }
        else if(tp_sum<sum)
            ++before;
        else{
            --end;
        }
    }
    throw logic_error("no such sums");
}

int main(){
    int a[100], n, sum;
    while(cin>>n>>sum){
        for(int i=0;i<n;i++)
            cin>>a[i];
        int num1 = 0, num2 = 0;
        just_sum(a, n, sum, &num1, &num2);
        cout<<num1<<" "<<num2<<endl;
    }
    return 0;
}
