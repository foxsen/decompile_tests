#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,m,s,t,f;
ll dist[105][105];
ll dist2[105][105];
ll dist3[105][105];
int u[1005],v[1005],a[1005],b[1005],d[1005];

int main(void){
	scanf("%d%d%d%d%d",&n,&m,&s,&t,&f);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dist[i][j]=1LL<<50;
			dist2[i][j]=1LL<<50;
			dist3[i][j]=1LL<<50;
		}
		dist[i][i]=0;
		dist2[i][i]=0;
		dist3[i][i]=0;
	}
	int d2=-1;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d%d",&u[i],&v[i],&a[i],&b[i],&d[i]);
		d[i]=min(d[i],f);
		if(a[i]<b[i]){
			d2=d[i];
		}
		ll val=a[i]*f;
		if(f>=d[i]){
			val=a[i]*d[i]+(f-d[i])*b[i];
		}
		dist[u[i]][v[i]]=min(dist[u[i]][v[i]],val);
	}
	if(d2!=-1){
		for(int i=0;i<m;i++){
			ll val=a[i]*d2;
			if(d2>=d[i]){
				val=a[i]*d[i]+(d2-d[i])*b[i];
			}
			dist2[u[i]][v[i]]=min(dist2[u[i]][v[i]],val);
		}
		d2=f-d2;
		for(int i=0;i<m;i++){
			ll val=a[i]*d2;
			if(a[i]<b[i])continue;
			if(d2>=d[i]){
				val=a[i]*d[i]+(d2-d[i])*b[i];
			}
			dist3[u[i]][v[i]]=min(dist3[u[i]][v[i]],val);
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				dist2[i][j]=min(dist2[i][j],dist2[i][k]+dist2[k][j]);
				dist3[i][j]=min(dist3[i][j],dist3[i][k]+dist3[k][j]);
			}
		}
	}
	ll ans=dist[s][t];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans=min(ans,dist2[i][j]+dist[s][i]+dist[j][t]+dist3[i][j]);
		}
	}
	if(ans==(1LL<<50)){
		printf("Impossible\n");
	}else{
		printf("%lld\n",ans);
	}
	return 0;
}
