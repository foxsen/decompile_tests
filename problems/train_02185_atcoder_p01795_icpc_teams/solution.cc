#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
const int N=1000100,P=1e9+9;
#define X first
#define Y second
int a[18],b[18],c[18],dp[N];
unordered_map<int,int>f,sz;
int main()
{
	memset(dp,-1,sizeof(dp));
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	dp[0]=1;
	for(int i=1;i<=n;i++)dp[i]=1ll*(3*i-1)*(3*i-2)/2%P*dp[i-1]%P;
	for(int i=0;i<m;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=0;i<(1<<m);i++)
	{
		int coef=1,res=1,cnt[4]={};
		bool ff=0;f.clear();sz.clear();
		for(int j=0;j<m;j++)
		{
			if(i&(1<<j))
			{
				if(c[j])coef*=-1;
				if(!f.count(a[j]))f[a[j]]=a[j],sz[a[j]]=1;
				if(!f.count(b[j]))f[b[j]]=b[j],sz[b[j]]=1;
				if(f[a[j]]!=f[b[j]])
				{
					if(sz[f[a[j]]]+sz[f[b[j]]]>3)ff=1;
					else if(sz[f[a[j]]]<sz[f[b[j]]])f[a[j]]=f[b[j]],sz[f[b[j]]]++;
					else f[b[j]]=f[a[j]],sz[f[a[j]]]++;
				}
			}
			else if(!c[j]) coef=0;
		}
		if(!ff)
		{
			for(auto it=f.begin();it!=f.end();++it)if(it->X==it->Y)cnt[sz[it->X]]++;
			cnt[1]=3*n-2*cnt[2]-3*cnt[3];
			for(int i=0;i<cnt[2];i++){res=1LL*res*cnt[1]%P;cnt[1]--;}
			res=1LL*res*dp[cnt[1]/3]%P;
		}
		else res=0;
		ans=(ans+1ll*res*(P+coef))%P;
	}
	printf("%d\n",ans);
	return 0;
}
