#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>
#include <climits>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;
#define ll long long
#define INF LONG_LONG_MAX
#define pll pair<ll,ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
const ll N=998244353;
void extgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    else {
        extgcd(b, a % b, x, y);
        ll nx = y;
        ll ny = x - (a / b) * y;
        x = nx;
        y = ny;
        return;
    }
}
int main(){
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		string s;
		cin >> n;
		cin >> s;
		ll start=0,end=n-1;
		while(start<n && s[start]!='0') start++;
		while(end>-1 && s[end]!='0') end--;
		start%=2;
		if((n-1-end)%2==1) end=n-2;
		else end=n-1;
		ll cntz=0,cnt=0;
		for(int i=start;i<=end;i++){
			if(s[i]=='0') cntz++;
			if(s[i]=='1' && s[i+1]=='1'){
				cnt++;
				i++;
			}
		}
		//cout << cntz << " " << cnt << endl;
		ll ans=1;
		for(int i=cntz+1;i<=cnt+cntz;i++){
			ans*=i;
			ans%=N;
		}
		for(int i=1;i<=cnt;i++){
			ll x,y;
			extgcd(i, N, x, y);
			if(x<0) x+=N;
			ans*=x;
			ans%=N;
		}
		cout << ans << endl;
	}
	return 0;
}