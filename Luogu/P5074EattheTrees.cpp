#include<iostream>
#include<cstring>
using namespace std;

//DD
constexpr int MAXN = 15;
constexpr int MAX_CONNECTION = 15;
constexpr int HASH = 9973;
constexpr int MAX_STAT = 1e5;

struct HashTable{
    int head[HASH], next[MAX_STAT], pointer = 0;
    long long int stats[MAX_STAT];
    long long int num[MAX_STAT];
    void set_zero(){
        pointer = 0;
        memset(head, 0, sizeof(head));
    }
    void push(long long int conn, long long int cnt){
        int h = conn % HASH;
        for(int i=head[h]; i; i=next[i])
            if(conn == stats[i]){
                num[i] += cnt;
                return;
            }
        stats[++pointer] = conn;
        num[pointer] = cnt;
        next[h] = head[h];
        head[h] = pointer;
    }
    void roll(){
        for(int i=1; i<=pointer; i++)    stats[i] <<= 3;
    }
    long long int ans(){
        for(int i=1; i<=pointer; i++)   num[0] += num[i];
        return num[0];
    }
}H[2],*H0,*H1;

int T, n, m;
bool connection[MAX_CONNECTION];
int a[MAXN][MAXN];

bool cut_conn(int n){
    connection[n] = 0;
    for(int i=1; i< MAX_CONNECTION; i++)
        if(connection[i]){
            return false;
        }
    return true;
}
int get_conn(){
    for(int i=1; i< MAX_CONNECTION; i++)
        if(!connection[i]){
            connection[i] = 1;
            return i;
        }
    //TODO
    cout << "debug" << endl;
    return 0;
}

//TODO
void print(long long int tmp){
    while(tmp){
        cout << tmp % 8 << '\t';
        tmp /= 8;
    }
    cout << endl;
}

long long int process(long long int sit, int type, int block, int p, int q){ //1:rtbt 2:ltup 3:uprt 4:upbt 5:ltrt 6:ltbt
    long long int tmp;
    int cnt = 0;
    int c;
    switch(type){
        case 1:
            c = get_conn();
            return sit | c << (3*(block-1)) | c << (3*block);
            break;
        case 2:
            sit = sit ^ p << (3*(block-1)) ^ (q << (3*block));
            if(cut_conn(q)) return sit;
            tmp = sit;
            while(tmp && tmp % 8 != q){
                tmp >>= 3;
                cnt ++;
            }
            return (sit ^ (q << (3*cnt))) | p << (3*cnt);
        case 3:
            return sit;
        case 4:
            return (sit ^ (q << (3*block))) | q << (3*(block-1));
        case 5:
            return (sit ^ p << (3*(block-1))) | (p << (3*block));
        case 6:
            return sit;
    }
    //TODO
    cout << "debug" << endl;
    return 0;
} 

// void init_first_line(int cur, long long int conn){
//     int p;
//     if(cur == 1)    p = 0;
//     else    p = (conn >> (3*cur)) % 8;
//     //boundary
//     if(cur > m){
//         H1->push(conn, 1);
//         return;
//     }
//     //dfs
//     if(p == 0){
//         if(a[2][cur] == 1 && a[1][cur+1] == 1){
//             int c = get_conn();
//             init_first_line(cur+1, conn | (c << (3*cur)) | (c << (3*(cur+1))));
//         }
//     }else{
//         if(a[2][cur] == 1)
//             init_first_line(cur+1, conn);
//         if(a[1][cur+1] == 1)
//             init_first_line(cur+1, (conn ^ p << (3*cur)) | p << (3*(cur+1)));
//     }
// }

// test
// int main(){
//     long long int n;
//     H0 = H; H1 = H + 1;
//     H1->set_zero();
//     H1->push(1, 1);
//     cin >> n;
//     while(n){
//         H1->push(n,1);
//         print(n);
//         cin >> n;
//     }
//     return 0;
// }
int main(){
    cin >> T;
    while(T--){
        //in2
        fill(connection, connection+MAX_CONNECTION, 0);
        cin >> n >> m;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++) cin >> a[i][j];
        H0 = H; H1 = H + 1;
        H1->set_zero();
        H1->push(0,1);

        //DP core
        for(int line=1; line <=n; line++){
            for(int block=1; block <=m ; block++){
                swap(H0, H1);
                H1->set_zero();
                for(int s=1; s<=H0->pointer; s++){
                    long long int sit = H0->stats[s];
                    long long int cnt = H0->num[s];
                    int p, q;
                    bool rt = true, bt = true;
                    if(a[line][block] == 0){
                        H1->push(sit, cnt);
                        continue;
                    }
                    if(block == 1 || a[line][block-1] == 0) p = 0;
                    else    p = (sit >> (3*(block-1))) % 8;
                    if(a[line-1][block] == 0)   q = 0;
                    else    q = (sit >> (3*block)) % 8;
                    if(block == m || a[line][block+1] == 0)   rt = false;
                    if(line == n || a[line+1][block] == 0)   bt = false;

                    if(p == 0 && q == 0){
                        if(bt && rt)    H1->push(process(sit, 1, block, p, q), cnt);
                    }else if(p != 0 && q != 0){
                        H1->push(process(sit, 2, block, p, q), cnt);
                    }else{
                        if(q != 0){
                            if(rt)  H1->push(process(sit, 3, block, p, q), cnt);
                            if(bt)  H1->push(process(sit, 4, block, p, q), cnt);
                        }
                        if(p != 0){
                            if(rt)  H1->push(process(sit, 5, block, p, q), cnt);
                            if(bt)  H1->push(process(sit, 6, block, p, q), cnt);
                        }
                    }
                }
            }
            H1->roll();
        }
        cout << H1->ans() << endl;
    }
    return 0;
}