#include<cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	for(int cas=1,n,m;scanf("%d%d",&n,&m),n;cas++){
		int t=0;
		int win[21]={n};
		while(win[m]==0){
			int next[21]={};
			rep(i,m){
				next[i+1]+=win[i]/2;
				next[ 0 ]+=win[i]/2;
				next[ i ]+=win[i]%2;
			}
			rep(i,m+1) win[i]=next[i];
			t++;
		}
		printf("Case %d: %d\n",cas,t);
	}

	return 0;
}