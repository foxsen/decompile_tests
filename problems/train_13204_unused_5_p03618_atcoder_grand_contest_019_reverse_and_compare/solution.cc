#include<cstdio>
#include<cstring>
#define maxn 200005
#define D 26
#define LL long long
int n,cnt[D];
char s[maxn];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
	LL ans=1ll*n*(n-1)/2;
	for(int i=0;i<D;i++) ans-=1ll*cnt[i]*(cnt[i]-1)/2;
	printf("%lld\n",ans+1);
}