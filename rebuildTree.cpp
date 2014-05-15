#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct binary_tree{
    int m_value;
    binary_tree* m_pLeft;
    binary_tree* m_pRight;
};

void preOrder(const binary_tree* root){
    if(root != NULL){
        printf("%d ", root->m_value);
        preOrder(root -> m_pLeft);
        preOrder(root -> m_pRight);
    }
}

void postOrder(const binary_tree* root){
    if(root != NULL){
        postOrder(root -> m_pLeft);
        postOrder(root -> m_pRight);
        printf("%d ", root -> m_value);
    }
}

void inOrder(const binary_tree* root){
    if(root != NULL){
        inOrder(root -> m_pLeft);
        printf("%d ", root -> m_value);
        inOrder(root -> m_pRight);
    }
}

void cengOrder(binary_tree* root){
    if(root == NULL)
        return;
    queue<binary_tree*> tp;
    tp.push(root);
    do{
        binary_tree* tp_root = tp.front();
        tp.pop();
        printf("%d ", tp_root -> m_value);
        if(tp_root -> m_pLeft != NULL)
            tp.push(tp_root -> m_pLeft);
        if(tp_root -> m_pRight != NULL)
            tp.push(tp_root -> m_pRight);
    }while(!tp.empty());
    printf("\n");
}

binary_tree* rebuild_tree(char* pre, char* mid, int len){
    if(len == 0)
        return NULL;
    binary_tree* bt = new binary_tree();
    bt -> m_value = pre[0] - '0';
    long int proot = strchr(mid, pre[0]) - mid;
    bt -> m_pLeft = rebuild_tree(pre+1, mid, proot);
    bt -> m_pRight = rebuild_tree(pre+proot+1, mid+proot+1, len-proot-1);
    return bt;
}

int main(){
    char p1[20] = "12473568";
    char p2[20] = "47215386";
    binary_tree* root = rebuild_tree(p1, p2, strlen(p1));
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    cengOrder(root);
    return 0;
}
