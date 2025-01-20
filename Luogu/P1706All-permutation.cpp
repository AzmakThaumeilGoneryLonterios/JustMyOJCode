#include<iostream>
#include<iomanip>
#define MAX 20
using namespace std;

void dfs(int step,int* ans,bool* visited,int n){
    if(step > n){       //bound: output
        for(int i=1;i<=n;i++){
            cout << setw(5) << ans[i];
        }
        cout << endl;
        return;
    }
    for(int i=1;i<=n;i++){      //iteration
        if(!visited[i]){
            visited[i] = true;
            ans[step] = i;
            dfs(step + 1,ans,visited,n);    //recursion
            visited[i] = false;
        }
    }
}

int main(){
    int num,ans[MAX];
    bool visited[MAX];
    cin >> num;
    dfs(1,ans,visited,num);

    return 0;
}
