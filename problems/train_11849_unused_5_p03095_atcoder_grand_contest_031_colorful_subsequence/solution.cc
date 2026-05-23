#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n; string s; cin >> n >> s;
	map<char, int> mp; for(auto i : s)mp[i]++;

	ll res = 1;
	for(auto i : mp) {
		res *= (1 + i.second);
		res %= mod;
	}
	cout << ((res - 1) + mod ) % mod<< endl;
}	