#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;

inline int get_tp_sum(int start, int end){
    return (start+end)*(end-start+1)/2;
}

inline void print_serial(int start, int end){
    for(int i=start;i<=end;i++)
        cout<<i<<" ";
    cout<<endl;
}

void conti_sum(int sum){
    if(sum<=2)
        throw logic_error("invalide parameter");
    int c_start = 1;
    while(c_start <= sum/2){
        int start = c_start;
        int end = c_start+1;
        while(start != end){
            int tp_sum = get_tp_sum(start, end);
            if(tp_sum < sum)
                ++end;
            else if(tp_sum > sum)
                ++start;
            else{
                print_serial(start, end);
                c_start = start+1;
                break;
            }
        }
    }
}

int main(){
    int sum;
    while(cin>>sum){
        conti_sum(sum);
    }
    return 0;
}
