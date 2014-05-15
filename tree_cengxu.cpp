#include <stdexcept>
#include <queue>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::logic_error;

struct tree{
    int m_value;
    tree *m_lchild;
    tree *m_rchild;
};
void level_order(tree *root){
    if(root == NULL)
        return;
    queue<tree*> q;
    q.push(root);
    while(!q.empty()){
        tree* c_root = q.front();
        q.pop();
        cout<<c_root->m_value<<endl;
        if(c_root->m_lchild!=NULL)
            q.push(c_root->m_lchild);
        if(c_root->m_rchild!=NULL)
            q.push(c_root->m_rchild);
    }
}
