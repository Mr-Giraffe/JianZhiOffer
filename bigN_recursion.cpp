#include <cstdio>
#include <cstring>
using namespace std;



void print_bigN(char* num, int length){
    int c_bit = 0;
    while(num[c_bit] == '0')
        ++c_bit;
    for(int i=c_bit;i<length;i++)
        printf("%c", num[i]);
    printf("\n");
}

void rec_print(char* num, int length, int index){
    if(index == length-1){
        print_bigN(num, length);
        return;
    }
    for(int i=0;i<10;i++){
        num[index+1] = i+'0';
        rec_print(num, length, index+1);
    }
}

void print_all(int n){
    if(n<=0)
        return;
    char* num = new char[n];
    memset(num, '0', n);
    for(int i=0;i<10;i++){
        num[0] = '0'+i;
        rec_print(num, n, 0);
    }
}

int main(){
    int n;
    while(~scanf("%d", &n)){
        print_all(n);
    }
    return 0;
}
