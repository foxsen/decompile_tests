#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<(S)<<endl
#define ck(a,b) (0<=(a)&&(a)<b)
using namespace std;

string abcgene(string anss){
	queue<string> q;
	q.push(anss);
	string c[3]={"A","B","C"};
	map<string,bool> m;
	m[anss]=true;
	while(!q.empty()){
		string s=q.front();
		q.pop();
		if(s=="ABC") return "Yes";
		REP(j,0,3){
			string tmps=s;
			int cnt=0;
			REP(i,0,(int) tmps.size()-2){
				if(tmps[i]=='A'&&tmps[i+1]=='B'&&tmps[i+2]=='C'){
					tmps.replace(i,3,c[j]);
					cnt++;
				}
			}
			if(cnt != count(tmps.begin(),tmps.end(),'A'+j)) continue;
			if(!m[tmps]) {
				m[tmps]=true;
				q.push(tmps);
			}
		}
	}
	return "No";
}

int main(){
	string ans;
	cin>>ans;
	p(abcgene(ans));
	return 0;
}