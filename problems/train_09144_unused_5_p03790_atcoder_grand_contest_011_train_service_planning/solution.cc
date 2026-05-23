#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int N=100005;
int n,k,ans,a[N],b[N],L[N],R[N],sum[N],f[N],h[N*2],val[N*8];
void pushdown(int o){
	if(val[o]){
		val[o*2]=val[o*2+1]=val[o];
		val[o]=0;
	}
}
void update(int o,int l,int r,int L,int R,int v){
	if(L>R){
		return;
	}
	if(L<=l&&R>=r){
		val[o]=v;
		return;
	}
	pushdown(o);
	int mid=(l+r)/2;
	if(L<=mid){
		update(o*2,l,mid,L,R,v);
	}
	if(R>mid){
		update(o*2+1,mid+1,r,L,R,v);
	}
}
int query(int o,int l,int r,int k){
	if(l==r){
		return val[o];
	}
	pushdown(o);
	int mid=(l+r)/2;
	if(k<=mid){
		return query(o*2,l,mid,k);
	}else{
		return query(o*2+1,mid+1,r,k);
	}
}
int get(int x){
	int res=query(1,1,h[0],x);
	if(!res){
		return 0;
	}
	return f[res]+(h[L[res]]-h[x]+k)%k;
}
signed main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
		sum[i]=sum[i-1]+a[i];
		if(b[i]==1){
			L[i]=sum[i-1]%k*(k-2)%k;
			R[i]=sum[i]%k*(k-2)%k;
			if(a[i]*2>k){
				return puts("-1"),0;
			}
		}else{
			L[i]=0;
			R[i]=k-1;
		}
		h[++h[0]]=L[i];
		h[++h[0]]=R[i];
	}
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	for(int i=n;i>=1;i--){
		L[i]=lower_bound(h+1,h+h[0]+1,L[i])-h;
		R[i]=lower_bound(h+1,h+h[0]+1,R[i])-h;
		f[i]=get(L[i]);
		if(L[i]>R[i]){
			update(1,1,h[0],R[i]+1,L[i]-1,i);
		}else{
			update(1,1,h[0],1,L[i]-1,i);
			update(1,1,h[0],R[i]+1,h[0],i);
		}
	}
	ans=f[1];
	for(int i=1;i<=h[0];i++){
		ans=min(ans,get(i));
	}
	printf("%lld\n",ans+2*sum[n]);
	return 0;
}