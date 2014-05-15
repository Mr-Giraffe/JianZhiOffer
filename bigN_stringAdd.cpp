#include <cstdio>
#include <cstring>
using namespace std;

bool increase(char* num, int length){
    int c = num[length-1]-'0'+1 >= 10?1:0;
    num[length-1] = c?'0':num[length-1]+1;
    int c_bit = length-2;
    while(c && c_bit>=0){
        c = num[c_bit]-'0'+c >= 10?1:0;
        num[c_bit] = c?'0':num[c_bit]+1;
        --c_bit;
    }
    if(c && c_bit<0)
        return false;
    else
        return true;
}

void print_bigN(char* num, int length){
    int c_bit = 0;
    while(num[c_bit] == '0')
        ++c_bit;
    for(int i=c_bit;i<length;i++)
        printf("%c", num[i]);
    printf("\n");
}

void printAll(int n){
    if(n<=0)
        return;
    char* num = new char[n];
    memset(num, '0', n);
    //num[n] = '\0';
    while(increase(num, n)){
        print_bigN(num, n);
    }
    delete [] num;
}

int main(){
    int n;
    while(~scanf("%d", &n))
        printAll(n);
    return 0;
}
