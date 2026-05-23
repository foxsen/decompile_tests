#include<bits/stdc++.h>
using namespace std;
#define mo 1000000007ll
#define N 100010
#define int long long
int n,d[N],a[N],vi[N],c[N],le[N],s[N],f[N],ans;
void dfs(int x){
	int v=0,y=0,z=0,p=0;
	while(c[x]){
		v++;
		c[x]=0;
		if(le[x]){
			if(!y){
				z=y=v;
				p=le[x];
			}
			else{
				ans=ans*((le[x]<v-z)+(le[x]<=v-z))%mo;
				z=v;
			}
		}
		x=a[x];
	}
	if(!y)s[v]++;
	else ans=ans*((p<v-z+y)+(p<=v-z+y))%mo;
}
void dp(){
	for(int i=1;i<=n;i++){
		if(d[i])continue;
		int x=i,l=0;
		while(!c[x]){
			x=a[x];
			l++;
		}
		le[x]=l;
	}
	ans=1;
	for(int i=1;i<=n;i++)
		if(c[i])dfs(i);
	for(int i=1;i<=n;i++)
		if(s[i]){
			f[0]=1;
			for(int j=1;j<=s[i];j++){
				if(i>1&&(i&1))
					f[j]=f[j-1]*2ll%mo;
				else f[j]=f[j-1];
				if(j>1)f[j]=(f[j]+f[j-2]*(j-1)%mo*i%mo)%mo;
			}
			ans=ans*f[s[i]]%mo;
		}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(vi[i])continue;
		int x=i;
		while(!vi[x]){
			vi[x]=i;
			x=a[x];
		}
		if(vi[x]!=i)continue;
		while(!c[x]){
			c[x]=1;
			x=a[x];
		}
	}
	for(int i=1;i<=n;i++)
		if((c[i]&&d[i]>2)||(!c[i]&&d[i]>1)){
			puts("0");
			return 0;
		}
	dp();
	cout<<ans;
}