#include <bits/stdc++.h>
using namespace std;
int main(){
	string res;
	for(int i=0;i<3;++i){
		string s;
		cin >> s;
		res+=s[0]-32;
	}
	cout << res;
	return 0;
}