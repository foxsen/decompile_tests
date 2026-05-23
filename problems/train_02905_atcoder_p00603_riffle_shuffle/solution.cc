#include<iostream>
#include<queue>
using namespace std;
queue<int>Q[3]; int p, q;
void solve(int a) {
	for (int i = 0; i < 1000; i++) {
		if (Q[i % 2].size() < a) {
			while (!Q[i % 2].empty()) { Q[2].push(Q[i % 2].front()); Q[i % 2].pop(); }
		}
		else {
			for (int j = 0; j < a;j++){ Q[2].push(Q[i % 2].front()); Q[i % 2].pop(); }
		}
	}
}
int main() {
	while (cin >> p >> q) {
		for (int i = 0; i < p / 2; i++)Q[1].push(i);
		for (int i = p / 2; i < p; i++)Q[0].push(i);
		for (int i = 0; i < q; i++) {
			if (i >= 1) {
				int V = Q[2].size();
				for (int j = 0; j < V / 2; j++) { Q[1].push(Q[2].front()); Q[2].pop(); }
				for (int j = V / 2; j < V; j++) { Q[0].push(Q[2].front()); Q[2].pop(); }
			}
			int a; cin >> a; solve(a);
		}
		while (Q[2].size() >= 2)Q[2].pop();
		cout << Q[2].front() << endl; Q[2].pop();
	}
	return 0;
}