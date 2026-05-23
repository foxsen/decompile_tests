#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

int N, N2;
int xs[1<<20];
int solve(int i){
  if(i >= N2) return xs[i];
  int l = solve(i*2), r = solve(i*2+1);
  return (r==l?r: max(r,l) - min(r,l));
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  N2 = 1 << N;
  REP(i,N2) cin >> xs[N2+i];

  cout << solve(1) << endl;

  return 0;
}
