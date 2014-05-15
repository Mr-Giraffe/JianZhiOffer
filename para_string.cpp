#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::memset;
using std::runtime_error;

void perm(const string &s, int p, bool *vis, char* res){
    if(p == s.size()){
        res[p] = '\0';
        cout<<res<<endl;
        return;
    }
    for(int i=0;i<s.size();++i){
        if(!vis[i]){
            res[p] = s[i];
            vis[i] = 1;
            perm(s, p+1, vis, res);
            vis[i] = 0;
        }
    }
}

int main(){
    string s;
    while(cin>>s){
        bool vis[100];
        char res[100];
        memset(vis, 0, sizeof(vis));
        perm(s, 0, vis, res);
    }
    return 0;
}
