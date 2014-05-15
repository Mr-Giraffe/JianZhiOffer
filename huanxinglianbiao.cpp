#include <iostream>
#include <stdexcept>
#include <list>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;
using std::list;

int last_number(unsigned int n, unsigned int m){
    if(n<1||m<1)
        throw logic_error("invalide parameter");
    list<int> num;
    for(int i=0;i<n;++i)
        num.push_back(i);
    list<int>::iterator it = num.begin();
    int count = 0;
    while(count<n-1){
        ++count;
        for(int i=1;i<m;++i){
            ++it;
            if(it == num.end())
                it = num.begin();
        }
        list<int>::iterator next = ++it;
        if(next == num.end())
            next = num.begin();
        num.erase(--it);
        it = next;
    }
    return (*it);
}

int last_number2(unsigned int n, unsigned int m){
    if(n<1||m<1)
        throw logic_error("invalide parameter");
    int last = 0;
    for(int i=2;i<=n;++i){
        last = (last+m)%i;
    }
    return last;
}

int main(){
    int n, m;
    while(cin>>n>>m){
        cout<<last_number(n, m)<<endl;
        cout<<last_number2(n, m)<<endl;
    }
    return 0;
}
