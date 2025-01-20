#include<iostream>
using namespace std;

constexpr int MAX = 400+5;  //dataDefine
constexpr int INTMAX = 2e9;
int i, j, k, len, n;
int rocks[MAX], sum[MAX], f[MAX][MAX], l[MAX][MAX];

int main(){
    cin >> n;   //input
    for(i=1;i<=n;i++)   cin >> rocks[i];

    for(i=0;i<2*n;i++)      fill(f[i],f[i]+2*n+1,0);      //process
    for(i=0;i<2*n;i++){
        fill(l[i],l[i]+2*n+1,INTMAX);
        l[i][i] = 0;
    }
    l[0][0] = INTMAX;
    for(i=1;i<n;i++)       rocks[i+n] = rocks[i];
    sum[0] = 0;
    for(i=1;i<=2*n;i++)     sum[i] = sum[i-1] + rocks[i];

    for(len=2;len<=n;len++)     //core
        for(i=1;i<=2*n-len;i++){
            j = i + len - 1;
            for(k=i;k<j;k++){
                f[i][j] = max(f[i][j], f[i][k] + f[k+1][j] + sum[j] - sum[i-1]);
                l[i][j] = min(l[i][j], l[i][k] + l[k+1][j] + sum[j] - sum[i-1]);
            }
        }

    for(i=1;i<=n;i++){  //output: max
        if(f[0][0] < f[i][i+n-1]) f[0][0] = f[i][i+n-1];
        if(l[0][0] > l[i][i+n-1]) l[0][0] = l[i][i+n-1];
    }   
    cout << l[0][0] << endl;
    cout << f[0][0] << endl;
    return 0;
}