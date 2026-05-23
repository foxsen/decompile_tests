#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

const int MAX_LEN=2e5,INF=1e6;
string A;

char dp[MAX_LEN+1];
int dp2[MAX_LEN+1];
map<char,int> mp[MAX_LEN+1];

int main(){
	cin>>A;
	A.insert(A.begin(),'$');
	dp[A.size()-1]='a';
	dp2[A.size()-1]=1;
	map<char,int> m;
	for(int i=A.size()-1;i>=0;i--){
		mp[i]=m;
		m[A[i]]=i;
	}
	for(int i=A.size()-2;i>=0;i--){
		dp2[i]=INF;	
		REP(j,'z'-'a'+1){
			if (mp[i].find(j+'a')!=mp[i].end()){	
				if (dp2[i]>dp2[mp[i][j+'a']]+1){
					dp2[i]=dp2[mp[i][j+'a']]+1;
					dp[i]=j+'a';
				}
			}else if (dp2[i]>1){
				dp2[i]=1;
				dp[i]=j+'a';
			}
		}
	}
	char c=dp[0];
	int inx=0;
	do{
		cout<<c;
		if (mp[inx].find(c)==mp[inx].end()){
			break;
		}else{
			inx=mp[inx][c];
			c=dp[inx];
		}
	}while(1);
	cout<<endl;
	return 0;
}