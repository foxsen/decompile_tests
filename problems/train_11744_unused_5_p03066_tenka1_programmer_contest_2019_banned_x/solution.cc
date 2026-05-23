#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define N_MAX 6002

using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll inv[N_MAX],fac[N_MAX],finv[N_MAX];

void init(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        fac[i]=fac[i-1]*(ll) i%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

ll comb(ll n, ll r){
  ll ans;
  if(n < r){
      ans = 0;
  }else{
      ans = (fac[n]*finv[r])%MOD;
      ans = (ans*finv[n-r])%MOD;
      ans = (ans+MOD)%MOD;
  }
  return ans;
}

int N, X;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    cin >> N >> X;
    ll ans = 0;
    for(int i = 0; i <= 2*N; i++){
        if(i < X){
            for(int j = 0; j <= i; j++){
                int r = i-j;
                if(r%2 != 0) continue;
                int cnt = j+r/2;
                ll cb = comb(j+r/2, j);
                ll hcb = comb(N, cnt);
                ans += (cb*hcb)%MOD;
                ans %= MOD;
            }
        }
        else if(i%2 == X%2){
            continue;
        }else{
            int m = 2*max((i-(X-1))/2, 0);
            int rem = i-(m*2);
            // cout << i << ' ' << rem << ' ' << m << endl;
            if(rem < 0){
                if(i%2 == 0){
                    ll cb = comb(N, i/2);
                    ans += cb;
                    ans %= MOD;
                }
            }
            for(int j = 0; j <= rem; j++){
                int r = rem-j;
                if(r%2 == 1 || r < 0) continue;
                int cnt = m+j+r/2;
                if(cnt > N) continue;
                // cout << j << ' ' << cnt << endl;
                ll cb = comb(j+r/2, j);
                ll hcb = comb(N, cnt);
                ans += (cb*hcb)%MOD;
                ans %= MOD;
            }
        }
        // cout << i << "->" << ans << endl;
    }
    cout << ans << endl;
}