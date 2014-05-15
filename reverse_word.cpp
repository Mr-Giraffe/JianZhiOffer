#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::logic_error;

inline void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *begin, char *end){
    while(begin < end){
        swap(begin, end);
        ++begin;
        --end;
    }
}

char* find_end(char *seq){
    char *begin = seq;
    while((*begin) != ' '&&(*begin)!='\0')
        ++begin;
    return begin;
}

char* reverse_word(char *seq, int length){
    if(seq == NULL || length <=0)
        throw logic_error("invalide parameter");
    reverse(seq, seq+length-1);
    char *start = seq;
    while(true){
        char *end = find_end(start);
        reverse(start, end-1);
        if(*end == '\0')
            break;
        start = end+1;
    }
    return seq;
}

int main(){
    string s;
    while(getline(cin, s)){
        char *res = reverse_word(const_cast<char*>(s.c_str()),s.length());
        cout<<res<<endl;
    }
}
