#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
const int maxn=110;
void chkmin(long long &x,long long y){
	x=x<y?x:y;
}
void chkmax(long long &x,long long y){
	x=x>y?x:y;
}
struct node{
	long long pri;
	int siz,lim;
}a[maxn],stk[10010];
bool cmp(const node &A,const node &B){
	return A.siz*B.pri>B.siz*A.pri;
}
int n,X,D;
int f[maxn];
long long dp[51*51*51];
void get_dp(){
	int top=0,l;
	for(int i=1;i<=n;i++){
		l=a[i].lim<=n?a[i].lim:n;
		a[i].lim-=l;
		for(int j=0;;j++){
			if((1<<j)<=l){
				stk[++top]=(node){a[i].pri*(1<<j),a[i].siz*(1<<j),1};
				l-=1<<j;
			}
			else
				break;
		}
		if(l) stk[++top]=(node){a[i].pri*l,a[i].siz*l,1};
	}
	for(int i=n*n*n;i>=0;i--)
		dp[i]=INF;
	dp[0]=0;
	for(int i=1;i<=top;i++)
		for(int j=n*n*n;j>=stk[i].siz;j--){
			chkmin(dp[j],dp[j-stk[i].siz]+stk[i].pri);
		}
}
int main(){
	scanf("%d%d%d",&n,&X,&D);
	scanf("%lld",&a[1].pri);
	for(int i=2;i<=n;i++)
		scanf("%lld%d",&a[i].pri,&f[i]);
	for(int i=n;i>=1;i--){
		a[i].siz++;
		a[f[i]].pri+=a[i].pri;
		a[f[i]].siz+=a[i].siz;
	}
	for(int i=2;i<=n;i++)
		a[i].lim=D;
	a[1].lim=1e9+100;
	sort(a+1,a+n+1,cmp);
	get_dp();
	long long ans=0,sum;
	long long res,v;
	for(int i=n*n*n;i>=0;i--){
		res=X-dp[i],sum=i;
		if(res<0) continue;
		for(int j=1;j<=n;j++){
			v=res/a[j].pri;
			if(a[j].lim<v) v=a[j].lim;
			res-=v*a[j].pri;
			sum=sum+v*a[j].siz;
		}
		chkmax(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
