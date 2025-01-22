#include <string>
#include <iostream>
using namespace std;
string s[201];
int main(){
    s[0] = "http://www.acm.org/";
    int i=0,end=0;
    while(true){
        string c;
        cin>>c;
        if(c == "QUIT"){
            break;
        }
        if(c =="BACK"){
            if(i==0){
                cout<<"Ignored"<<endl;
                continue;
            }else{
                i--;
                cout<<s[i]<<endl;
            }
        }else if(c=="FORWARD"){
            if(i==end){
                cout<<"Ignored"<<endl;
                continue;
            }else{
                i++;
                cout<<s[i]<<endl;
            }
        }else{//visit
            string url;
            cin>>url;
            cout<<url<<endl;
            i++;
            s[i]=url;
            end=i;
        }

    }
    return 0;
}