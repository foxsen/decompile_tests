#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e16;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; ll X; cin >> N >> X;
    vector<ll> sum(N+1,0);
    for (int i=N;i>0;--i) cin >> sum[i];
    for (int i=0;i<N;++i) sum[i+1]+=sum[i];
    ll ans=INF;
    for (int i=1;i<=N;++i){
        ll cnt=(N+i)*X;
        int j=i;
        for (;j<=N;j+=i){
            cnt+=(sum[j]-sum[j-i])*max(5,2*(j/i-1)+3);
            if (ans<cnt) break;
        }
        cnt+=(sum[N]-sum[j-i])*max(5,2*(j/i-1)+3);
        ans=min(ans,cnt);
    }
    cout << ans << '\n';
}