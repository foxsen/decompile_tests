#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n;
long long a[55][55],A[55][55],tmp[55][55];
long long k;

void copy(long long x[][55],long long y[][55]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			x[i][j]=y[i][j];
		}
	}
}

void mul(long long x[][55],long long y[][55],long long z[][55]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				x[i][j]+=y[i][k]*z[k][j];
				x[i][j]%=mod;
			}
		}
	}
}

void ksm(long long x){
	x--;
	copy(A,a);
	while(x){
		if(x&1){
			memset(tmp,0,sizeof(tmp));
			mul(tmp,A,a);
			copy(A,tmp);
		}
		memset(tmp,0,sizeof(tmp));
		mul(tmp,a,a);
		copy(a,tmp);
		x/=2;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans+=A[i][j];
			ans%=mod;
		}
	}
	printf("%lld\n",ans);
}

int main(){
	cin>>n;
	cin>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	ksm(k);

	return 0;
}