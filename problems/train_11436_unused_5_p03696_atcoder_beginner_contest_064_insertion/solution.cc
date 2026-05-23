#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n>>s;
	deque<char>ret;
	int b = 0;
	for(int i=0; s[i]; i++){
		if(s[i]=='(') b++;
		else b--;
		ret.push_back(s[i]);
		if(b<0){
			b*=-1;
			for(int j=0; j<b; j++) ret.push_front('(');
			b = 0;
		}
	}
	while(b--) ret.push_back(')');
	while(ret.size()){
		cout<<ret.front();
		ret.pop_front();
	}
}