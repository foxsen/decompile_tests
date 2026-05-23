#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
#define N 100005
#define M 2000005
char a[N],b[N],c[M],d[M];
int p[M],cf[N],qh[N][26],inv[N];
int pw(int x,int p){
	int ans=1;
	while(p){
		if(p&1)ans=1ll*ans*x%P;
		x=1ll*x*x%P;p>>=1;
	}return ans;
}
int main(){
	cf[0]=1;inv[0]=1;
	for(int i=1;i<N;++i)cf[i]=2*cf[i-1]%P,inv[i]=pw(cf[i],P-2);
	int n,q;
	scanf("%d%d",&n,&q);
	scanf("%s%s",b+1,a+1);
	for(int i=n;i>=1;--i){
		for(int j=0;j<26;++j)qh[i][j]=qh[i+1][j];
		qh[i][a[i]-'a']=(qh[i][a[i]-'a']+cf[n-i])%P;
	}
	int m1=strlen(b+1);
	for(int i=1;i<=q;++i){
		int k;scanf("%d",&k);
		scanf("%s",c+1);
		int m2=strlen(c+1);
		int t1=m1,t2=0;
		while(t1<m2)t1=t1*2+1,++t2;
		if(t2>k)puts("0");
		else{
			t1=m1;t2=0;
			for(int j=1;j<=m1;++j)d[j]=b[j];
			while(t1<m2){
				for(int j=1;j<=t1;++j)d[j+t1+1]=d[j];
				d[t1+1]=a[t2+1];
				++t2;t1=t1*2+1;	
			}
			for(int j=2;j<=m2;++j){
				int k=p[j-1];
				while(k&&c[k+1]!=c[j])k=p[k];
				if(c[k+1]==c[j])++k;
				p[j]=k;
			}int t=0,ans=0;
			for(int j=1;j<=t1;++j){
				while(t&&c[t+1]!=d[j])t=p[t];
				if(c[t+1]==d[j])++t;
				if(t==m2)ans++;
			}ans=1ll*ans*cf[k-t2]%P;
			for(int j=0;j<26;++j){
				int tp=t,sum=0;
				d[0]='a'+j;
				for(int k=0;k<m2;++k){
					while(tp&&c[tp+1]!=d[k])tp=p[tp];
					if(c[tp+1]==d[k])++tp;
					if(tp==m2)sum++;
				}
				ans=(ans+1ll*sum*(qh[t2+1][j]-qh[k+1][j])%P*inv[n-k])%P;
			}
			printf("%d\n",(ans+P)%P);
		}
	}
}
	 					    	   			 	 			   		