#include "bits/stdc++.h"

using namespace std;

inline int comp(string& s, string &t)
{
	if (s.size() < t.size()) return 1;
	if (s.size() > t.size()) return 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] < t[i]) return 1;
		if (s[i] > t[i]) return 0;
	}
	return 0;
}

void solve(void)
{
	int w, h;
	while(cin >> w >> h)
	{
		if (!w && !h) break;
		vector<string> g(h), dp(w);
		for (string& s : g) cin >> s;
		string ans = "";
		for (int i = 0; i < h; i++)
		{
			vector<string> nx(w);
			for (int j = 0; j < w; j++)
			{
				if ('0' > g[i][j] || '9' < g[i][j])
					continue;
				string s = "", t = "";
				if (i)
					s = dp[j];
				if (j)
					t = nx[j - 1];
				if (s.empty() && t.empty() && g[i][j] == '0') continue;
				nx[j] = (comp(s, t) ? t : s) + g[i][j];
				if (comp(ans, nx[j]))
					ans = nx[j];
			}
			swap(dp, nx);
		}
		bool f = 1;
		for (char c : ans)
		{
			if (c == '0' && f) continue;
			cout << c;
			f = 0;
		}
		if (f) cout << 0;
		cout << '\n';
	}
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}


