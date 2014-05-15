#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::memset;
using std::logic_error;
using std::pow;

void get_percentage(int n, int face_point){
    if(n<=0||face_point<=0)
        throw logic_error("invalide parameter");
    int *times[2];
    int size = n*face_point+1;
    times[0] = new int[size];
    times[1] = new int[size];
    for(int i=1;i<=face_point;i++)
        times[0][i] = 1;
    memset(times[0]+face_point+1, 0, sizeof(size-face_point));
    memset(times[1], 0, sizeof(size));
    int flag = 1;
    for(int k=2;k<=n;++k){
        int old_flag = (flag+1)%2;
        for(int i=k;i<=k*face_point;++i){
            times[flag][i] = 0;
            for(int j=1;j<=face_point&&j<=i-k+1;++j)
                times[flag][i] += times[old_flag][i-j];
        }
        flag = old_flag;
    }
    flag = (flag+1)%2;
    double max = pow(face_point, n);
    int res_length = (face_point-1)*n+1;
    for(int i=0;i<res_length;++i){
        cout<<n+i<<" : "<<times[flag][n+i]/max<<endl;
    }
}

int main(){
    int n;
    while(cin>>n){
        get_percentage(n, 6); 
    }
    return 0;
}
