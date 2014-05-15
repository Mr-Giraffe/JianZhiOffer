#include <iostream>
#include <stdexcept>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;
using std::qsort;

int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

bool is_continuous(int *card, int length){
    if(card == NULL || length<=1||length>=54)
        throw logic_error("invalide parameter");
    int zero_num = 0, gap = 0;
    qsort(card, length, sizeof(int), compare);
    for(int i=0;i<length;i++){
        if(card[i] == 0)
            ++zero_num;
    }
    int begin = zero_num;
    int end = length - 1;
    while(begin < end){
        if(card[begin] == card[begin+1])
            return false;
        gap += card[begin+1] - card[begin] - 1;
        ++begin;
    }
    if(gap>zero_num)
        return false;
    return true;
}
