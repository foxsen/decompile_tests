#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

int n;
char s[125252];

typedef unsigned int Hash1;
typedef short Hash2;
typedef pair<Hash1,Hash2> Hash;
const Hash1 b1 = 29;
const Hash2 b2 = 29;
const Hash2 m2 = 127;
const int MAX = 100001;
Hash hsh[MAX];
Hash bpow[MAX];
Hash2 mdmp[65536];

struct HashHash {
  size_t operator()(const Hash &yey) const {
    hash<int> hasher;
    return hasher((int)yey.first)^hasher((int)yey.second);
  }
};

unordered_set<Hash,HashHash> S;
int calc(int x){
  S.clear();
  REP(i,n-x+1){
    // substr
    int l = i;
    int r = l+x;
    Hash h(0,0);
    h.first += hsh[l].first;
    h.second+= hsh[l].second;
    h.first *= bpow[x].first;
    h.second*= bpow[x].second;
    // mod & negative
    h.first = -h.first;
    h.second= m2 - mdmp[h.second];
    h.first += hsh[r].first;
    h.second+= hsh[r].second;
    h.second= mdmp[h.second];
    S.insert(h);
  }
  return S.size();
}

int main(){
  scanf("%s",s);
  n = strlen(s);
  REP(i,65536)mdmp[i] = i%m2;
  // create hash
  REP(i,n){
    int id = s[i]-'a';
    hsh[i+1].first = hsh[i].first*b1 + (Hash1)id;
    hsh[i+1].second= mdmp[ hsh[i].second*b2+ (Hash2)id ];
  }
  // base pow
  bpow[0] = Hash(1,1);
  REP(i,n){
    bpow[i+1].first = bpow[i].first*b1;
    bpow[i+1].second= mdmp[ bpow[i].second*b2 ];
  }
  // go
  int low = 1, high = n;
  while(low+2<high){
    int ml = (low+high)/2;
    int mh = ml+1;
    if(calc(ml)<calc(mh)){
      low = ml;
    }else{
      high = mh;
    }
  }
  int ans = 0;
  FOR(i,low,high+1)CHMAX(ans,calc(i));
  printf("%d\n",ans);
  return 0;
}
