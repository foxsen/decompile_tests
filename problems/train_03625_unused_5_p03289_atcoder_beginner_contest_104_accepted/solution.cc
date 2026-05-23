#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    string s;   cin >> s;
    string ans="AC";
    int cnt=0;
    if(s[0]!='A') ans = "WA";

    for(int i=1; i<s.size(); i++){
        if(s[i]=='C' && 2<=i && i<=s.size()-2) cnt +=1;
        else if('A'<=s[i] && s[i]<='Z') ans = "WA";
    }
    if(cnt!=1) ans="WA";
    cout << ans << endl;
    
    
}