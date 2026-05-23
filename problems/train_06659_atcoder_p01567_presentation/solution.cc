#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
using vi=vector<int>;
#define PB push_back
#define ALL(x) x.begin(),x.end()
	
const int Nmax=415514;
const int inf=1145141919;
char tree[Nmax],buf[Nmax];
int sub[Nmax],idx;
int dfs1(char*&p){
	if(*++p==')')return 0;
	int v=idx++,res=1;
	REP(_,2){
		res+=dfs1(p);
		p++;
	}
	return sub[v]=res;
}
bool check(int&i,char c){
	if(buf[i]=='?')buf[i]=c;
	else if(buf[i]!=c)return false;
	i++;
	return true;
}
bool dfs2(char*&p,int w,int*i){
	if(*++p==')')return true;
	int v=idx++,tmp=0;
	if(sub[v]%w==0)i=&tmp;
	REP(_,2){
		if(!check(*i,*p))return false;
		if(!dfs2(p,w,i))return false;
		if(!check(*i,*p))return false;
		p++;
	}
	return true;
}

int main(){
	scanf("%s",tree);
	char* beg=tree;
	dfs1(beg);
	int n=sub[0];
	vi canUse;
	FOR(i,1,n+1)if(n%i==0){
		beg=tree;
		REP(j,4*i)buf[j]='?';
		idx=0;
		if(dfs2(beg,i,0))
			canUse.PB(i);
	}
	vi dp(canUse.size(),inf);
	dp[0]=0;
	REP(i,dp.size())FOR(j,i+1,dp.size())if(canUse[j]%canUse[i]==0)
		dp[j]=min(dp[j],dp[i]+canUse[j]/canUse[i]-1);
	cout<<dp.back()<<endl;
}