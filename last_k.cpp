#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

struct ListNode{
    int m_value;
    ListNode* m_next;
};

int last_k(ListNode** head, int k){
    if(*head == NULL || head == NULL || k<=0)
        throw runtime_error("invalide parameters");
    ListNode *left, *right;
    left = right = *head;
    int i=1;
    for(; i<k && right->m_next!=NULL;i++)
        right = right->m_next;
    if(i<k)
        throw runtime_error("the last k doesnot exist");
    while(right->m_next != NULL){
        right = right->m_next;
        left = left->m_next;
    }
    return left->m_value;
}

ListNode* build_list(int t){
    ListNode* head = NULL;
    for(int i=t;i>0;--i){
        ListNode* node = new ListNode();
        node->m_next = head;
        node->m_value = i;
        head = node;
    }
    return head;
}

void reales_node(ListNode** head){
    ListNode* d_node = (*head)->m_next;
    if(d_node->m_next != NULL){
        (*head)->m_next = d_node->m_next;
        delete d_node;
        d_node = 0;
    }
    if(*head != NULL){
        delete *head;
        *head = 0;
    }
}

int main(){
    int k;
    while(cin>>k){
        ListNode* head = build_list(10);
        int value = last_k(&head, k);
        cout<<value<<endl;
        reales_node(&head);
    }
}
