#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;

#define INF INT_MAX/3

#define MAX_N 1000

#define M 1000000007

ll mem[55][2];

int n;
string a,b,c;

ll dfs(int digit,int carry){
	if(digit==-1)return (carry==1?0:1);
	if(mem[digit][carry]!=-1)return mem[digit][carry];
	ll res=0;

	rep(an,10){
		if(a[digit]!='?'&&a[digit]-'0'!=an)continue;
		if(digit==0&&an==0)continue;
		rep(bn,10){
			if(b[digit]!='?'&&b[digit]-'0'!=bn)continue;
			if(digit==0&&bn==0)continue;
			rep(cn,10){
				if(c[digit]!='?'&&c[digit]-'0'!=cn)continue;
				if(digit==0&&cn==0)continue;
				if((an+bn+carry)%10==cn)res=(res+dfs(digit-1,(an+bn+carry)/10))%M;
			}
		}
	}
	return mem[digit][carry]=res;
}

int main(){
	cin.sync_with_stdio(false);
	while(1){
		cin>>a;
		if(a[0]=='0')break;
		cin>>b>>c;
		n=a.length();
		memset(mem,-1,sizeof(mem));
		cout<<dfs(n-1,0)<<endl;
	}
	return 0;
}