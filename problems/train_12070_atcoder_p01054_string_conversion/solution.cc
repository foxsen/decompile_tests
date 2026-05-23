#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;

int sc[26], tc[26];

int main() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	for (char c: s) {
		sc[c-'a']++;
	}
	for (char c: t) {
		tc[c-'a']++;
	}

	sort(sc, sc+26);
	sort(tc, tc+26);

	int sm = 0;
	for (int i = 0; i < 26; i++) {
		sm += min(sc[i], tc[i]);
	}
	cout << n - sm << endl;
    return 0;
}