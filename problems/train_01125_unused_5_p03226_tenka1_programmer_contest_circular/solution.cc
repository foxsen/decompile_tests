#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
int N;
const int MAX_N=3e5;
const ll MOD=998244353;
typedef pair<int,int> P;
vector<P> org;
int psm[MAX_N+1];
int main(){
	cin>>N;
	REP(i,N){
		int a;
		cin>>a;
		if (i==0 || org.back().first!=a){
			org.push_back(P(a,1));
		}else{
			org.back().second++;
		}
	}
	ll ans=1;
	if (org[0].second==N){
		if (org[0].first!=1){
			ans=0;
		}else{
			ans=1;
		}
		REP(i,N){
			ans*=(i+1);
			ans%=MOD;
		}
	}else{
		if (org[0].first==org.back().first){
			org[0].second+=org.back().second;
			org.pop_back();
		}
		{
			set<int> st;
			for(auto p:org){
				if (st.find(p.first)!=st.end()){
					ans=0;
					goto BREAK;
				}
				st.insert(p.first);
			}
		}
		REP(i,(int)org.size()){
			psm[i+1]=psm[i]+org[i].second;
		}
		map<int,int> mp;
		{
			int cnt=0;
			for(auto p:org){
				mp[p.first]=cnt++;
			}
		}
		map<int,int> inx;
		int cap=0,len;
		if (mp.find(1)!=mp.end()){
			inx[psm[mp[1]]]=1;
			len=org[mp[1]].second;
		}else{
			ans=0;
			len=0;
			goto BREAK;
		}
		FOR(i,2,N+1){
			if (mp.find(i)==mp.end()){
				ans*=cap;
				ans%=MOD;
				cap--;
			}else{
				int j=mp[i];
				if (!(0<=j && j<(int)org.size())){
					return 0;
				}
				if (org[j].second>len){
					ans=0;
					goto BREAK;
				}
				int prej;
				if (j>0){
					prej=j-1;
				}else{
					prej=(int)org.size()-1;
				}
				int nexj;
				if (j<(int)org.size()-1){
					nexj=j+1;
				}else{
					nexj=0;
				}
				if (!(0<=prej && prej<(int)org.size())){
					return 0;
				}
				if (!(0<=nexj && nexj<(int)org.size())){
					return 0;
				}
				int iinx;
				if (org[prej].first<i && org[nexj].first<i){
					iinx=psm[j];
					ans*=len-org[j].second+1;
					ans%=MOD;
				}else if(org[prej].first<i){
					iinx=psm[j]-(len-org[j].second);
				}else if (org[nexj].first<i){
					iinx=psm[j];
				}else{
					iinx=psm[j];
					if (org[j].second!=len){
						ans=0;
						goto BREAK;
					}
				}
				int gap;
				map<int,int>::iterator low,upp;
				upp=inx.upper_bound(iinx);
				if (upp==inx.end()){
					upp=inx.begin();
					gap=N-iinx-1+upp->first;
				}else{
					gap=upp->first-iinx-1;
				}
				if (gap<len){
					cap+=gap;
				}
				low=upp;
				if (upp==inx.begin()){
					low=inx.end();
				}
				low--;
				if (low->first<iinx){
					gap=iinx-low->first-1;
				}else{
					gap=iinx+N-low->first-1;
				}
				if (gap<len){
					cap+=gap;
				}
				inx[iinx]=i;
			}
		}
	}
	BREAK:
	cout<<ans<<endl;				
	return 0;
}