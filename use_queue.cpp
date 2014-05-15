#include "stack_to_queue.cpp"
#include <cstdio>
using namespace std;

int main(){
    Queue<int> q;
    for(int i=0;i<5;i++)
        q.appendTail(i);
    for(int i=0;i<3;i++)
        printf("%d ", q.deleteHead());
    printf("\n***********\n");
    for(int i=6;i<10;i++)
        q.appendTail(i);
    for(int i=0;i<3;i++)
        printf("%d ", q.deleteHead());
    printf("\n***********\n");
    for(int i=0;i<3;i++)
        printf("%d ", q.deleteHead());
    printf("\n***********\n");
    return 0;
}
