#include<bits/stdc++.h>
#define ll long long
#define INF 1e18
#define N 2010
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
struct Info{int nu,ne,qu,fi;}a[N*20];
int s,t,n,z1,z2,z3,z4,x,y,z,num=1,b[N],li[1000010],la[N],mi[N];
ll di[N],ansn;
bool vi[N];
void jb(int x,int y,int z,int p){
	a[++num].nu=y;a[num].ne=b[x];b[x]=num;a[num].qu=z;a[num].fi=p;
	a[++num].nu=x;a[num].ne=b[y];b[y]=num;a[num].qu=0;a[num].fi=-p;
}
bool dij(){
	for (int i=1;i<=t;i++)di[i]=INF,vi[i]=1,mi[i]=0;di[s]=0;vi[s]=0;mi[s]=100;
	int l=1,r=1;li[l]=s;
	while (l<=r){
		for (int y=b[li[l]];y;y=a[y].ne){
			if (a[y].qu!=0){
				if (di[li[l]]+a[y].fi<di[a[y].nu]){
					di[a[y].nu]=di[li[l]]+a[y].fi;la[a[y].nu]=y;mi[a[y].nu]=min(mi[li[l]],a[y].qu);
					if (vi[a[y].nu]){vi[a[y].nu]=0;li[++r]=a[y].nu;}
				}
			}
		}
		vi[li[l]]=1;l++;
	}
	if (di[t]==INF) return 0;
	ansn=ansn-di[t]*mi[t];
	for (int i=t;i!=s;){
		i=la[i];
		a[i].qu-=mi[t];a[i^1].qu+=mi[t];
		i=a[i^1].nu;
	}
	return 1;
}
int main(){
	read(n);
	s=n+n+5,t=n+n+6,z1=n+n+1,z2=n+n+2,z3=n+n+3,z4=n+n+4;
	for (int i=1;i<=n;i++){
		read(x);read(y);read(z);
		jb(s,i,z,0);
		jb(i,z1,z,x+y);jb(i,z2,z,x-y);jb(i,z3,z,-x-y);jb(i,z4,z,-x+y);
	}
	for (int i=1;i<=n;i++){
		read(x);read(y);read(z);
		jb(i+n,t,z,0);
		jb(z3,i+n,z,x+y);jb(z4,i+n,z,x-y);jb(z1,i+n,z,-x-y);jb(z2,i+n,z,-x+y);
	}
	while (dij());
	cout<<ansn<<endl;
	return 0;
}