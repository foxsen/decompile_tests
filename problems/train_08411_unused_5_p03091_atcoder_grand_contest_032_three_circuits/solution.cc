#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

multiset<int> G[MX];
int loops = 0;

void remove(int v) {
	int a = *G[v].begin();
	int b = *G[v].rbegin();
	
	G[v].clear();
	
	G[a].erase(v);
	G[b].erase(v);
	
	if (a == b) {
		loops++;
		
		if (G[a].size() == 2) remove(a);
		if (G[b].size() == 2) remove(b);
	}
	else {
		G[a].insert(b);
		G[b].insert(a);
	}
}

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	for (int i = 0, u, v; i < m; i++) {
		ignore = scanf("%d %d", &u, &v);
		u--;
		v--;
		G[u].insert(v);
		G[v].insert(u);
	}
	
	bool bad = false;
	for (int v = 0; v < n; v++) {
		if (G[v].size() == 2) remove(v);
		if (G[v].size() % 2 == 1) bad = true;
	}
	
	int V = 0, E = 0;
	for (int v = 0; v < n; v++) {
		if (G[v].empty() == false) V++;
		E += G[v].size() / 2;
	}
	
	bool ok = (E / 2 + loops >= 3);
	
	printf("%s\n", ok && (bad == false) ? "Yes" : "No");
	
	return 0;
}

/*
5 7
1 2
1 3
2 3
2 4
2 5
3 4
3 5
No

7 9
1 3
3 4
4 1
1 2
2 5
5 1
2 6
6 7
7 2
Yes
*/
