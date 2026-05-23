#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
const int MOD=1000000007;

int t[200000],a[200000];
ll s[8][200000];

int main(){
	int n;cin>>n;
	vector<int>xs;
	rep(i,n){
		scanf("%d%d",&t[i],&a[i]);
		rep(j,8){
			s[j][i+1]=s[j][i];
			if(j==a[i])s[j][i+1]++;
		}
		xs.push_back(t[i]);
	}
	int q;cin>>q;
	rep(i,q){
		int l,r;scanf("%d%d",&l,&r);
		int R=lower_bound(xs.begin(),xs.end(),r)-xs.begin();
		int L=lower_bound(xs.begin(),xs.end(),l)-xs.begin();
		double ans=1e9;
		rep(j,8){
			int cnt=s[j][R]-s[j][L];
			ans*=pow((10-j)/10.,cnt);
		}
		printf("%.12lf\n",ans);
	}
}
