#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll 
a[]={1,1,1,1,-1,-1,-1,-1},
b[]={1,1,-1,-1,1,1,-1,-1},
c[]={1,-1,1,-1,1,-1,1,-1};

struct xyz{ll x,y,z;};
ll I;
bool cmp(xyz x,xyz y)
{
	ll A = a[I]*x.x+b[I]*x.y+c[I]*x.z;
	ll B = a[I]*y.x+b[I]*y.y+c[I]*y.z;
	return A > B;
}

int main()
{
	ll n,m;
	cin >> n >> m;
	vector<xyz> v(n);
	for(ll i = 0;i<n;i++)
	{
		cin >> v[i].x>>v[i].y>>v[i].z;
	}
	ll ans = 0;
	for(ll i =0 ;i<8;i++)
	{
		sort(v.begin(),v.end(),cmp);
		ll now = 0;

		for(ll j = 0;j<m;j++)
		{
			now+=v[j].x*a[I]+v[j].y*b[I]+v[j].z*c[I];
		}
		ans = max(now,ans);
		I++;
	}
	cout<<ans<<endl;

}