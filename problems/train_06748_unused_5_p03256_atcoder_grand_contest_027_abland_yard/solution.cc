#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define SF scanf
#define PF printf
#define MAXN 200010
using namespace std;
typedef long long ll;
int n,m;
int cnt[MAXN][2];
char s[MAXN];
bool del[MAXN];
vector<int> a[MAXN];
void dfs(int x){
	del[x]=1;
	for(int i=0;i<a[x].size();i++){
		int u=a[x][i];
		if(del[u]==0){
			cnt[u][s[x]-'A']--;
			if(cnt[u][s[x]-'A']==0)
				dfs(u);
		}
	}
}
int main(){
	SF("%d%d",&n,&m);
	SF("%s",s+1);
	int u,v;
	for(int i=1;i<=m;i++){
		SF("%d%d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
		cnt[v][s[u]-'A']++;
		cnt[u][s[v]-'A']++;	
	}
	for(int i=1;i<=n;i++)
		if(del[i]==0&&(cnt[i][0]==0||cnt[i][1]==0))
			dfs(i);
	for(int i=1;i<=n;i++)
		if(del[i]==0){
			PF("Yes");
			return 0;
		}
	PF("No");
}