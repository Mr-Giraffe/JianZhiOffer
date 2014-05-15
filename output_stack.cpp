#include <iostream>
#include <stdexcept>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;
using std::stack;

bool is_output(int *a, int *b, int n){
    if(a == NULL || b == NULL)
        throw logic_error("invalide parameter");
    int p1 = 0, p2 = 0;
    stack<int> s;
    while(p1<n||!s.empty()){
        if(a[p1] == b[p2]){
            ++p1;
            ++p2;
        }else if(!s.empty()&&s.top()==b[p2]){
            s.pop();
            ++p2;
        }else if(p1==n&&s.top()!=b[p2]){
            break;
        }else{
            s.push(a[p1]);
            ++p1;
        }
    }
    if(p1==n&&p2==n&&s.empty())
        return true;
    return false;
}

int main(){
    int n, a[10], b[10];
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        cout<<is_output(a, b, n)<<endl;
    }
    return 0;
}
