#include <cstdio>
#include <stdexcept>
using namespace std;

struct ListNode{
    int m_value;
    ListNode* m_next;
};

void delete_node(ListNode **head, ListNode *d_node){
    if(!*head || !head || !d_node)
        throw runtime_error("Invalid parameters");
    if(d_node -> m_next != NULL){
        ListNode *d_next = d_node -> m_next;
        d_node -> m_value = d_next -> m_value;
        d_node -> m_next = d_next -> m_next;
        delete d_next;
        d_next = NULL;
    }else if(*head == d_node){
        delete *head;
        *head = NULL;
        d_node = NULL;
    }else{
        ListNode *d_next = *head;
        while(d_next -> m_next != d_node)
            d_next = d_next -> m_next;
        d_next -> m_next = NULL;
        delete d_node;
        d_node = NULL;
    }
}
