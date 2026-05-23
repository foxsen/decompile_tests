#include <stdio.h>
#include <algorithm>
#define MN 300000
#define MA 300000

int n,k,ans=0;

int T[MA*4+5]={0};

void modify(int k,int l,int r,int p,int w){
	if(l==r){
		T[k] = w;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid) modify(k<<1,l,mid,p,w);
	else modify(k<<1|1,mid+1,r,p,w);
	T[k] = std::max(T[k<<1],T[k<<1|1]);
}

int query(int k,int l,int r,int L,int R){
	if(l==L&&r==R) return T[k];
	int mid=(l+r)>>1;
	if(R<=mid) return query(k<<1,l,mid,L,R);
	if(L>mid) return query(k<<1|1,mid+1,r,L,R);
	return std::max(query(k<<1,l,mid,L,mid),query(k<<1|1,mid+1,r,mid+1,R));
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,a;i<=n;i++){
		scanf("%d",&a);
		int t = query(1,0,MA,std::max(0,a-k),std::min(MA,a+k))+1;
		ans = std::max(ans,t);
		modify(1,0,MA,a,t);
	}
	printf("%d\n",ans);
}