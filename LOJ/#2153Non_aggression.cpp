#include<iostream>
using namespace std;

//DD
constexpr int MAX_SITUATIONS = 2e3+5;
int n, k, stats_cnt = 0;
long long int line_stat[MAX_SITUATIONS], king_set[MAX_SITUATIONS];
long long int f[15][MAX_SITUATIONS][105];

bool compatible(int x, int y) {
    if (line_stat[x] & line_stat[y])  return false;
    if ((line_stat[x] << 1) & line_stat[y])   return false;
    if (line_stat[x] & (line_stat[y] << 1))   return false;
    return true;
}

void dfs_first_line_init(int stat_cur, int kings_cur, int ptr){
    if(ptr >= n){    //boundary
        line_stat[++stats_cnt] = stat_cur;
        king_set[stats_cnt] = kings_cur;
        return;
    }
    //dfs
    dfs_first_line_init(stat_cur + (1<<ptr), kings_cur+1, ptr+2);
    dfs_first_line_init(stat_cur, kings_cur, ptr+1);
}

int main(){
    //in2
    cin >> n >> k;
    dfs_first_line_init(0,0,0);
    for(int situation=1; situation<=stats_cnt; situation++) f[1][situation][king_set[situation]] = 1;

    //DP Core
    for(int line=2; line<=n; line++)
        for(int stat_before=1; stat_before<=stats_cnt; stat_before++)
            for(int stat_cur=1; stat_cur<=stats_cnt; stat_cur++)
                if(compatible(stat_cur, stat_before))
                    for(int king_goal=king_set[stat_cur]; king_goal<=k; king_goal++)
                        f[line][stat_cur][king_goal] += f[line-1][stat_before][king_goal-king_set[stat_cur]];  //用stat_before的king_set补全stat_cur距king_goal的king_set, 累加数量

    //solve
    long long int ans = 0;
    for(int situation = 1; situation<=stats_cnt; situation++)   ans += f[n][situation][k];
    cout << ans << endl;
    return 0;
}
