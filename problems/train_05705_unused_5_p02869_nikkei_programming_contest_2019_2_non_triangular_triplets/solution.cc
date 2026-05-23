#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
#define maxn 200010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static int buf[20],len; len=0;
	if(x<0)x=-x,putchar('-');
	for(;x;x/=10)buf[len++]=x%10;
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]+'0');
}
inline void writeln(ll x){write(x); putchar('\n');}
inline void writesp(ll x){write(x); putchar(' ');}
int a[maxn],b[maxn],c[maxn];
int n,k;
int main()
{
	n=read(); k=read();
	if(n<2*k-1){
		puts("-1"); return 0;
	}
	for(int i=0;i<n;i+=2){
		int t=i/2;
		a[i]=t; b[i]=2*n-(n+1)/2+t; c[i]=2*n+i;
	}
	for(int i=1;i<n;i+=2){
		int t=i/2;
		a[i]=(n+1)/2+t; b[i]=n+t; c[i]=2*n+i;
	}
	for(int i=0;i<n;i++)
		writesp(a[i]+k),writesp(b[i]+k),writeln(c[i]+k);
	return 0;
}