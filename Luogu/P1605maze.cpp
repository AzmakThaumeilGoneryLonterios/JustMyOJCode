#include<iostream>
#include<cstring>

using namespace std;

int n,m,t;
int sx,sy,fx,fy;
int a[9][9],path_e[9][9];
int xdir[4] = {0,1,0,-1}, ydir[4] = {1,0,-1,0};
int path = 0;

void dfs(int x, int y){
    // boundary condition
    if(x==fx && y==fy){
        path++;
        return;
    }
    
    for(int i=0;i<4;i++){
        if(a[x+xdir[i]][y+ydir[i]]==0 && path_e[x+xdir[i]][y+ydir[i]]==0 && x+xdir[i]>0 && x+xdir[i]<=n && y+ydir[i]>0 && y+ydir[i]<=m){
            path_e[x][y] = 1;
            dfs(x+xdir[i],y+ydir[i]);
            path_e[x][y] = 0;
        }
    }
}

int main()
{
	cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    memset(a,0,sizeof(a));
    memset(path_e,0,sizeof(path_e));
	for(int i=0;i<t;i++) {
        int tx,ty;
        cin>>tx>>ty;
        a[tx][ty] = 1;
	}

    dfs(sx,sy);
    cout << path << endl;
    
	return 0;
}