#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
typedef pair<int,int> P;
int N,M;
char c[26];
int h[26],w[26];
int flipto[26];
string bs[26][15];
vector<P> g[52];
int mxh;
int H,W;
string s[100];
bool isbox(int x,int y){
	int t=x;
	while(t<H&&s[t][y]=='*') t++;
	return t-x>mxh;
}
string seq(int u,int l,int d,int r){
	vector<string> ret;
	bool flip=0;
	int y=l,x=u;
	while(y<r){
		if(s[x][y]=='*'){
			if(isbox(x,y)){
				int nu=x+1,nl=y+1;
				int nd=nu,nr=nl;
				while(nd<H&&s[nd][y]=='*') nd++;
				while(nr<W&&s[x][nr]=='*') nr++;
				nd--,nr--;
				ret.pb(seq(nu,nl,nd,nr));
				x=u,y=nr+1;
				continue;
			}else{
				vector<P> vc;
				int L=y,U=1e5;
				for(;y<r;y++){
					bool iscol=0;
					for(x=u;x<d;x++){
						if(s[x][y]=='*') vc.pb(P(x,y)),iscol=1,chmin(U,x);
					}
					if(!iscol) break;
				}
				for(P& p:vc) p=P(p.fs-U,p.sc-L);
				sort(all(vc));
				rep(i,2*N){
					if(vc==g[i]){
						ret.pb(string(1,c[i%N]));
						if(i>=N) flip=1;
						break;
					}
				}
				x=u;
				continue;
			}
		}
		x++;
		if(x==d){
			y++;
			x=u;
		}
	}
	if(flip){
		reverse(all(ret));
		for(string& str:ret) if(str.size()==1){
			int tmp=flipto[str[0]-'a'];
			if(tmp>=0) str[0]=tmp+'a';
		}
	}
	string st="[";
	for(string str:ret) st+=str;
	st+="]";
	return st;
}
int main(){
	while(true){
		cin>>N>>M;
		if(N==0) break;
		rep(i,N*2) g[i].clear();
		mxh=0;
		rep(i,N){
			cin>>c[i]>>h[i]>>w[i];
			chmax(mxh,h[i]);
			rep(j,h[i]) cin>>bs[i][j];
			rep(j,h[i]) rep(k,w[i]) if(bs[i][j][k]=='*') g[i].pb(P(j,k)),g[i+N].pb(P(j,w[i]-1-k));
		}
		rep(i,2*N) sort(all(g[i]));
		rep(i,N) flipto[i]=-1;
		rep(i,N) rep(j,N) if(g[i+N]==g[j]) flipto[c[i]-'a']=c[j]-'a';
		rep(tt,M){
			cin>>H>>W;
			rep(i,H) cin>>s[i];
			string ans=seq(0,0,H,W);
			cout<<ans.substr(1,ans.size()-2)<<endl;
		}
		puts("#");
	}
}