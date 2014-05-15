#include <stack>
#include <cstdio>
using namespace std;

struct LikedList{
    int m_kValue;
    LikedList* m_next;
};

void print_list(LikedList** head){
    if(head == NULL || *head == NULL)
        return;
    LikedList* p = *head;
    stack<int> s;
    do{
        s.push(p -> m_kValue);
        p = p->m_next;
    }while(p != NULL);
    while(!s.empty()){
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

void print_list2(LikedList* head){
    if(head == NULL)
        return;
    print_list2(head->m_next);
    printf("%d ", head->m_kValue);
}

void add_elems(LikedList** head, int value){
    LikedList* p = new LikedList();
    p -> m_kValue = value;
    p -> m_next = NULL;
    if(*head == NULL){
        *head = p;
    }
    else{
        LikedList* pp = *head;
        for(;pp->m_next != NULL;pp = pp-> m_next);
        pp -> m_next = p;
    }
}

void remove_elems(LikedList** head, int rValue){
    LikedList* rp = NULL;
    if((*head)->m_kValue == rValue){
        rp = *head;
        *head = (*head)->m_next;
    }else{
        LikedList* pp = *head;
        while(pp ->m_next != NULL && pp->m_next->m_kValue != rValue)
            pp = pp -> m_next;
        if(pp ->m_next == NULL) return;
        rp = pp -> m_next;
        pp -> m_next = pp -> m_next -> m_next;
    }
    if(rp != NULL){
        delete rp;
        rp = NULL;
    }
}

int main(){
    LikedList* head = NULL;
    for(int i=0;i<10;i++){
        add_elems(&head, i);
    }
    LikedList* p = head;
    print_list2(head);
    printf("\n");
    for(int i=10;i>0;i--)
        remove_elems(&head, i);
    print_list2(head);
}


