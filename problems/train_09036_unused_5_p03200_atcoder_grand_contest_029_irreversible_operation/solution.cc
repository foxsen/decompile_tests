#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	long long ans = 0;
	long long ctr = 0;

	for(int i = 0; i < s.size(); i++){
		if (s[i] == 'W') {
			ans += ctr;
		} 
		else ctr++;
	}
	cout<<ans<<endl;
	return 0;
}