#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 21474836

int main(){
  int n,m,s,g;
  cin>>n>>m>>s>>g;
  s--;g--;
  vector<int> u(m),v(m),t(m),c(m);
  rep(i,m) cin>>u[i]>>v[i]>>t[i]>>c[i];
  rep(i,m) u[i]--,v[i]--;

  vector<vector<int>> st(200001), gt(200001), gc(200001);
  rep(i,m) st[t[i]].pb(i);

  vector<int> bs(n,-INF);
  bs[s] = 0;

  int ans = INF;
  rep(i,200001){
    int k = gt[i].size();
    rep(j,k){//dbg(i),dbg(bs);
      int arr = gt[i][j];
      int cost = gc[i][j];
      bs[arr] = max(bs[arr], cost);
      if(arr == g){
        ans = min(ans, i-bs[arr]);
      }
    }
    for(auto id : st[i]){//dbg(i),dbg(bs);
      gt[i+c[id]].pb(v[id]);
      gc[i+c[id]].pb(bs[u[id]] + c[id]);
    }
  }

  cout << ans << endl;

  return 0;
}