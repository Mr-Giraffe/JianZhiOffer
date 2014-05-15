#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    char s[20] = "hello world!";
    printf("%ld\n", strchr(s, 'w')-s);
}
