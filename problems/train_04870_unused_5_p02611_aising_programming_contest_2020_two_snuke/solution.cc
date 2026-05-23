#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=1e9+7;
ll c1[]={539588932,729548371,700407153,404391958,962779130,184117322,927321758,444014759,542573865,237315285,417297686,471090892,183023413,660103155,727008098,869418286};
ll c0[]={0,765144583,346175634,347662323,5655049,184117322,927321758,444014759,542573865,237315285,417297686,471090892,183023413,660103155,727008098,869418286};
/*int solve(int n){
	ll ans=0;
	for(int s1=0; s1<=n; s1++){
		for(int s2=s1+1; s2+s1<=n; s2++){
			for(int n1=0; n1+s2+s1<=n; n1++){
				for(int n2=n1+1; n2+n1+s2+s1<=n; n2++){
					for(int u1=0; u1+n2+n1+s2+s1<=n; u1++){
						for(int u2=u1+1; u2+u1+n2+n1+s2+s1<=n; u2++){
							for(int k1=0; k1+u2+u1+n2+n1+s2+s1<=n; k1++){
								for(int k2=k1+1; k2+k1+u2+u1+n2+n1+s2+s1<=n; k2++){
									for(int e1=0; e1+k2+k1+u2+u1+n2+n1+s2+s1<=n; e1++){
										for(int e2=e1+1; e2+e1+k2+k1+u2+u1+n2+n1+s2+s1<=n; e2++){
											ans+=(s2-s1)*(n2-n1)*(u2-u1)*(k2-k1)*(e2-e1);
											ans%=MOD;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return ans;
}*/
int main()
{
	int t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n%2==0){
			ll ans=0;
			ll p=1;
			for(int i=0; i<16; i++){
				(ans+=c0[i]*p)%=MOD;
				(p*=n)%=MOD;
			}
			cout<<ans<<endl;
		}else{
			ll ans=0;
			ll p=1;
			for(int i=0; i<16; i++){
				(ans+=c1[i]*p)%=MOD;
				(p*=n)%=MOD;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}