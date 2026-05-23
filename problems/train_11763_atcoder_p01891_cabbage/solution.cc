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

#define INF 2147483600

int solve(){
  int n,m,a,b;
  cin>>n>>m>>a>>b;
  vector<int> vec(n);
  rep(i,n) cin>>vec[i];

  int cnt =0;
  int i=0;
  while(i<n){
    if(vec[i]>=a) cnt++;
    else break;
    i++;
  }

  if(n - cnt >= m){
    return cnt;
  }
  i--;

  while(i>=0){
    if(vec[i] >= a && vec[i]<=b) cnt--;
    else if(vec[i]>=a && vec[i]>b) break;
    i--;
  }

  return cnt;
}

int main(){
  cout << solve() << endl;

  return 0;
}