#include <bits/stdc++.h>
using namespace std;
string s; int c[100009];
int main() {
	cin >> s;
	int depth = 0; c[0] = 1;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') depth++;
		if(s[i] == ')') depth--;
		c[depth]++;
	}
	long long ret = 0;
	for(int i = 0; i <= s.size(); i++) {
		ret += 1LL * c[i] * (c[i] - 1) / 2;
	}
	cout << ret - 1 << endl;
	return 0;
}