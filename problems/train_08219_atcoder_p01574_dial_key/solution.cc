#include<cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

int main(){
	int n,m; scanf("%d%d",&n,&m);
	rep(i,m){
		int l; scanf("%d",&l);
		n=gcd(n,l);
	}
	puts(n==1?"Yes":"No");

	return 0;
}