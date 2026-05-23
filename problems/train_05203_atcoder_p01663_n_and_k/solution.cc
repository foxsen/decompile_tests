#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>
#include <bitset>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cassert>
#include <random>

struct Range {
	long long int from, to;
};
long long int power(long long int base, int exp) {
	switch (exp) {
	case 0: return 1LL;
	case 1: return base;
	default: return power(base * base, exp / 2) * power(base, exp % 2);
	}
}
long long int k_th_element(const long long int N, const long long int K) {
	if (K > (N + 1) / 2) return -1;
	std::vector<Range> result;
	for (long long int exp = 1; exp <= N; exp *= 3) {
		result.push_back(Range{ N / exp / 3 + 1, N / exp });
	}
	for (auto& r : result) {
		if (r.from % 2 == 0) ++r.from;
		if (r.to % 2 == 0) --r.to;
	}
	long long int min = 1LL, max = N;
	while (min < max) {
		auto mid = (min + max) / 2;
		long long int count = 0, exp = 1;
		for (auto i = 0; i < result.size(); ++i) {
			if (mid >= result[i].from * exp) {
				count += (std::min(result[i].to, mid / exp) - result[i].from) / 2 + 1;
			}
			exp *= 2;
		}
		if (count < K) min = mid + 1;
		else max = mid;
	}
	return max;
}
int main() {
	int c; std::cin >> c;
	for (auto i = 0; i < c; ++i) {
		long long int n, k; std::cin >> n >> k;
		std::cout << k_th_element(n, k) << '\n';
	}
}
