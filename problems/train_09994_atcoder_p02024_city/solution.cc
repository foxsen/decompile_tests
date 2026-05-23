#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
#define int long long
#define All(v) (v.begin(),v.end())
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
int lcm(int a, int b) {
	return a / gcd(a, b)*b;
}
int modpow(int a,int b){
    if(!b)return 1;
    if(b%2)return modpow(a,b-1)*a%MOD;
    return modpow(a,b/2)*modpow(a,b/2)%MOD;
}
int fac(int a){
    int Ans=1;
    for(int i=1;i<=a;i++){
        Ans*=i;
        Ans%=MOD;
    }
    return Ans;
}//kaijo
int comb(int a,int b){
    return fac(a)*modpow(fac(a-b),MOD-2)%MOD*modpow(fac(b),MOD-2)%MOD;
}
signed main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if((a*b)%2&&(c+d)%2)puts("No");
	else puts("Yes");
	return 0;
}



