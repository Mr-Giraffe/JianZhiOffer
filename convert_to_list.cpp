#include <stdexcept>
#include <iostream>
#include "tree.h"
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;

void convert(tree *root, tree** list){
    if(root->m_pLeft != NULL){
        convert(root->m_pLeft, list);
    }
    cout<<"*"<<root->m_value<<endl;
    if(*list == NULL){
        *list = root;
    }else{
        (*list)->m_pRight = root;
        root->m_pLeft = *list;
        *list = root;
    }
    if(root->m_pRight != NULL){
        convert(root->m_pRight, list);
    }
}

int main(){
    int n, a[10];
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>a[i];
        tree* root = build_tree(a, 0, n);
        tree* list=NULL;
        convert(root, &list);
        while(list->m_pLeft!=NULL){
            cout<<list->m_value<<" ";
            list = list->m_pLeft;
        }
        cout<<endl;
    }
    return 0;
}
