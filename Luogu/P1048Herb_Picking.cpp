#include<iostream>
using namespace std;

constexpr int MAX = 1e3+5;
int T, M;
int tc[MAX], v[MAX];
long f[MAX];

int main(){
    cin >> T >> M;
    for(int i=1; i<=M; i++) cin >> tc[i] >> v[i];
    for(int i=1; i<=M; i++) f[i] = 0;

    for(int i=1; i<=M; i++)
        for(int j=T; j>=tc[i]; j--)
            if(f[j-tc[i]] + v[i] > f[j])    f[j] = f[j-tc[i]] + v[i];
    
    cout << f[T];
    return 0;
}