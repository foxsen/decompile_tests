#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, x;
  cin >> n >> m;
  priority_queue<int> que;
  for(int i=0; i<n; ++i){
    cin >> x;
    que.push(x);
  }
  for(int i=0; i<m; ++i){
    x = que.top();
    que.pop();
    que.push(x/2);
  }
  long long ans = 0;
  for(int i=0; i<n; ++i){
    ans += que.top();
    que.pop();
  }
  cout << ans << endl;
}