#include<iostream>
using namespace std;

constexpr int MAX_M = 1e4+5;    //dataDefine
constexpr int MAX_T = 1e7+5;
int t,m,tc[MAX_M],v[MAX_M];
long long f[MAX_T];

int main(){
    cin >> t >> m;  //input
    for(int i=1;i<=m;i++)   cin >> tc[i] >> v[i];

    for(int i=1;i<=m;i++)   //core
        for(int c=tc[i];c<=t;c++)
            if((f[c - tc[i]] + v[i]) > f[c])    f[c] = f[c - tc[i]] + v[i];

    cout << f[t];   //end
    return 0;
}