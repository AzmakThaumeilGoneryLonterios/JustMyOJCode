#include<iostream>
#include<bits/stdc++.h>
using namespace std;

constexpr int MAX_M = 1e3+5;    //dataDefine
int n,m,c[100][MAX_M],v[100][MAX_M],kc = 1,ki = 1,f[MAX_M];
struct stuff
{
    int c;
    int v;
    int k;
    bool operator<(stuff o)const{
        return k < o.k;
    }
}s[MAX_M];

int main(){
    cin >> m >> n;  //input
    for(int i=1;i<=n;i++)   cin >> s[i].c >> s[i].v >> s[i].k;
    sort(s+1,s+n+1);
    fill(f,f+m+1,0);

    for(int i=1;i<=n;i++){
        c[kc][ki] = s[i].c;
        v[kc][ki] = s[i].v;
        if(s[i].k == s[i+1].k){
            ki++;
        }else{
            c[kc][0] = ki;
            kc++;
            ki = 1;
        }
    }

    for(int g=1;g<kc;g++)   //core
        for(int j=m;j>=0;j--)
            for(int i=1;i<=c[g][0];i++)
                if(c[g][i]<=j)    f[j] = max(f[j],f[j - c[g][i]] + v[g][i]);

    cout << f[m];   //end
    return 0;
}