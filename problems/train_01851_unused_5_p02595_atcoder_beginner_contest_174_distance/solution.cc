#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t n, d, ans=0;
  cin >> n >> d;
  int64_t x, y;
  for(int i=0; i<n; i++){
    cin >> x >> y;
    if(x*x+y*y<=d*d) ans++;
  }
  cout << ans;
  return 0;
}