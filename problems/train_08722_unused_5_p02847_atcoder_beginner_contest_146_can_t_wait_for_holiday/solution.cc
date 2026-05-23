#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<string> w={"SUN","MON","TUE","WED","THU","FRI","SAT"};
	for(int i=0; i<7; i++){
		if(w[i]==s){
			cout << 7-i <<endl; return 0;
		}
	}
	return 0;
}