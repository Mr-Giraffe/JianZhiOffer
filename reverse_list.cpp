#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

struct ListNode{
    int m_vaule;
    ListNode* m_next;
};

ListNode* reverse_list(ListNode* head){
    ListNode* pReversedHead = NULL;
    ListNode* pNode = head;
    ListNode* pPre = NULL;
    while(pNode != NULL){
        ListNode* pNext = pNode -> m_next;
        if(pNext == NULL)
            pReversedHead = pNode;
        pNode->m_next = pPre;
        pPre = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}
