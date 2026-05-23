#include <iostream>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define REP1(i,n) for(int i=1;i<=n;++i)
#define ALL(c) (c).begin(),(c).end()
int a[50][50],b[50][50],c[50][50];
int main(){
	int ha,wa,hc,wc;
	cin >> ha >> wa;
	rep(i,ha) rep(j,wa) cin >> a[i][j];
	rep(i,ha) rep(j,wa) cin >> b[i][j];
	cin >> hc >> wc;
	rep(i,hc) rep(j,wc) cin >> c[i][j];
	int ans=-1000000000;
	rep(i,ha-hc+1) rep(j,wa-wc+1){
		int tmp=0;
		bool flag=true;
		rep(k,hc){
			rep(l,wc){
				if(c[k][l]!=b[i+k][j+l]){
					flag=false;
					break;
				}
				tmp+=a[i+k][j+l];
			}
			if(!flag) break;
		}
		if(flag) ans=max(ans,tmp);
	}
	if(ans==-1000000000) cout << "NA" << endl;
	else cout << ans << endl;
	return 0;
}
