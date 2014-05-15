#include <cstdio>
#include <stdexcept>
using namespace std;

const double MIN = 0.0000001;

bool isEqual(double a, double b){
    if(a-b<MIN && b-a<MIN)
        return true;
    else
        return false;
}

double power_for_absExpo(double base, unsigned int absExpo){
    if(absExpo == 0)
        return 1;
    if(absExpo == 1)
        return base;
    double tp_res = power_for_absExpo(base, absExpo>>1);
    tp_res *= tp_res;
    if(absExpo & 1)
        tp_res *= base;
    return tp_res;
}


double power_for_double(double base, int exponent){
    if(isEqual(base, 0.0)){
        if(exponent<0)
            throw runtime_error("devide 0!");
        else if(exponent == 1)
            return 1;
        else
            return 0;
    }
    unsigned int absExpo = exponent>0?exponent:-exponent;
    double tp_res = power_for_absExpo(base, absExpo);
    if(exponent<0)
        tp_res = 1/tp_res;
    return tp_res;
}

int main(){
    double base;
    int exponent;
    while(~scanf("%lf%d", &base, &exponent)){
        printf("%lf\n", power_for_double(base, exponent));
    }
    return 0;
}
