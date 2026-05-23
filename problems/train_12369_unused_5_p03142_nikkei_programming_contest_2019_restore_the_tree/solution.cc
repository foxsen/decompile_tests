#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n,m;cin>>n>>m;
  vi parent[n], child[n];
  vi n_parent(n,0);
  int a,b;
  rep(i,n-1+m) {
    cin>>a>>b;
    a--;b--;
    child[a].push_back(b);
    parent[b].push_back(a);
    n_parent[b]++;
  }
  
  int root;
  rep(i,n) {
    if (parent[i].size() == 0) {
      root = i;
      break;
    }
  }
  
  vi ans(n,-1);
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int c: child[x]) {
      if (n_parent[c]==1) {
        
        ans[c]=x;
        q.push(c);
      } else {
        n_parent[c]--;
      }
    }
  }
  rep(i,n) cout<<(ans[i]+1)<<endl;
}
