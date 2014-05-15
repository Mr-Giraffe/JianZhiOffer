#include <cstdio>
#include <stdexcept>
using namespace std;

int d_min(int* num, int length){
    int min = num[0];
    for(int i=1;i<length;i++){
        if(num[i]<min)
            min = num[i];
    }
    return min;
}

int search_min(int* num, int length){
    if(num == NULL || length <= 0)
        throw logic_error("Invalid parameters");
    int l = 0, r = length - 1;
    while(num[l] >= num[r]){
        int mid = (l+r)/2;
        if(mid == l)
            return num[r];
        if(num[l] == num[mid] && num[l] == num[r])
            return d_min(num, length);
        if(num[l] <= num[mid])
            l = mid;
        else
            r = mid;
    }
    return num[l];
}

int main(){
    int n, num[100];
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++)
            scanf("%d", &num[i]);
        printf("%d\n", search_min(num, n));
    }
    return 0;
}
