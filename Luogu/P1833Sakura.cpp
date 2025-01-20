#include<iostream>
using namespace std;

constexpr int MAXT = 1005;  //dataDefine
constexpr int MAXN = 10005;
int tsh,tsm,teh,tem,trm,n;
char re;
int f[MAXT];
int T[MAXN],C[MAXN],P[MAXN];

int main(){
    cin >> tsh >> re >> tsm >> teh >> re >> tem >> n;   //input
    for(int i=1;i<=n;i++)   cin >> T[i] >> C[i] >> P[i];
    trm = (teh - tsh) * 60 + (tem - tsm);

    for(int i=1;i<=n;i++){      //core
        if(P[i] == 0){      //Complete
            for(int c=T[i];c<=trm;c++)
                if(f[c - T[i]] + C[i] > f[c])   f[c] = f[c - T[i]] + C[i];
        }else{              //Multi(and 0-1)
            for(int c=trm;c>=T[i];c--)
                for(int j=1;j<=P[i] && j*T[i]<=c;j++)
                    if(f[c - j * T[i]] + j * C[i] > f[c])   f[c] = f[c - j * T[i]] + j * C[i];
        }
    }

    cout << f[trm];     //end
    return 0;
}
