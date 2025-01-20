#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> leader;     //Data define
vector<vector<int>> adj;
vector<set<int>> sub;

void processR(int u){
    sub[u].insert(u);
    for(int i:adj[u]){
        processR(i);
        sub[u].insert(sub[i].begin() , sub[i].end());
    }
}

int main(){
    int n, t;       //input
    cin >> n;
    adj.resize(n+1);    //init
    leader.resize(n+1);
    for(int i=1;i<n;i++){
        cin >> leader[i];
        adj[leader[i]].push_back(i);
    }

    sub.resize(n+1);
    processR(0);

    cin >> t;   //party
    while(t--){
        vector<int> emp;    //input
        set<int> bosses;
        cin >> n;
        emp.resize(n+1);
        for(int i=1;i<=n;i++)    cin >> emp[i];
        bosses = sub[0];

        for(int i=1;i<=n;i++){
            set<int> bossesNew;
            for(int b:bosses){
                if(sub[b].count(emp[i]))    bossesNew.insert(b);
            }
            bosses = bossesNew;
        }

        cout << *bosses.rbegin() << endl;
    }
    return 0;
}