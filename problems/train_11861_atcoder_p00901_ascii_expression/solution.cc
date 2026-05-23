#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

/*constexpr lint mod = 1000000007;
constexpr lint INF = mod * mod;
constexpr int MAX = 200010;*/

constexpr int mod = 2011;

int powmod(int x, int n){
    int ret = 1;
    while(n){
        if(n & 1) (ret *= x) %= mod, --n;
        else (x *= x) %= mod, n >>= 1;
    }
    return ret;
}

int rev(int x){
    return powmod(x, mod - 2);
}

int expr(vector<string> &s, int &i, int u, int d);
int term(vector<string> &s, int &i, int u, int d);
int factor(vector<string> &s, int &i, int u, int d);
int powexpr(vector<string> &s, int &i, int u, int d);
int primary(vector<string> &s, int &i, int u, int d);
int fraction(vector<string> &s, int &i, int u, int d);
int digit(vector<string> &s, int &i, int u, int d);

int get_base(vector<string> &s, int &i, int u, int d){
    For(x, i, s[0].size()){
        For(y, u, d)if(s[y][x] != '.') return y;
        ++i;
    }
    return -1;
}

int expr(vector<string> &s, int &i, int u, int d){
    int base = get_base(s, i, u, d);
    int ret = term(s, i, u, d);
    while(i+1 < (int)s[0].size() && (s[base][i+1] == '+' || s[base][i+1] == '-')){
        ++i;
        char op = s[base][i];
        i += 2;
        int rhs = term(s, i, u, d);
        if(op == '+') (ret += rhs) %= mod;
        else (ret += mod - rhs) %= mod;
    }
    return ret;
}

int term(vector<string> &s, int &i, int u, int d){
    int base = get_base(s, i, u, d);
    int ret = factor(s, i, u, d);
    while(i+1 < (int)s[0].size() && s[base][i+1] == '*'){
        i += 3;
        int rhs = factor(s, i, u, d);
        (ret *= rhs) %= mod;
    }
    return ret;
}

int factor(vector<string> &s, int &i, int u, int d){
    int base = get_base(s, i, u, d);
    if(s[base][i] == '-'){
        if(s[base][i+1] == '.'){
            i += 2;
            return mod - factor(s, i, u, d);
        }
        else return fraction(s, i, u, d);
    }
    else return powexpr(s, i, u, d);
}

int powexpr(vector<string> &s, int &i, int u, int d){
    int base = get_base(s, i, u, d);
    int ret = primary(s, i, u, d);
    if(base > 0 && i < (int)s[0].size() && isdigit(s[base-1][i])){
        ret = powmod(ret, digit(s, i, base - 1, base));
    }
    return ret;
}

int primary(vector<string> &s, int &i, int u, int d){
    int base = get_base(s, i, u, d);
    if(isdigit(s[base][i])){
        int ret = digit(s, i, base, base + 1);
        return ret;
    }
    i += 2;
    int ret = expr(s, i, u, d);
    i += 2;
    return ret;
}

int fraction(vector<string> &s, int &i, int u, int d){
    int base = get_base(s, i, u, d);
    int j = i, k = i;
    int lhs = expr(s, j, u, base), rhs = expr(s, k, base + 1, d);
    i = max(j, k) + 1;
    return (lhs * rev(rhs)) % mod;
}

int digit(vector<string> &s, int &i, int u, int d){
    int ret = s[u][i] - '0';
    ++i;
    return ret;
}

int main(){
    int h;
    while(scanf("%d", &h) && h){
        vector<string> s(h);
        rep(i, h) cin >> s[i];
        int idx = 0;
        printf("%d\n", expr(s, idx, 0, h));
    }
}
