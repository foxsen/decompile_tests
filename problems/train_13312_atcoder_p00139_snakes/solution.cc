#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main(){
	int n;
	cin>>n;
	rep(i,0,n){
		string s;
		cin>>s;
		int ans=0;
		int sz=s.size();
		if(sz<6){
			ans=-1;
		}else if(s[0]=='>'&&s[1]=='\''&&s[sz-1]=='~'&&sz%2==0&&s[sz/2]=='#'){
			rep(i,2,sz-1){
				if(i!=sz/2&&s[i]!='='){
					ans=-1; break;
				}
				if(i==sz-2) ans=1;
			}
		}else if(s[0]=='>'&&s[1]=='^'&&s[sz-2]=='~'&&s[sz-1]=='~'&&sz%2==0){
			rep(i,2,sz-2){
				if(i%2==0&&s[i]!='Q'){
					ans=-1; break;
				}if(i%2&&s[i]!='='){
					ans=-1; break;
				}
				if(i==sz-3) ans=2;
			}
		}else{
			ans=-1;
		}
		if(ans==-1) o("NA");
		else if(ans==1) o("A");
		else if(ans==2) o("B");
	}	
}