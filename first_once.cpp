#include <iostream>
#include <cstring>
#include <string>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::logic_error;
using std::memset;

char first_once(const char* s){
    if(s == NULL || *s == '\0')
        throw logic_error("invalide parameter");
    const char* hashKey = s;
    int hashTable[256];
    memset(hashTable, 0, sizeof(hashTable));
    while((*hashKey)!='\0'){
        ++hashTable[*(hashKey++)];
    }
    while((*s)!='\0'){
        if(hashTable[*s] == 1)
            return *s;
        s++;
    }
    throw logic_error("donot exist");
}

int main(){
    string s;
    while(getline(cin, s)){
        cout<<first_once(s.c_str())<<endl;
    }
    return 0;
}
