#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5,P=998244353,Gi=332748118;
 
#define PII pair<int,int>
inline int add(const int &x,const int &y){return x+y>P?x+y-P:x+y;}
inline int dec(const int &x,const int &y){return x-y<0?x-y+P:x-y;}
inline int mul(const int &x,const int &y){return 1LL*x*y>P?1LL*x*y%P:x*y;}
 
int ksm(int x,int y=P-2){
    int ans=1;
    for(;y;y>>=1,x=mul(x,x))
        if(y&1)ans=mul(ans,x);
    return ans;
}
 
int lim,r[N],a[N],b[N],o[N],l;
int n,h[N],m,p[N],ans,fac[N],inv[N];
vector<int>f[N];
void init(int len){
    lim=1,l=-1;
    while(lim<=len)lim<<=1,++l;
    for(int i=1;i<lim;i++)r[i]=(r[i>>1]>>1)|((i&1)<<l);
}
void NTT(int *A,int ty){
    for(int i=0;i<lim;i++)
        if(i<r[i])swap(A[i],A[r[i]]);
    for(int p=1;p<lim;p<<=1){
        int D=p<<1,wn=ksm(ty==1?3:Gi,(P-1)/D);
        o[0]=1;
        for(int i=1;i<p;i++)o[i]=mul(o[i-1],wn);
        for(int i=0;i<lim;i+=D){
            for(int j=0;j<p;j++){
                int x=A[i+j],y=mul(A[i+j+p],o[j]);
                A[i+j]=add(x,y),A[i+j+p]=dec(x,y);
            }
        }
    }
    if(ty==-1)
        for(int i=0,INV__=ksm(lim);i<lim;i++)
            A[i]=mul(A[i],INV__);
}
int C(int x,int y){
	return mul(fac[y],mul(inv[x],inv[y-x]));
}
int A(int x,int y){
	return mul(fac[y],inv[y-x]);
}
priority_queue<PII,vector<PII>,greater<PII> >Q;
signed main(){
    scanf("%lld",&n),n*=2;
    for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
    sort(h+1,h+1+n);
    for(int i=1;i<=n;i++){
    	if(h[i]!=h[i-1])p[++m]=1;
    	else p[m]++;
	}
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	inv[n]=ksm(fac[n]);
	for(int i=n-1;~i;i--)inv[i]=mul(inv[i+1],i+1);
    for(int i=1;i<=m;i++){
    	for(int j=0;j<=(p[i]>>1);j++){
    		f[i].push_back(mul(mul(A(j,p[i]),C(j,p[i]-j)),ksm(ksm(2,j))));
		}
		Q.push(PII(f[i].size(),i));
	}
	while(Q.size()>1){
		int u=Q.top().second;
		Q.pop();
		int v=Q.top().second;
		Q.pop(); 
		int su=f[u].size(),sv=f[v].size();
		init(su+sv-2);
		for(int i=0;i<=lim;++i) a[i]=b[i]=0;
		for(int i=0;i<su;++i) a[i]=f[u][i];
		for(int i=0;i<sv;++i) b[i]=f[v][i];
		NTT(a,1),NTT(b,1);
		for(int i=0;i<lim;i++) a[i]=mul(a[i],b[i]);
		NTT(a,-1);
		++m;
		if(!Q.size()){
			for(int i=0;i<=su+sv-2;++i)
				ans=add(ans,mul(mul(ksm(P-1,i),a[i]),mul(A((n-2*i)>>1,n-2*i),ksm(ksm(2,(n-2*i)>>1)))));
			break;
		}
		for(int i=0;i<=su+sv-2;++i) f[m].push_back(a[i]);
		Q.push(PII(f[m].size(),m));
	}
	printf("%lld\n",(ans+P)%P);
}