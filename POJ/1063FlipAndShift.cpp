#include<iostream>
using namespace std;
int main(){
    int times,amount;
    int odds,evens;
    int c;
    cin >> times;
    for(int i=0;i<times;i++){
        cin >> amount;
        odds = 0;
        evens = 0;
        if(amount % 2 == 1){
            for(int j=0;j<amount;j++) cin >> c;
            cout << "YES" << endl;
            continue;
        }
        for(int j=0;j<amount;j++){
            cin >> c;
            if (j % 2 == 0 && c == 1)
            {
                evens++;
            }else if(j % 2 == 1 && c == 1){
                odds++;
            }
        }
        if((evens - odds) < 2 && (evens - odds) > -2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}