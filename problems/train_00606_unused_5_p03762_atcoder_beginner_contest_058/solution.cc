#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n, m;
  cin >> n >> m;
  
  ll x, y, xs = 0, ys = 0;
  for (int i = 0; i < n; i++){
    cin >> x;
    xs = (xs + (1 - n + 2*i)*x) % MOD;
  }
  for (int i = 0; i < m; i++){
    cin >> y;
    ys = (ys + (1 - m + 2*i)*y) % MOD;
  }

  cout << xs * ys % MOD << endl;

  return 0;
}
