#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL<<61;

int main(){
  ll n, k; cin >> n >> k;
  vector<ll> A(n);
  for(int i = 0; i < n; i++) cin >> A[i];
  sort(A.begin(), A.end());
  ll left = -INF, right = INF;
  while(right - left > 1){
    ll x = (right+left)/2;
    ll s = 0, t = 0;
    for(int i = 0; i < n; i++){
      if(A[i] > 0){
        int l1 = -1, r1 = n;
        while(r1 - l1 > 1){
          int m = (r1 + l1) / 2;
          if(A[i] * A[m] <= x) l1 = m; 
          else r1 = m;
        }
        s += r1;
      }
      else if(A[i] < 0){
        int l1 = -1, r1 = n;
        while(r1 - l1 > 1){
          int m = (r1 + l1) / 2;
          if(A[i] * A[m] <= x) r1 = m;
          else l1 = m;
        }
        s += n - r1;
      }
      else if(x >= 0) s += n;
      if(A[i] * A[i] <= x) t++;
    }
    ll num = (s - t) / 2;
    if(num >= k) right = x;
    else left = x;
  }
  cout <<  right << endl;
}