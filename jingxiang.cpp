#include <stdexcept>
using std::runtime_error;

struct tree{
    int m_value;
    tree* m_lchild;
    tree* m_rchild;
};

tree* mirror(tree* root){
    if(root == NULL)
        throw runtime_error("invalide parameter");
    tree* temp = root->m_lchild;
    root->m_lchild = root->rchild;
    root->rchild = temp;
    if(root->lchild != NULL)
        mirror(root->lchild);
    if(root->rchild != NULL)
        mirror(root->rchild);
    return root;
}
