#include<iostream>
#include<vector>
using namespace std;

//DD
int W, n, t, w;
vector<int> ts, wr;

int main(){
    cin >> W >> n;
    const int S = (1 << n) - 1;
    ts.resize(S+1);
    wr.resize(S+1);
    for(int i=0;i<n;i++){
        cin >> t >> w;
        for(int j=1;j<=S;j++)
            if(j&(1<<i)){
                ts[j] = max(ts[j],t);
                wr[j] += w;
            }
    }

    vector<int> dp(S+1, 2e9);
    for(int i=0;i<=S;i++){
        if(wr[i] <= W)   dp[i] = ts[i];
        for(int j=i;j;j=i&(j-1))
            if(wr[i^j] <= W) dp[i] = min(dp[i], dp[j] + ts[i^j]);
    }

    cout << dp[S];
    return 0;
}