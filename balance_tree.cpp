

struct tree{
    int m_value;
    tree* m_pLeft;
    tree* m_pRight;
};

bool is_balance_tree(tree* root, int *ch){
    if(root == NULL){
        *ch = 0;
        return true;
    }
    int left = 0, right = 0;
    if(is_balance_tree(root->m_pLeft, &left)
            &&is_balance_tree(root->m_pRight, &right)){
        int delta = max(left, right) - min(left, right);
        if(delta <= 1 && delta >= -1){
            *ch = max(left, right)+1;
            return true;
        }
    }
    return false;
}
