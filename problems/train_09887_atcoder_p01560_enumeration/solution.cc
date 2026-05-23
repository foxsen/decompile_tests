#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define MP make_pair
#define PB push_back
typedef long double ld;
typedef long long ll;

ll gcd(ll a,ll b){
    if(b==1)return b;
    if(b==0)return a;
    if(a<b)return gcd(b,a);
    if(a%b==0)return b;
    return gcd(b,a%b);
}

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll>a(n);
    rep(i,n)cin >> a[i];
    vector<ld>p(n);
    rep(i,n){
        int tmp;
        cin >> tmp;
        p[i] = (ld)tmp/(ld)100.0;
    }
    vector<ld> pp(1<<n,(ld)1.0);
    vector<int> s(1<<n);
    vector<ld> dp(n+1);
    dp[0] = (ld)0.0;
    rep(bit,1<<n){
        rep(i,n){
            if((bit>>i)&1){
                pp[bit] *= p[i];
                s[bit]++;
            }else{
                pp[bit] *=((ld)1.0-p[i]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        dp[i] = ((ld)1.0-p[i-1])*dp[i-1];
        
        ld tmp= dp[i-1];
        tmp += (ld)(m/a[i-1]);
        rep(bit,1<<(i-1)){
            if(bit==0)continue;
            ll x = a[i-1];
            bool flag = 0;
            rep(j,i-1){
                if((bit>>j)&1){
                    ll y = gcd(x,a[j]);
                    if((ld)x/(ld)y>(ld)(m+100000)/a[j]){
                        flag = 1;
                        break;
                    }else{
                        x = x/y;
                        x *= a[j];
                    } 
                }
            }
            if(flag)continue;
            ld hoge = (ld)(m/x);
            ld sss = 1.0;
            for(int k = 0;k<i-1;k++){
                if(bit>>k&1){
                    sss *= p[k];
                }
            }
            if(s[bit]%2==0){
                
                tmp += sss*hoge;
            }else{
                tmp -= sss*hoge;
            }
        }
        dp[i] += tmp*p[i-1];
    } 
    cout << fixed << setprecision(15) <<  dp[n] << endl;
    return 0;
}
