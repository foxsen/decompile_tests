#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define ALL(v) v.begin(),v.end()

bool f(char c){
	return c=='a'||c=='i'||c=='u'||c=='e'||c=='o';
}

int main() {
	int n;
	while(cin>>n,n){
		vector<string> v(n);
		REP(i,n)cin>>v[i];
		for(int k=1;k<=50;++k){
			vector<string> code(n);
			REP(i,n){
				code[i]+=v[i][0];
				for(int j=1;j<v[i].size();++j){
					if(f(v[i][j-1]))code[i]+=v[i][j];
				}
				if(code[i].size()>=k)code[i]=code[i].substr(0,k);
			}
			
			set<string> s;
			REP(i,n)s.insert(code[i]);
			if(s.size()==n){
				cout<<k<<endl;
				goto next;
			}
		}	
		cout<<-1<<endl;
		next:;
	}
	
}
