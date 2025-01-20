#include<iostream>
#include<cmath>
using namespace std;

//DD
constexpr int DIGITS = 15;
long long int l, r;
int numl[DIGITS], numr[DIGITS];
long long int ans_bottom[DIGITS], ans_top[DIGITS], num_on_digit[DIGITS], di[DIGITS], numd[DIGITS];

void dfs(int digit, int* num, long long int* ans){
    if(digit == 0)  return;

    for(int i=0;i<=9;i++)    ans[i] += numd[digit - 1] * num[digit];
    for(int i=0;i<num[digit];i++)   ans[i] += di[digit - 1];
    ans[num[digit]] += num_on_digit[digit-1] + 1;
    ans[0] -= di[digit - 1];

    dfs(digit - 1, num, ans);
}

void calc(long long int n, int* num, long long int* ans){
    int i = 0;
    while(n){
        num[++i] = n % 10;
        n /= 10;
    }
    num[0] = i;
    di[0] = 1;
    num_on_digit[0] = 0;
    numd[0] = 0;
    for(int j=1;j<=i;j++){
        num_on_digit[j] = num[j] * pow(10, j-1) + num_on_digit[j-1];
        numd[j] = numd[j-1] * 10 + di[j-1];
        di[j] = di[j-1] * 10;
    }
    dfs(num[0], num, ans);
}

int main(){
    cin >> l >> r;
    calc(l-1, numl, ans_bottom);
    calc(r, numr, ans_top);

    for(int i=0;i<=9;i++)   cout << ans_top[i] - ans_bottom[i] << ' ';
    return 0;
}