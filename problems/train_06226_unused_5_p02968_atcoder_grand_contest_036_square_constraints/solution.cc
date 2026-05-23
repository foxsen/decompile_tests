#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=555;
int n,mod;
LL dp[Maxn][Maxn];
int f[Maxn],g[Maxn];
int rf[Maxn],rg[Maxn];
int pf[Maxn];
int ord[Maxn*2],ko;
LL coef[Maxn][Maxn];
bool cmp(int x,int y){
	int vx,vy;
	if (x<0) vx=g[~x];
	else vx=f[x];
	if (y<0) vy=g[~y];
	else vy=f[y];
	if (vx!=vy) return vx<vy;
	if (x<0 && y>=0) return x<y;
	if (x>=0 && y<0) return x<y;
	if (x<0)return x<y;
	return x>y;
}
void Add(LL &x,LL y){
	x+=y;
	if (x>=mod) x-=mod;
}
int main(){
	scanf("%d%d",&n,&mod);
	int t=n;
	for (int i=0;i<n;i++){
		while (t*t+i*i>=n*n) t--;
		f[i]=t+1;
	}
	t=2*n-1;
	for (int i=0;i<2*n;i++){
		while (t*t+i*i>n*n*4) t--;
		g[i]=t+1;
	}
	for (int i=0;i<n;i++) ord[ko++]=i;
	for (int i=0;i<2*n;i++) ord[ko++]=~i;
	sort(ord,ord+ko,cmp);
	for (int i=0;i<ko;i++){
		if (ord[i]>=0) rf[ord[i]]=i;
		else rg[~ord[i]]=i;
	}
	int tmp=0;
	for (int i=0;i<n;i++){
		while (tmp<=2*n-1 && rg[tmp]>rf[i]){
			tmp++;
		}
		pf[i]=tmp;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<=2*n;j++){
			coef[i][j]=1;
			int cur=j;
			int pp=(i)?pf[i-1]:n;
		//	cout<<i<<' '<<j<<' '<<pp<<endl;
			for (int k=pf[i]-1;k>=pp;k--){
				coef[i][j]=coef[i][j]*(g[k]-cur)%mod;
		//		cout<<g[k]-cur<<endl;
				cur++;
			}
		//	cout<<coef[i][j]<<endl;
		}
	}
	LL ans=0;
	for (int k=0;k<=n;k++){
		LL cf=(k&1)?1:-1;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
	//	cout<<k<<endl;
		for (int i=0;i<=n;i++){
			for (int j=0;j<=min(i,k);j++){
			//	cout<<i<<' '<<j<<" "<<dp[i][j]<<endl;
				if (!dp[i][j] || i==n) continue;
				int pos=n-k+j+pf[i]-n;
				pos=2*n-1-pos;
				if (j+1<=k){
					LL C1=1ll*(f[i]-pos)*coef[i][pos+1]%mod;
					Add(dp[i+1][j+1],dp[i][j]*C1%mod);
				}
				
				int pos2=2*n-1-(i-j);
			//	cout<<g[i]-pos2<<endl;
			//	cout<<"FF"<<" "<<g[i]-pos2<<' '<<coef[i][pos+1]<<' '<<pos<<endl;
				Add(dp[i+1][j],dp[i][j]*(g[i]-pos2)%mod*coef[i][pos+1]%mod);
			}
		}
	//	cout<<k<<' '<<dp[n][k]<<endl;
		if (k&1) ans-=dp[n][k];
		else ans+=dp[n][k];
	}
	ans=(ans%mod+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}