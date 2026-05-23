#include<bits/stdc++.h>
using namespace std;

const int N=200100,mod=1000000007;
inline void reduce(int&x){x+=x>>31&mod;}
int n,l[N],r[N],f[N],b[N];
pair<int,int>a[N];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i].first>>a[i].second,b[i]=a[i].second;;
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)a[i].second=lower_bound(b+1,b+n+1,a[i].second)-b;
	for(int i=1,j=1;i<=n;++i)r[i]=j=max(j,a[i].second);
	for(int i=n,j=n;i;--i)l[i]=j=min(j,a[i].second);
	int L=0,R=0,sum=1;f[0]=1;
	for(int i=1;i<=n;++i){
		for(;L<l[i]-1;reduce(sum-=f[L++]));
		for(;R<r[i];reduce(sum+=f[++R]-mod));
		reduce(f[R]+=sum-mod);reduce(sum+=sum-mod);
	}
	cout<<f[n]<<'\n';
	return 0;
}
