#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <string>
using namespace std;

inline void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *begin, char *end){
    while(begin<end){
        swap(begin, end);
        ++begin;
        --end;
    }
}

char* left_reverse(char *seq, int length, int pos){
    if(seq==NULL||length<=0||pos<0||pos>length)
        throw logic_error("invalide parameter");
    reverse(seq, seq+length-1);
    reverse(seq, seq+length-pos-1);
    reverse(seq+length-pos, seq+length-1);
    return seq;
}

int main(){
    string s;
    int pos;
    while(cin>>pos){
        getchar();
        getline(cin, s);
        char *res = left_reverse(const_cast<char*>(s.c_str()),
                s.length(), pos);
        cout<<res<<endl;
    }
}
