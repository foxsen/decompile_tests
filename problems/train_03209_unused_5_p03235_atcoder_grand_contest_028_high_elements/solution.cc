#include<cstdio>
#include<algorithm>
using namespace std;
int gi(){
	int x=0,w=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')w=0,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return w?x:-x;
}
const int N=2e5+5;
int n,q,a[N],b[N];
struct fenwick{
	int c[N],top,tt[N];pair<int,int>S[N*20];
	void init(int v){
		for(int i=1;i<=n;++i)c[i]=v;
	}
	void modify(int x,int v){
		while(x<=n){
			if(c[x]<v)S[++top]=make_pair(x,c[x]),c[x]=v;
			x+=x&-x;
		}
	}
	void rollback(int i){
		while(top>tt[i])c[S[top].first]=S[top].second,--top;
	}
	int query(int x){
		int res=-1<<30;
		while(x)res=max(res,c[x]),x^=x&-x;
		return res;
	}
}foo,bar;
bool check(int x,int v){
	if(v<0)return false;
	if(v&1)return foo.query(n+1-x)>=v;
	else return bar.query(n+1-x)>=v;
}
bool check(int max0,int max1,int dif){
	return check(max0,q-dif)||check(max1,q+dif);
}
int main(){
	n=gi();
	for(int i=1,pre_max=0;i<=n;++i){
		a[i]=gi();
		if(a[i]>pre_max){
			pre_max=a[i];
			b[i]=1;++q;
		}
	}
	foo.init(-1<<30);bar.init(0);
	for(int i=n;i;--i){
		int x=-1<<30,y=-1<<30;
		if(b[i]){
			x=foo.query(n+1-a[i])+2;
			y=bar.query(n+1-a[i])+2;
		}else{
			x=bar.query(n+1-a[i])+1;
			y=foo.query(n+1-a[i])+1;
		}
		foo.tt[i]=foo.top;foo.modify(n+1-a[i],x);
		bar.tt[i]=bar.top;bar.modify(n+1-a[i],y);
	}
	if(!check(1,q))return puts("-1"),0;
	for(int i=1,max0=1,max1=1,dif=0;i<=n;++i){
		if(b[i])--q;
		foo.rollback(i);bar.rollback(i);
		if(a[i]>=max0)
			if(check(a[i],max1,dif+1))
				putchar('0'),max0=a[i],++dif;
			else
				putchar('1'),dif-=a[i]>=max1,max1=max(max1,a[i]);
		else
			if(check(max0,max1,dif))
				putchar('0');
			else
				putchar('1'),dif-=a[i]>=max1,max1=max(max1,a[i]);
	}
	puts("");return 0;
}
