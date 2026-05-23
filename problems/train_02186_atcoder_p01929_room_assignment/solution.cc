#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
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
#include <set>
constexpr long long int MOD = 1000000007;
constexpr int MAX_N = 100000;
long long int power(long long int base, int exp) {
	switch (exp) {
	case 0: return 1;
	case 1: return base % MOD;
	default: return power(base, exp & 1) * power(base * base % MOD, exp >> 1) % MOD;
	}
}
long long int inverse(long long int value) {
	return pow(value, MOD - 2);
}
long long int mul() {
	return 1;
}
template<typename Head, typename ...Tail> 
long long int mul(Head&& head, Tail&&... tail) {
	return head % MOD * mul(std::forward<Tail>(tail)...) % MOD;
}
int main() {
	std::vector<long long int> factorial(MAX_N + 1, 1), inv(MAX_N + 1, 1), inv_factorial(MAX_N + 1, 1);
	for (auto i = 2; i < factorial.size(); ++i) {
		factorial[i] = i * factorial[i - 1] % MOD;
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
		inv_factorial[i] = inv[i] * inv_factorial[i - 1] % MOD;
	}
	const auto comb = [factorial, inv_factorial](int n, int r) {return factorial[n] * inv_factorial[n - r] % MOD * inv_factorial[r] % MOD; };
	while (true) {
		int n; std::cin >> n; if (n == 0) break;
		std::vector<int> favor(n);
		std::vector<int> inv_count(n, 0);
		for (auto i = 0; i < n; ++i) {
			int f; std::cin >> f;
			favor[i] = f - 1;
		}
		std::vector<bool> is_pair(n, false);
		for (auto i = 0; i < n; ++i) {
			if (favor[favor[i]] == i) is_pair[i] = true;
			else ++inv_count[favor[i]];
		}
		if (std::any_of(inv_count.begin(), inv_count.end(), [](int c) {return c > 1; })) {
			std::cout << "0\n";
			continue;
		}
		std::queue<int> queue;
		for (auto i = 0; i < n; ++i) {
			if (inv_count[i] == 0) queue.push(i);
		}
		std::vector<bool> is_visit(n, false);
		while (!queue.empty()) {
			is_visit[queue.front()] = true;
			if (!is_pair[queue.front()]) queue.push(favor[queue.front()]);
			queue.pop();
		}
		if (std::any_of(is_visit.begin(), is_visit.end(), [](bool b) {return !b; })) {
			std::cout << "0\n";
			continue;
		}
		int single_pair = 0;
		int other_count = 0;
		for (auto i = 0; i < n; ++i) {
			if (is_pair[i] && i < favor[i]) {
				if (inv_count[i] + inv_count[favor[i]] == 0) {
					++single_pair;
				}
				else {
					++other_count;
				}
			}
		}
		if (other_count == 0) {
			std::cout << mul(factorial[single_pair], power(2, single_pair), single_pair / 2 + 1) << std::endl;
			continue;
		}
		long long int result = 0;
		const auto pow = power(2, single_pair + other_count);
		for (auto len = 0; len <= single_pair; ++len) {
			const auto c = mul(comb(single_pair, len), factorial[len]);
			const auto for_end = mul(c, other_count, factorial[single_pair - len + other_count - 1], pow, len / 2 + 1, 2);
			const auto for_mid = other_count > 1 ? mul(c, other_count, other_count - 1, factorial[single_pair - len + other_count - 1], pow, len / 2 + 1) : 0;
			result += for_end + for_mid;
			result %= MOD;
		}
		std::cout << result << '\n';
	}
}
