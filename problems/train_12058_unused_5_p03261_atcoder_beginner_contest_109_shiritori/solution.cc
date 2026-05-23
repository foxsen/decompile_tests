#include <bits/stdc++.h>
using namespace std;
int n;
string w;
set<string>ss;
int main(){
	cin>>n;
	char c;
	for(int i=0;i<n;i++){
		cin>>w;
		if(ss.count(w)==0){
			if(i!=0&&c!=w[0]){
				cout<<"No";
				return 0;
			}
			c=w[w.size()-1];
			ss.insert(w);
		}
		else{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
