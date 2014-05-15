#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;

bool isFirst(int *a, int p){
    if(p == 0 || a[p] != a[p-1])
        return true;
    return false;
}

bool isLast(int *a, int p, int n){
    if(p == n-1 || a[p] != a[p+1])
        return true;
    return false;
}

int findFirst(int *a, int start, int end, int value){
    if(start > end)
        return -1;
    int m = (end+start)/2;
    if(a[m] == value && isFirst(a, m))
        return m;
    else if(a[m]>=value)
        return findFirst(a, start, m-1, value);
    else 
        return findFirst(a, m+1, end, value);
}

int findLast(int *a, int start, int end, int value, int n){
    if(start > end)
        return -1;
    int m = (end+start)/2;
    if(a[m] == value && isLast(a, m, n))
        return m;
    else if(a[m]>value)
        return findLast(a, start, m-1, value, n);
    else 
        return findLast(a, m+1, end, value, n);
}

int findTimes(int *a, int n, int value){
    if(a == NULL||n<=0)
        throw logic_error("invalide parameter");
    int first = findFirst(a, 0, n-1, value);
    int end;
    if(first != -1)
        end = findLast(a, first, n-1, value, n);
    else
        throw logic_error("donot find this value");
    return end - first+1;
}

int main(){
    int n, value, a[100];
    while(cin>>n>>value){
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<findTimes(a, n, value)<<endl;
    }
    return 0;
}
