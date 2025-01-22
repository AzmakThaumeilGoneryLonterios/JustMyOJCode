#include<iostream>
#include<string>
#define MAX_LENGTH 105

//DP
using namespace std;
int evaluate(char x,char y,int *scores){
    short x1,y1;
    switch (x)
    {
    case 'A':
        x1 = 0;
        break;
    case 'C':
        x1 = 1;
        break;
    case 'G':
        x1 = 2;
        break;
    case 'T':
        x1 = 3;
        break;
    case '-':
        x1 = 4;
        break;
    default:
        return 0;
    }
    switch (y)
    {
    case 'A':
        y1 = 0;
        break;
    case 'C':
        y1 = 1;
        break;
    case 'G':
        y1 = 2;
        break;
    case 'T':
        y1 = 3;
        break;
    case '-':
        y1 = 4;
        break;
    default:
        return 0;
    }
    return scores[x1 * 5 + y1];

}
int main(){
    int times,lx,ly,xy,xa,ya;
    int scores[5][5] = {{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};
    int r[MAX_LENGTH][MAX_LENGTH];
    string cx,cy;
    cin >> times;
    r[0][0] = 0;
    while(times--){
        cin >> lx;
        cin >> cx;
        cin >> ly;
        cin >> cy;
        cx = "-" + cx;
        cy = "-" + cy;
        for(int j=1;j<=lx;j++)  r[j][0] = evaluate(cx[j],'-',scores[0]) + r[j-1][0];    //Init
        for(int k=1;k<=ly;k++)  r[0][k] = evaluate('-',cy[k],scores[0]) + r[0][k-1];
        for(int j = 1;j <= lx;j++){
            for (int k = 1; k <= ly; k++)
            {
                xy = evaluate(cx[j],cy[k],scores[0]) + r[j-1][k-1];
                xa = evaluate(cx[j],'-',scores[0]) + r[j-1][k];
                ya = evaluate('-',cy[k],scores[0]) + r[j][k-1];
                r[j][k] = max(max(xy,xa),ya);   //Core
            }
        }
        cout << r[lx][ly] << endl;
    }
    // for(int j = 0;j<= lx;j++){
    //     for (int k = 0; k <= ly; k++){
    //         cout << r[j][k] << '\t';
    //     }
    //     cout << endl;
    // }

    return 0;
}