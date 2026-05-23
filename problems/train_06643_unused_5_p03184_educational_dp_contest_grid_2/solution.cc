//In the name of God

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

const int N = 2e5+10 , mod = 1e9+7;

vector <pii> v;
int dp[N] , fac[N] , rev[N];

inline int power(int x , int y){
   int ret = 1;
   for( ; y ; y /= 2){
      if(y & 1)
         ret = 1ll * ret * x % mod;
      x = 1ll * x * x % mod;
   }
   return ret;
}

int comb(int x , int y){
   return 1ll * fac[y] * rev[x] % mod * rev[y - x] % mod;
}

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   fac[0] = rev[0] = 1;
   for(int i = 1 ; i < N ; i++){
      fac[i] = 1ll * fac[i - 1] * i % mod;
      rev[i] = power(fac[i] , mod - 2);
   }
   int n , m , k;
   cin >> n >> m >> k;
   for(int i = 0 ; i < k ; i++){
      int r , c;
      cin >> r >> c;
      v.push_back({r , c});
   }
   v.push_back({n , m});
   sort(v.begin() , v.end());
   for(int i = 0 ; i <= k ; i++){
      int r = v[i].first , c = v[i].second;
      dp[i] = comb(r - 1 , r - 1 + c - 1);
      for(int j = 0 ; j < i ; j++){
         int r2 = v[j].first , c2 = v[j].second;
         if(c2 > c)
            continue;
         dp[i] -= 1ll * dp[j] * comb(c - c2 , c - c2 + r - r2) % mod;
         dp[i] += mod;
         dp[i] %= mod;
      }
   }
   cout << dp[k];
   return 0;
}
