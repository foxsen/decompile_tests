#include <bits/stdc++.h>
using namespace std;

string dp2[310][310];
int dp[310][310];

int main()
{
	string s;
	while (cin >> s){
		if (s == "#END")return 0;
		int res = 0, id = 0;
		for (int k = 1; k < s.length(); ++k){
			string s1 = s.substr(0, k);//从头到k的子序列
			string s2 = s.substr(k);//从k往后的子序列
			memset(dp, 0, sizeof dp);
			for (int i = 0; i < s1.length(); ++i){
				for (int j = 0; j < s2.length(); ++j){
					if (s1[i] == s2[j])dp[i + 1][j + 1] = dp[i][j] + 1;
					else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
				}
			}
			if (res < dp[s1.length()][s2.length()]){
				res = dp[s1.length()][s2.length()];
				id = k;
			}
		}
		//从id处分隔字符串
		string s1 = s.substr(0, id);
		string s2 = s.substr(id);
		for (int i = 0; i <= s1.length(); ++i){
			for (int j = 0; j <= s2.length(); ++j)dp2[i][j] = "";
		}
		for (int i = 0; i < s1.length(); ++i){
			for (int j = 0; j < s2.length(); ++j){
				if (s1[i] == s2[j])dp2[i + 1][j + 1] = dp2[i][j] + s1[i];
				else{
					if (dp2[i][j + 1].size() <= dp2[i + 1][j].size())dp2[i + 1][j + 1] = dp2[i + 1][j];
					if (dp2[i][j + 1].size() > dp2[i + 1][j].size())dp2[i + 1][j + 1] = dp2[i][j + 1];
				}
			}
		}
		cout << dp2[s1.size()][s2.size()] << endl;
	}
	return 0;
}
