#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,n,k,a[300010],t[300010];
ll l[300010],r[300010],p;
int main()
{
	ios::sync_with_stdio(false); 
	cin>>q;
	while(q--)
	{
		memset(t,0x3f,sizeof(t));
		cin>>n>>k;
		for(int i=1;i<=k;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=k;i++)
		{
			cin>>t[a[i]];
		}
		p=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			p=min(p+1,t[i]);
			l[i]=p;
		}
		p=0x3f3f3f3f;
		for(int i=n;i>=1;i--)
		{
			p=min(p+1,t[i]);
			r[i]=p;
		}
		for(int i=1;i<=n;i++)
		{
			cout<<min(l[i],r[i])<<" ";
		}
		cout<<"\n";
	} 
}