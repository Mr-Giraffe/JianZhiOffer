#include <cmath>
using std::max;

struct tree{
    int m_value;
    tree* m_pLeft;
    tree* m_pRight;
};

int get_height(tree* root){
    if(root == NULL)
        throw logic_error("invalide parameter");
    if(root->pLeft == NULL && root->pRight == NULL)
        return 1;
    int left = 0, right = 0;
    if(root->pLeft != NULL)
        left = get_height(root->pLeft);
    if(root->pRight != NULL)
        right = get_height(root->pRight);
    return max(left, right)+1;
}

