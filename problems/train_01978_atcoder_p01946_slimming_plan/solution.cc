#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
ll inf =  1e9;


int main(){
    ll s,t,d;
    cin>>s>>t>>d;
    ll aim = s-t;
    vector<ll> w(d);
    for(ll i=0;i<d;i++)cin>>w[i];
    ll sumw = w[0];
    vector<ll> dp(d,0);
    dp[0] = w[0];
    for(ll i=1;i<d;i++)sumw += w[i],dp[i] = dp[i-1] + w[i];
    ll mi = inf;
    for(ll i=0;i<d;i++){
	if( aim + dp[i] <= 0 ){
	    cout<<i+1<<endl;
	    return 0;
	}
	mi =  min( mi , dp[i] );
    }
    if( sumw >= 0 ){
	cout<<-1<<endl;
	return 0;
    }
    mi = abs( mi );
    ll res = ( aim - mi )/(-sumw) ;
    aim += res *  sumw ;
    res *= d;
    while( aim  > 0 ){
	aim +=w[ res % d ];
	res++;
    }
    cout<<res<<endl;

    return 0;
}

