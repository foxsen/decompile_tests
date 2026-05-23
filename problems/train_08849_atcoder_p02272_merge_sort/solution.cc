#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int n, a[500000], cnt = 0;

void func(int l, int r){
  if(l + 1 >= r) return;
  int m = (l + r) / 2;
  func(l, m);
  int t1[m - l + 1], t2[r - m + 1];
  for(int i = l; i < m; i++){
    t1[i - l] = a[i];
  }
  t1[m - l] = 1000000001;
  func(m, r);
  for(int i = m; i < r; i++){
    t2[i - m] = a[i];
  }
  t2[r - m] = 1000000001;
  int t1i = 0, t2i = 0;
  for(int i = l; i < r; i++){
    if(t1[t1i] <= t2[t2i]) a[i] = t1[t1i++];
    else a[i] = t2[t2i++];
    cnt++;
  }
  /*for(int i = l; i < r; i++){
    cout << a[i]
  }*/
  return;
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  func(0, n);
  for(int i = 0; i < n - 1; i++) cout << a[i] << " "; cout << a[n - 1] << endl;
  cout << cnt << endl;
  return;
}

int main(){
  solve();
  return 0;
}

