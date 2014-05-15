#include <stdexcept>
using std::runtime_error;

struct Tree{
    int m_value;
    Tree* lchild;
    Tree* rchild;
};

bool isAllCommon(Tree *h1, Tree *h2){
    if(h2 == NULL)
        return true;
    if(h1 == NULL)
        return false;
    if(h1->m_value != h2->m_value)
        return false;
    return isAllCommon(h1->lchild, h2->lchild)&&
        isAllCommon(h1->rchild, h2->rchild);
}

bool is_child(Tree *h1, Tree *h2){
    bool has_common = false;
    if(h1 != NULL && h2 != NULL){
        if(h1->m_value == h2->m_value)
            has_common = isAllCommon(h1, h2);
        if(!has_common)
            has_common = is_child(h1->lchild, h2);
        if(!has_common)
            has_common = is_child(h1->rchild, h2);
    }
    return has_common;
}
