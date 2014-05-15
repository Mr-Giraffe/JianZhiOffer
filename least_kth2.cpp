#include <iostream>
#include <stdexcept>
#include <set>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::stdexcept;
using std::multiset;
using std::greater;
using std::vector;

typedef multiset<int, greater<int> > intSet;
typedef intSet::iterator intSetIter;

void least_kth(const vector<int>& a, intSet &snumbers, int k){
    vector<int>::const_iterater iter = a.begin();
    for(;iter != a.end();++iter){
        if(snumbers.size()<k)
            snumbers.insert(*iter);
        else{
            intSetIter m_iter = snumbers.begin();
            if((*iter)<(*m_iter)){
                snumbers.erase(m_iter);
                snumbers.insert(*iter);
            }
        }
    }
}
