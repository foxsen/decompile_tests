#include<iostream>
#include<string>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	bool tmp=false;
	for(int i=s.size()-t.size();i>=0;i--){
		bool check=true;
		rep(j,t.size()){
			if(s[i+j]=='?' or s[i+j]==t[j])continue;
			check=false;
			break;
		}
		if(check && !tmp){
			rep(j,t.size())s[i+j]=t[j];
			tmp=true;
		}
	}
	rep(i,s.size())if(s[i]=='?')s[i]='a';
	cout<<((tmp)?s:"UNRESTORABLE")<<endl;
	return 0;
}