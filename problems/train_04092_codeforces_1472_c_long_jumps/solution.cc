#include <bits/stdc++.h>

using namespace std;
#define TEST int tt; cin >> tt; while (tt--)
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define xx first
#define yy second
#define ll long long
#define ld long double

int n;
vector<ll> ipt;
vector<ll> ans;

ll func(ll x){
    if(ans[x]!=0){
        return ans[x];
    }
    if((x + ipt[x]) > n){
        return ans[x] = x+ipt[x];
    }

    return ans[x] = func(x+ipt[x]);
}

void solve() {
    ipt.clear();
    ans.clear();
    cin>>n;
    ipt.resize(n+1);
    ans.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>ipt[i];
    }
    ll asd=0;
    for(int i=1;i<=n;i++){
        if(ans[i]==0){
            asd = max(asd, func(i) - i);
        }
        else asd = max(asd, ans[i] - i);
    }
    cout<<asd<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TEST {
        solve();
    };

    return 0;
}