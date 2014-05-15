struct tree{
    int m_value;
    tree *m_pLeft;
    tree *m_pRight;
};

tree* build_tree(int *a, int s, int n){
    tree *root = new tree;
    root->m_value = a[s];
    if(2*s+1<n)
        root->m_pLeft = build_tree(a, 2*s+1, n);
    else
        root->m_pLeft = NULL;
    if(2*s+2<n)
        root->m_pRight = build_tree(a, 2*s+2, n);
    else
        root->m_pRight = NULL;
    return root;
}
