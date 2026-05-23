#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int b, r, g, c, s, t;
    cin >> b >> r >> g >> c >> s >> t;
    if(t==0) return false;
    int ans = 100;
    int bt = b*5+r*3;
    ans += 15*(bt+b+r);
    ans += 7*g+2*c;
    ans -= 2*bt;
    t -= s+bt;
    ans -= t*3;
    cout << ans << endl;
    return true;
}

int main() {
    while(solve());
    return 0;
}

