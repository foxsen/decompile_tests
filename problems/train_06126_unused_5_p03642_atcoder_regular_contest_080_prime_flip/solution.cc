#include <bits/stdc++.h>
using namespace std;
#define N 10000010
#define M 110
int p[N],isp[N],s[N],a[M],b[M],vis[M*2],mat[M*2];
vector <int> E[M];
bool dfs(int x){
	for (auto &i:E[x]){
		if (!vis[i]){
			vis[i]=1;
			if (!mat[i] || dfs(mat[i])){
				mat[i]=x;return 1;
			}
		}
	}
	return 0;
}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		x=x*10+ch-'0';ch=getchar();
	}
	return x*f;
}
int main(){
	int tot=0,cnt1=0,cnt2=0,ans=0;
	for (int i=2;i<N;++i){
		if (!isp[i]) p[++tot]=i;
		for (int j=1;j<=tot && i*p[j]<N;++j){
			isp[i*p[j]]=1;
			if (i%p[j]==0) break;
		}
	}
	int n=read();isp[1]=1;
	for (int i=1;i<=n;++i) s[read()]=1;
	for (int i=1;i<N;++i){
		if (s[i]!=s[i-1]){
			if (i&1) a[++cnt1]=i;
			else b[++cnt2]=i;
		}
	}
	for (int i=1;i<=cnt1;++i){
		for (int j=1;j<=cnt2;++j){
			if (!isp[abs(a[i]-b[j])]) E[i].push_back(j);
		}
	}
	for (int i=1;i<=cnt1;++i){
		memset(vis,0,sizeof(vis));ans+=dfs(i);
	}
	cout<<ans+(cnt1-ans)/2*2+(cnt2-ans)/2*2+((cnt1-ans)&1)*3<<endl;
	return 0;
}