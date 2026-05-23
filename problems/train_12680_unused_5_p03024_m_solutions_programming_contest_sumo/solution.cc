#include<bits/stdc++.h>
using namespace std;

string s;
int sum=0;

int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='x') sum++;
	}
	
	if(sum<=7) cout<<"YES";
	else cout<<"NO";
	return 0;
}