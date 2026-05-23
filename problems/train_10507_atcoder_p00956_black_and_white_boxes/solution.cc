#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

//! represents x / (1<<y)
class Frac{
public:
  using LL = __int128;
  LL x, y;

  Frac(LL x = 0, LL y = 0) : x(x), y(y) { red(); }

  void red(){
	if(x == 0){
	  y = 0;
	  return;
	}

	while(y && x % 2 == 0){
	  x /= 2;
	  --y;
	}
  }

  Frac& operator += (const Frac &p){ LL l = max(y, p.y); x = (x<<(l-y)) + (p.x<<(l-p.y)); y = l; red(); return *this;}
  Frac operator + (const Frac &p) const{ Frac q = *this;return q += p;}
  Frac operator - () const { Frac q = *this; q.x *= -1; return q; }
  Frac& operator -= (const Frac &p){ Frac q = -p; *this += q; return *this;}
  Frac operator - (const Frac &p) const{ Frac q = *this; return q -= p;}
  Frac& operator *= (const Frac &a){ x *= a.x; y += a.y; red(); return *this;}
  Frac operator * (Frac a) const{ Frac q = *this; return q *= a;}

  bool operator < (const Frac &p) const{
	LL l = max(y, p.y);
	return (x << (l - y)) < (p.x << (l - p.y));
  }
  bool operator > (const Frac &p) const{
	return p < *this;
  }
  bool operator == (const Frac &p) const {
	return x == p.x && y == p.y;
  }
  bool operator <= (const Frac &p){
	return !(*this > p);
  }
  bool operator >= (const Frac &p){
	return !(*this < p);
  }
  LL floor() const { LL n = 1ll << y; return (x >= 0? x / n : (x-n) / n); }
  LL ceil() const { LL n = 1ll << y; return (x >= 0? (x+n-1) / n : x / n); }
  friend ostream& operator <<(ostream& os, const Frac& p);
};
ostream& operator <<(ostream& os, const Frac& p){
  return os ;//<< p.x << "/" << (1ll<<p.y);
}

Frac simplest(const Frac &l, const Frac &r){
  //cout<<"{ "<<l<<" | "<<r<<" } = ";
  for(LL k=0;;++k){
	Frac tmp = l * (1ll<<k);
	tmp.x++;
	tmp.red();
	Frac res(tmp.ceil(), k);
	if(l < res && res < r){
	  //cout<<res<<endl;
	  return res;
	}
  }
}

void calcNum(int N, string& s, vector<Frac>& xs){
  xs.resize(N+1);
  xs[0] = 0;
  Frac left, right;
  bool isLeftEmpty = true, isRightEmpty = true;
  FOR(i,1,N+1){
	if(s[i-1] == 'B'){
	  if(isLeftEmpty){
		isLeftEmpty = false;
		left = xs[i-1];
	  }
	  else
		left = max(left, xs[i-1]);
	  
	  if(isRightEmpty){
		xs[i] = left + 1;
	  }
	  else{
		xs[i] = simplest(left, right);
	  }
	}
	else{
	  if(isRightEmpty){
		isRightEmpty = false;
		right = xs[i-1];
	  }
	  else
		right = min(right, xs[i-1]);
	  
	  if(isLeftEmpty){
		xs[i] = right - 1;
	  }
	  else{
		xs[i] = simplest(left, right);
	  }
	}
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, S = 0;
  cin >> N;
  vector<vector<Frac>> xs(N);
  REP(i,N){
	string s;
	cin >> s;
	S += SZ(s);
	calcNum(SZ(s), s, xs[i]);
  }

  /*
  REP(i,N){
	for(auto&p:xs[i])
	  cout<<p<<" , ";
	cout<<endl;
  }
  */

  int N2 = N / 2;
  map<Frac,int> mem;
  REP(b,1<<N2){
	int sum = 0;
	Frac f;
	REP(i,N2)
	  if(b>>i&1)
		sum += SZ(xs[i])-1;
	  else
		f += xs[i].back();
	if(!mem.count(f))
	  mem[f] = sum;
	else
	  mini(mem[f], sum);
  }

  int ans = S;
  REP(b,1<<(N-N2)){
	int sum = 0;
	Frac f;
	REP(i,N-N2)
	  if(b>>i&1)
		sum += SZ(xs[N2+i])-1;
	  else
		f += xs[N2+i].back();
	
	if(mem.count(-f))
	  mini(ans, mem[-f] + sum);
  }

  cout << S - ans << endl;

  return 0;
}