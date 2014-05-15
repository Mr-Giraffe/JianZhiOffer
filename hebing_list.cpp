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

ListNode* combine_list(ListNode* h1, ListNode* h2){
    if(h1 == NULL)
        return h2;
    if(h2 == NULL)
        return h1;
    ListNode *re_list = NULL;
    if(h1->m_value <= h2->m_value){
        re_list = h1;
        re_list->m_next = combine_list(h1->m_next, h2);
    }else{
        re_list = h2;
        re_list->m_next = combine_list(h1, h2->m_next);
    }
    return re_list;
}
