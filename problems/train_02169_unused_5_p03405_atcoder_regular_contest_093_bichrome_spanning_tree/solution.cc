#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
inline ll read()
{
	ll x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 1000
#define MM 2000
#define mod 1000000007
struct edge{int x,y,w;}e[MM+5];
bool cmp(const edge&a,const edge&b){return a.w<b.w;}
int f[MN+5];
int gf(int k){return f[k]?f[k]=gf(f[k]):k;}
int ans=1;
inline int pow(int x,int k){
    int sum=1;
    for(;k;k>>=1,x=1LL*x*x%mod) if(k&1) sum=1LL*sum*x%mod;
    return sum;
}
int main(){
	int n,m,i,j,s1=0,s2=1;ll s,x;
	n=read();m=read();x=read();
	for(i=1;i<=m;++i)e[i].x=read(),e[i].y=read(),e[i].w=read();
	sort(e+1,e+m+1,cmp);
	for(i=2;i<=m;++i){
		memset(f,s=0,sizeof(f));
		if(gf(e[i].x)!=gf(e[i].y))f[gf(e[i].x)]=gf(e[i].y),s+=e[i].w;
		for(j=1;j<=m;++j)if(gf(e[j].x)!=gf(e[j].y))f[gf(e[j].x)]=gf(e[j].y),s+=e[j].w;
		if(s==x)++s1;if(s>x) ans=(2*ans)%mod;
	}
	printf("%d",2LL*ans*(pow(2,s1)-1)%mod);
}