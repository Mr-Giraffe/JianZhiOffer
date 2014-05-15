#include <stdexcept>
using std::logic_error;

struct complax_list{
    int m_value;
    complax_list *m_next;
    complax_list *m_spling;
};

void double_list(complax_list *head){
    complax_list *pNode = head;
    while(pNode != NULL){
        complax_list *npNode = new complax_list;
        npNode->m_value = pNode->m_value;
        npNode->m_next = pNode->m_next;
        pNode->m_next = npNode;
        pNode = npNode->m_next;
    }
}

void copy_spling(complax_list *head){
    complax_list *pNode = head;
    while(pNode != NULL){
        complax_list *npNode = pNode->m_next;
        npNode->m_spling = pNode->m_spling->m_next;
        pNode = npNode->m_next;
    }
}

complax_list* reconnect(complax_list *head){
    complax_list *pNode = head;
    complax_list *nhead = head->m_next;
    complax_list *npNode = nhead;
    while(pNode){
        pNode->m_next = npNode->m_next;
        pNode = pNode->m_next;
        npNode->m_next = pNode->m_next;
        npNode = npNode->m_next;
    }
    return nhead;
}

complax_list* clone(complax_list *head){
    if(head == NULL)
        throw runtime_error("invalide parameter");
    double_list(head);
    copy_spling(head);
    return reconnect;
}
