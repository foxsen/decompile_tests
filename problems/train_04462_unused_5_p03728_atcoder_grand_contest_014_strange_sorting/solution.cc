#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=300010,P=1e9+7;
inline int read(){
	int x=0,f=0,c=getchar();
	for(;c>'9'||c<'0';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+c-'0';return f?-x:x;
}
int n,i,a[N],p[N],f[N],g[N];
int main(){
	//freopen("1.out","w",stdout);
	n=read();
	for(i=1;i<=n;i++)p[a[i]=read()]=i;
	f[n]=n;for(i=n-1;i;i--)
	if(!g[i+1]){
		if(p[i]>p[i+1])g[i]=1,f[i]=i+1;
		else g[i]=g[i+1],f[i]=f[i+1];
	}else{
		if(((p[i]<p[i+1])+(p[f[i+1]]<p[i])+(p[i+1]<p[f[i+1]]))==2)
		g[i]=g[i+1],f[i]=f[i+1];else g[i]=g[i+1]+1,f[i]=i+1;
	}printf("%d\n",g[1]);
	return 0;
}