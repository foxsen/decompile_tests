#include<bits/stdc++.h>


int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	std::map<int, int> map;
	std::vector<int> vec;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		map[a]++;
	}
	for (auto p : map) {
		vec.push_back(p.second);
	}
	std::sort(vec.begin(), vec.end());
	int ans = 0;
	n = map.size();
	for (int i = 0; i < n - k; i++) {
		ans += vec[i];
	}
	printf("%d", ans);
}