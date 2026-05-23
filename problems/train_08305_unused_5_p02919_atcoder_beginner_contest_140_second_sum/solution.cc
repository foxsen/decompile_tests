#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
int n,x,w[100010],le[100010],ho[100010];
ll ans;
int main(){
	read(n);
	for (int i=1;i<=n;i++){read(x);w[x]=i;}
	for (int i=1;i<=n;i++)le[i]=i-1,ho[i]=i+1;
	for (int i=1;i<=n;i++){
		int x=le[w[i]],y=le[x];
		int z=ho[w[i]],p=ho[z];
		if (x!=0)ans+=1ll*(x-y)*(z-w[i])*i;
		if (z!=n+1)ans+=1ll*(w[i]-x)*(p-z)*i;
		ho[x]=z;le[z]=x;
	}
	cout<<ans<<endl;
	return 0;
}