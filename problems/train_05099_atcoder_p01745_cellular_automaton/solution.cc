#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll d[256];

bool bellman_ford(int n, vector<edge>& E, int s, ll d[]) {
	fill(d, d + n, LLONG_MAX); d[s] = 0;
	for (int i = 0; i < n; i++) {
		bool updated = false;
		for (int j = 0; j < E.size(); j++) {
			edge e = E[j];
			if (d[e.u] < LLONG_MAX && d[e.v] > d[e.u] + e.w) {
				d[e.v] = d[e.u] + e.w;
				updated = true;
			}
		}
		if (!updated) return true;
	}
	return false;
}

string check(int N, string s) {
	vector<edge> E;
	for (int u = 0; u < N; u++) {
		E.push_back(edge{u, N + u, 0});
		E.push_back(edge{N + u, u, 1});
		int v;
		v = u * 2 % N;
		E.push_back(edge{N + u, v, 0});
		E.push_back(edge{v, N + u, 0});
		v = (u * 2 + 1) % N;
		E.push_back(edge{N + u, v, 1});
		E.push_back(edge{v, N + u, -1});
	}
	for (int u = 0; u < N; u++) {
		if (s[u] == '0')
			E.push_back(edge{N + u, u, 0});
		if (s[u] == '1')
			E.push_back(edge{u, N + u, -1});
	}
	if (!bellman_ford(N * 2, E, 0, d)) return "";
	string t(N, ' ');
	for (int u = 0; u < N; u++)
		if (d[u] == d[N + u]) t[u] = '0';
		else t[u] = '1';
	return t;
}

int main() {
	int w; cin >> w;
	string s; cin >> s;
	int N = s.length();
	string t = check(N, s);
	if (t != "") {
		cout << t << endl;
		return 0;
	}
	for (int i = N - 1; i >= 0; i--) {
		if (s[i] == '0') {
			s[i] = '1';
			string t = check(N, s);
			if (t != "") {
				cout << t << endl;
				return 0;
			}
		}
		s[i] = '?';
	}
	cout << "no" << endl;
}