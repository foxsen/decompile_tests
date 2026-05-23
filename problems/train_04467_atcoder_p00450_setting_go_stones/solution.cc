#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n, n) {
		vector<int> st(1, 0);
		int c, ch;
		cin >> c;
		for (int i = 1; i < n; i++) {
			cin >> ch;
			if (c != ch) {
				if (i % 2 == 1) {
					if ((int)st.size() >= 2) {
						st.pop_back();
					}
				}
				else {
					st.push_back(i);
				}
				c = ch;
			}
		}
		st.push_back(n);
		int res = 0;
		while (st.size() >= 2) {
			if (c == 0) {
				res += st[st.size() - 1] - st[st.size() - 2];
			}
			c = 1 - c;
			st.pop_back();
		}
		cout << res << endl;
	}
	return 0;
}

