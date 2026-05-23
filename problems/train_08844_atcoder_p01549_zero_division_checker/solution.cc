#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>

using namespace std;

#define rep(i,n) for(int i = 0;i < n;i++)
#define each(i,n) for(auto i : n)

int main() {
	int m;
	cin >> m;
	vector<string> c(m);
	vector<int> l(m), r(m);
	map<string, int> p;
	p["+"] = -1;
	p["-"] = -1;
	p["*"] = -1;
	p["/"] = -1;
	rep(i, m) {
		cin >> c[i] >> l[i] >> r[i];
		p[c[i]] = i;
	}
	vector<vector<int>> d(m);
	rep(i, m) {
		for (int j = l[i]; j <= r[i]; j++) {
			d[i].push_back(j);
		}
	}
	int n;
	cin >> n;
	vector<int> v;
	stack<vector<int>> s;
	rep(k, n) {
		string t;
		cin >> t;
		if (p.count(t)) {
			if (p[t] == -1) {
				auto b = s.top();
				s.pop();
				auto a = s.top();
				s.pop();
				set<int> se;
				each(i, b)each(j, a) {
					if (t == "+") {
						se.insert((j + i) % 256);
					}
					if (t == "-") {
						se.insert((j - i + 256) % 256);
					}
					if (t == "*") {
						se.insert((j * i) % 256);
					}
					if (t == "/") {
						if (i == 0) {
							cout << "error" << endl;
							return 0;
						}
						se.insert((j / i) % 256);
					}
				}
				vector<int> v;
				each(i, se) {
					v.push_back(i);
				}
				s.push(v);
			}
			else {
				s.push(d[p[t]]);
			}
		}
		else {
			s.push(vector<int>(1, atoi(t.c_str())));
		}
	}
	cout << "correct" << endl;

	return 0;
}