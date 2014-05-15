#include <iostream>
#include <stdexcept>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::strlen;
using std::logic_error;

void print_array(int a[][4], int s, int m, int n){
    if(a == NULL)
        throw logic_error("invalid parameter");
    if(m<=0 && n<=0)
        return;
    int i=s, j=s+1;
    for(;i<m+s;i++)
        cout<<a[s][i]<<" ";
    if(m>0)
        --i;
    for(;j<n+s;j++)
        cout<<a[j][i]<<" ";
    if(n>0)
        --j;
    for(int k=i-1;k>=s&&j!=s;k--)
        cout<<a[j][k]<<" ";
    for(int k=j-1;k>s;k--)
        cout<<a[k][s]<<" ";
    cout<<endl;
    print_array(a, s+1, m-2, n-2);
}

int main(){
    int a[3][4] = {{1,3,4,5},
        {6,7,8,9},{13,15,16,19}};
    print_array(a, 0, 4, 3); 
    return 0;
}
