#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
//#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int main(){
	while(1){
		string ans = "impossible"; int a[6];
		cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
		if(a[0]+a[1]+a[2]+a[3]+a[4]+a[5] == 0) return 0;
		do{
			int b[6]; rep(i,6) b[i] = a[i];
			string s = "";
			while(b[0]+b[1]+b[2]+b[3]+b[4]+b[5] > 0){
				if(b[2] && b[2]+b[4]-1 <= b[0]+b[1]+b[3]+b[5] && b[1]+b[3] <= b[0]+b[2]+b[4]+b[5] && b[0]+b[5] <= b[1]+b[2]+b[3]+b[4]){
					s.pb('E');
					int f = b[5]; b[5] = b[2]-1; b[2] = b[0]; b[0] = b[4]; b[4] = f;
				}
				else if(b[3] && b[3]+b[1]-1 <= b[0]+b[2]+b[4]+b[5] && b[2]+b[4] <= b[0]+b[1]+b[3]+b[5] && b[0]+b[5] <= b[1]+b[2]+b[3]+b[4]){
					s.pb('N');
					int f = b[5]; b[5] = b[3]-1; b[3] = b[0]; b[0] = b[1]; b[1] = f;
				}
				else if(b[1] && b[3]+b[1]-1 <= b[0]+b[2]+b[4]+b[5] && b[2]+b[4] <= b[0]+b[1]+b[3]+b[5] && b[0]+b[5] <= b[1]+b[2]+b[3]+b[4]){
					s.pb('S');
					int f = b[5]; b[5] = b[1]-1; b[1] = b[0]; b[0] = b[3]; b[3] = f;
				}
				else if(b[4] && b[2]+b[4]-1 <= b[0]+b[1]+b[3]+b[5] && b[1]+b[3] <= b[0]+b[2]+b[4]+b[5] && b[0]+b[5] <= b[1]+b[2]+b[3]+b[4]){
					s.pb('W');
					int f = b[5]; b[5] = b[4]-1; b[4] = b[0]; b[0] = b[2]; b[2] = f;
				}
				else{
					goto bad;
				}
				//cout << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << " " << b[4] << " " << b[5] << endl;
			}
			if(ans == "impossible") ans = s;
			else ans = min(ans,s); bad:;
		}while(next_permutation(a,a+6));
		int p,q; cin >> p >> q;
		if(ans != "impossible"){
		        for(int i=p-1;i<q;i++) printf("%c",ans[i]); puts("");
		}
		else{
			cout << ans << endl;
		}
	}
}