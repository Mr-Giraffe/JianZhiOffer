#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <set>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;
using std::string;
using std::multiset;
using std::stringstream;
struct comp{
    bool operator()(const string &s1, const string &s2) const{
        string s3 = s1+s2;
        string s4 = s2+s1;
        return s3<s4;
    }
};

typedef multiset<string, comp> sset;
typedef sset::const_iterator ssetIter;

void comb_min_number(int *a, int length){
    sset snum;
    for(int i=0;i<length;i++){
        string s;
        stringstream ss;
        ss<<a[i];
        ss>>s;
        snum.insert(s);
    }
    ssetIter si = snum.begin();
    for(;si != snum.end();si++)
        cout<<(*si);
    cout<<endl;
}

int main(){
    int n, a[10];
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>a[i];
        comb_min_number(a, n);
    }
    return 0;
}
