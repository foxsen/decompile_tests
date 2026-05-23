#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,pos;
vector<int> pre,in,post;

void rec(int l,int r) {
  if (l>=r) 
    return ;
  int root=pre[pos++];
  int m=distance(in.begin(),find(in.begin(),in.end(),root));
  rec(l,m);
  rec(m+1,r);
  post.push_back(root);
  
}
void solve() {
  pos=0;
  rec(0,pre.size());
  for (int i=0; i<n; i++) {
    if (i) 
      cout<<" "<<flush;
    cout<<post[i]<<flush;
  }
  cout<<endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin>>n;
  int s;
  for (int i=0; i<n; i++) {
    cin>>s;
    pre.push_back(s);
  }
  for (int i=0; i<n; i++) {
    cin>>s;
    in.push_back(s);
  }
  
  
  solve();
  return 0;
}

