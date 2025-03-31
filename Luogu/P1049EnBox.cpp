#include<iostream>
using namespace std;

constexpr int MAX_N = 1e2+5;
constexpr int MAX_V = 2e4+5;
int V, n;
int v[MAX_N], f[MAX_V];

int main(){
    cin >> V >> n;
    for(int i=1; i<=n; i++) cin >> v[i];
    for(int i=1; i<=V; i++) f[i] = 0;

    for(int i=1; i<=n; i++)
        for(int j=V; j>=v[i]; j--)
            if(f[j-v[i]] + v[i] > f[j])    f[j] = f[j-v[i]] + v[i];
    
    cout << V - f[V];
    return 0;
}