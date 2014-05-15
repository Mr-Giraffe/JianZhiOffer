#include <stdexcept>
#include <cmath>
using std::logic_error;
using std::max;
using std::min;

struct listNode{
    int m_value;
    listNode *m_next;
};

listNode* common_node(listNode *a, listNode *b){
    if(a == NULL || b == NULL){
        throw logic_error("invalide parameter");
    }
    int alen = 1, blen = 1;
    while(a->m_next){
        ++alen;
        a = a->m_next;
    }
    while(b->m_next){
        ++blen;
        b = b->m_next;
    }
    listNode *sh = a, *lo = b;
    int delta = blen - alen;
    if(alen > blen){
        sh = b;
        lo = a;
        delta = alen - blen;
    }
    for(int i=0;i<delta;i++)
        lo = lo->m_next;
    while(lo){
        if(sh == lo)
            return sh;
        else{
            sh = sh->m_next;
            lo = sh->m_next;
        }
    }
    throw logic_error("no common node");
}
