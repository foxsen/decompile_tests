#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif


const int P = 1e9 + 7;
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
void sub(int &a,int b){
  a -= b;
  if(a < 0)
    a += P;
}

int mul(int a,int b){
  return a * b % P;
}
struct war{
  int a,b,c;
  void operator +=(war x){
    add(a, x.a);
    add(b, x.b);
    add(c, x.c);
  }
  void operator -=(war x){
    sub(a, x.a);
    sub(b, x.b);
    sub(c, x.c);
  }
  
  void operator *=(war x){
    c = mul(c, x.a);
    add(c,mul(a, x.c));
    add(c,mul(b, x.b));
    
    
    b = mul(b, x.a);
    add(b,mul(a, x.b));
    
    a = mul(a, x.a);
  }
};

const int MAX = 1001;
int dp[MAX][3];

war licz1(int x){
  war res = {0,1,0};
  R(i,x - 1){
    res -= {0,dp[i + 1][2],0};
  }
  debug(x, res.b * 3 % P);
  return res;
}

war licz2(int x){
  debug(x);
  if(x == 1){
    return {(P + 1) / 2, 0, (P - 1) / 2};
  }
  war res = {1,0,0};
  res -= licz2(x-1);
  R(i,2 * x - 2){
    war pom = licz1((i + 1) / 2);
    pom *= {0,1,0};
    res -= pom;
  }
  return res;
}

int pot(int a,int w){
  int r = 1;
  while(w){
    if(w & 1){
      r = r * a % P;
    }
    w/=2;
    a = a * a % P;
  }
  return r;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  dp[0][1] = dp[0][0] = 1;
  dp[0][2] = 0;
  R(i,MAX)if(i)R(j,3){
    R(k,i){
      add(dp[i][j], mul(pot(2 * i - 1 + j, P - 2), mul(dp[k][j / 2], dp[i - k - 1][(j + 1) / 2])));
    }
  }
  debug(dp[0][2]);
  debug(dp[1][2] * 3 % P);
  debug(dp[2][2] * 5 % P);
  debug(dp[3][2] * 7 % P);
  
  int n;
  string z;
  cin >> n >> z;
  if(n == 1 && z[0] == '-'){
    cout << (P + 1) / 2 << " 0 " << (P + 1) / 2 << "\n";
    return 0;
  }
  R(i,n-1)if(z[i] == 'X' && z[i+1] == 'X'){
    cout << "0 0 0\n";
    return 0;
  }
  int ile = 0;
  war res = {1,0,0};
  vector<int> x;
  R(i,n){
    if(z[i] == '-'){
      if(i && z[i-1] == '-'){
        x.PB(ile);
        ile = 0;
      }
    }else{
      ile ++;
    }
  }
  debug(ile, x);
  if(x.empty()){
    res = licz2(ile);
  }else{
    res *= licz1(ile);
    res *= licz1(x[0]);
    R(i,SZ(x))if(i){
      res *= {dp[x[i]][2],0,0};
    }
  }
  cout << res.a << " " << res.b << " " << res.c << "\n";
}
