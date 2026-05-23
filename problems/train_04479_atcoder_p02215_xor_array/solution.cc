#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

template<int mod>
struct ModInt {
    long long x;
 
    ModInt() : x(0) {}
    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    explicit operator int() const {return x;}
 
    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }
 
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
 
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
 
    ModInt inverse() const{
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return ModInt(u);
    }

    ModInt power(long long p) const{
        int a = x;
        if (p==0) return 1;
        if (p==1) return ModInt(a);
        if (p%2==1) return (ModInt(a)*ModInt(a)).power(p/2)*ModInt(a);
        else return (ModInt(a)*ModInt(a)).power(p/2);
    }

    ModInt power(const ModInt p) const{
        return ((ModInt)x).power(p.x);
    }

    friend ostream &operator<<(ostream &os, const ModInt<mod> &p) {
        return os << p.x;
    }
    friend istream &operator>>(istream &is, ModInt<mod> &a) {
        long long x;
        is >> x;
        a = ModInt<mod>(x);
        return (is);
    }
};

using modint = ModInt<mod>;



int n,x;
modint dp[2][550][510],S[2][550][510];

void solve(){
  cin >> n >> x;
  dp[0][0][0]=1;
  int k=1;
  while(k<x){
    k*=2;
  }
  rep(m,x+1){
    S[0][0][m]=1;
  }
  rep(i,n){
    rep(m,k+1){
      rep(s,x+1){
        dp[(i+1)%2][m][s]=S[i%2][m^s][s];
        if(s>=1)S[(i+1)%2][m][s]=S[(i+1)%2][m][s-1];
        else S[(i+1)%2][m][s]=0;
        S[(i+1)%2][m][s]+=dp[(i+1)%2][m][s];
        //cout << i+1 << " " << m << " " << s << " " << S[(i+1)%2][m][s] << endl;
      }
    }
  }
  cout << S[n%2][x][x] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}
