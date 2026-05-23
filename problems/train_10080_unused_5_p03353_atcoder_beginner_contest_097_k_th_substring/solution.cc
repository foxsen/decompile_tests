#include <iostream>
#include <set>
using namespace std;
int main(void) {
	string s;
	int k;
	cin >> s >> k;
	set<string> st;
	for (int i = 0; i < s.size(); ++i) {
		string subs;
		for (int j = i; j < s.size(); ++j) {
			subs += s[j];
			if (subs.size() > k) break;
			st.insert(subs);
		}
	}
	int cnt = 0;
	for (auto x : st) {
		++cnt;
		if (cnt == k) {
			cout << x << endl;
			break;
		}
	}
	return 0;
}