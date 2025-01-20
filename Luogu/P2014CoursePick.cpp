#include<iostream>
#include<vector>
using namespace std;

//DD
constexpr int MAX = 3e2 + 5;
vector<int> e[MAX];
int v[MAX];
int f[MAX][MAX];
int k, n, m;

//DP
int dfs(int u){
    int siz = 1;
    f[u][1] = v[u];

    for(auto sub:e[u]){
        int sub_siz = dfs(sub);
        for(int i=min(m+1,siz);i;i--)
            for(int j=1;j<=sub_siz && j+1<=m+1;j++)
                f[u][i+j] = max(f[u][i+j], f[u][i] + f[sub][j]);

        siz += sub_siz;
    }

    return siz;
}

int main(){
    //input
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> k >> v[i];
        e[k].push_back(i);
    }
    v[0] = 0;

    dfs(0); //first
    cout << f[0][m+1];

    return 0;
}