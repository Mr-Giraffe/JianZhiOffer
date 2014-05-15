#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

struct tree{
    int m_value;
    tree* m_lchild;
    tree* m_rchild;
};

void good_path(tree* root, int val, int p, int *res){
    if(root == NULL)
        throw runtime_error("error");
    res[p++] = root->m_value;
    if(root->m_lchild == NULL&&root->m_rchild == NULL){
        if(val == res[p-1]){
            for(int i=0;i<p;i++)
                cout<<res[i]<<" ";
            cout<<endl;
        }
        return;
    }
    if(root->m_lchild != NULL)
        good_path(root->m_lchild, val-root->m_value, p, res);
    if(root->m_rchild != NULL)
        good_path(root->m_rchild, val-root->m_value, p, res);
}

tree* build_tree(int *a, int s, int n){
    tree *root = new tree;
    root->m_value = a[s];
    if(2*s+1<n)
        root->m_lchild = build_tree(a, 2*s+1, n);
    else
        root->m_lchild = NULL;
    if(2*s+2<n)
        root->m_rchild = build_tree(a, 2*s+2, n);
    else
        root->m_rchild = NULL;
}

int main(){
    int n, val, a[10], res[10];
    while(cin>>n>>val){
        for(int i=0;i<n;i++)
            cin>>a[i];
        tree *root = build_tree(a, 0, n);
        good_path(root, val, 0, res);
    }
    return 0;
}
