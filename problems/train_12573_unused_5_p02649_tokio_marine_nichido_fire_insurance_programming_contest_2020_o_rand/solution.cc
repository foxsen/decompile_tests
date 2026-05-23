#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=52,M=(1<<18)|5;
int n,k,S,T;
int a[N],cnt[M],q[N];
ll f[N][N],ans;
void init(){
	For(i,1,M-1) cnt[i]=cnt[i/2]+(i&1);
	For(i,0,N-1) f[i][0]=1;
	For(i,1,N-1) For(j,1,i) f[i][j]=f[i-1][j]+f[i-1][j-1];
	For(i,0,N-1) For(j,2,N-1) f[i][j]+=f[i][j-1];
}
int main(){
	init();
	scanf("%d%d%d%d",&n,&k,&S,&T);
	For(i,1,n){
		scanf("%d",&a[i]);
		if ((a[i]&S)!=S||(a[i]|T)!=T)
			--i,--n;
	}
	if ((S&T)!=S||(S|T)!=T)
		return puts("0"),0;
	//cout<<233<<endl;
	T-=S;
	For(i,1,n) a[i]-=S;
	For(i,0,T) if ((T&i)==i){
		For(j,1,n) q[j]=a[j]&i;
		sort(q+1,q+n+1);
		int s=1;
		For(j,2,n+1)
			if (j==n+1||q[j]!=q[j-1])
				ans+=f[s][k]*(cnt[i]&1?-1:1),s=1;
			else ++s;
	}
	cout<<ans<<endl;
} 