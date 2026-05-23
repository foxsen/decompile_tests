#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    LL x, y;
    cin >> x >> y;
    LL ans = abs(abs(x)-abs(y));
    if(x*y > 0){
        if(x > y)   ans += 2;
    }else if(x*y < 0){
        ans++;
    }else{
        if(x > y)   ans++;
    }
    cout << ans << endl;
}
