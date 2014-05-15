#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;

bool is_search_tree(int *tree, int n){
    if(tree == NULL || n<=0)
        throw logic_error("invalide parameters");
    if(n<=2)
        return true;
    if(n==3)
        return tree[0]<tree[2]&&tree[2]<tree[1];
    int i=0;
    for(;i<n-1&&tree[i]<tree[n-1];i++);
    bool lres = true, rres = true;
    if(i>0)
        lres = is_search_tree(tree, i);
    if(n-i-1>0)
        rres = is_search_tree(tree+i, n-i-1);
    return lres&&rres;
}

int main(){
    int n, tree[10];
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>tree[i];
        cout<<is_search_tree(tree, n)<<endl;
    }
}
