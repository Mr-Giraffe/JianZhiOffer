#include <cstdio>
#include <stdexcept>
using namespace std;

int m, n, matr[100][200], t;

bool find(int matric[][200], int r, int c, int target){
    if(matric == NULL)
    {
        throw runtime_error("empty point");
        return false;
    }else if(r == n || c < 0)
        return false;
    if(matric[r][c] > target)
        return find(matric, r, c-1, target);
    else if(matric[r][c] < target)
        return find(matric, r+1, c, target);
    else
        return true;
}

int main(){
    while(~scanf("%d%d%d", &n, &m, &t)){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d", &matr[i][j]);
        printf("%d\n", find(&matr[0], 0, m-1, t));
    }
    return 0;
}
