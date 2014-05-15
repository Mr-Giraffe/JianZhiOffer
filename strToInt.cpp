#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

enum state {valide = 0, invalide};
int m_state = valide;
const int m_max = 0x7FFFFFFF;
const int m_min = 0x80000000;

int m_strToInt(const char* s, bool minus){
    long long num = 0;
    while(*s != '\0'){
        int flag = minus?-1:1;
        if(*s >='0' && *s<='9'){
            num = num*10+flag*(*s-'0');
        }else{
            return 0;
        }
        if((!minus&&num>m_max)||(minus&&num<m_min)){
            return 0;
        }
        ++s;
    }
    m_state = valide;
    return static_cast<int>(num);
}

int strToInt(const char* s){
    m_state = invalide;
    if(s == NULL || *s == '\0'){
        return 0;
    }
    bool minus = false;
    if(*s == '+')
        ++s;
    else if(*s == '-'){
        minus = true;
        ++s;
    }
    if(*s != '\0'){
        return m_strToInt(s, minus);
    }
    return 0;
}

int main(){
    string s;
    while(cin>>s){
        int res = strToInt(s.c_str());
        if(m_state == invalide)
            cout<<"invalide input"<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}
