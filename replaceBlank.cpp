#include <cstdio>
#include <cstring>
#include <stdexcept>
using namespace std;

char* replace(char s[], int l1)
{
    int l2;
    if(s == NULL)
        throw runtime_error("empty point");
    if(l1 == 0)
        return s;
    int tpBlank = 0;
    for(int i=0;i<l1;i++)
        if(s[i] == ' ')
            tpBlank++;
    l2 = l1 + 2*tpBlank;
    while(l1>=0){
        if(s[l1] == ' '){
            s[l2--] = '0';
            s[l2--] = '2';
            s[l2--] = '%';
        }
        else{
            s[l2--] = s[l1];
        }
        l1--;
    }
    return s;
}

int main(){
    char ss[100] = " aaaaa    ";
    char* s = replace(ss, strlen(ss));
    printf("%s\n", s);
    return 0;
}
