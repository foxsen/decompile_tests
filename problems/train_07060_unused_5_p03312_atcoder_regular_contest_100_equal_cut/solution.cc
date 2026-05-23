#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=(2e5)+10;
int n;
ll s[maxn],a[maxn],s1,s2,s3,s4,ans=1e18;
int find(int l,int r,ll x) {
	while (l<r) {
		int mid=(l+r+1)/2;
		if (s[mid]<=x) l=mid;
		else r=mid-1;
	}
	return l;
}
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for (int i=2;i<n-1;i++) {
		s1=find(0,i,s[i]/2),s2=s1+1;
		s3=find(i+1,n,s[i]+(s[n]-s[i])/2),s4=s3+1;
		int s5,s6;
		if (abs(s[i]-s[s1]-s[s1])<abs(s[i]-s[s2]-s[s2])) s5=s1; else s5=s2;
		if (abs(s[n]-s[s3]-s[s3]+s[i])<abs(s[n]-s[s4]-s[s4]+s[i])) s6=s3; else s6=s4;
		ans=min(max(max(s[s5],s[i]-s[s5]),max(s[s6]-s[i],s[n]-s[s6]))
		-min(min(s[s5],s[i]-s[s5]),min(s[s6]-s[i],s[n]-s[s6])),ans);
	}
	printf("%lld\n",ans);
	return 0;
}