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


class SqrtSegment {
public:
	std::vector<long long int> a_value, b_value, min_a, min_b;
	std::vector<int> sorted_by_diff;
	int from, until;
	long long int add_all;
	void recalculate() {
		std::sort(sorted_by_diff.begin(), sorted_by_diff.end(), [this](int a, int b) {return b_value[a] - a_value[a] < b_value[b] - a_value[b]; });
		std::transform(sorted_by_diff.begin(), sorted_by_diff.end(), min_a.begin(), [this](int i) {return a_value[i]; });
		std::transform(sorted_by_diff.begin(), sorted_by_diff.end(), min_b.begin(), [this](int i) {return b_value[i]; });
		for (auto i = 1; i < min_a.size(); ++i) {
			min_a[i] = std::min(min_a[i], min_a[i - 1]);
			min_b[min_b.size() - i - 1] = std::min(min_b[min_b.size() - i - 1], min_b[min_b.size() - i]);
		}
	}
	long long int min_all() const {
		auto separator = std::distance(sorted_by_diff.begin(), std::upper_bound(sorted_by_diff.begin(), sorted_by_diff.end(), add_all, [this](long long int added, int i) {return a_value[i] + added <= b_value[i]; }));
		long long int min = LLONG_MAX;
		if (separator > 0) {
			min = std::min(min, min_a[separator - 1] + add_all);
		}
		if (separator < min_b.size()) {
			min = std::min(min, min_b[separator]);
		}
		return min;

	}
	SqrtSegment(int _from, int _until, const std::vector<int>& a, const std::vector<int>& b) : from{ _from }, until{ _until }, add_all{ 0LL }, sorted_by_diff(_until - _from), a_value(_until - _from), b_value(_until - _from), min_a(_until - _from), min_b(_until - _from){
		std::iota(sorted_by_diff.begin(), sorted_by_diff.end(), 0);
		for (auto i = from; i < until; ++i) {
			a_value[i - from] = a[i];
			b_value[i - from] = b[i];
		}
		recalculate();
	}
	void add(int left, int right, int x) {
		if (right < from || until <= left) return;
		if (left <= from && until <= right + 1) {
			add_all += x;
			return;
		}
		for (auto i = std::max(0, left - from); i + from <= right && i < a_value.size(); ++i) {
			a_value[i] += x;
		}
		recalculate();
	}
	bool has_intersection(int left, int right) const {
		return !(right < from || until <= left);
	}
	long long int min(int left, int right) const {
		if (right < from || until <= left) return LLONG_MAX;
		if (left <= from && until <= right + 1) {
			return min_all();
		}
		long long int result = LLONG_MAX;
		for (auto i = std::max(0, left - from); i + from <= right && i < a_value.size(); ++i) {
			result = std::min(result, std::max(a_value[i] + add_all, b_value[i]));
		}
		return result;
	}
};
int main() {
	int n, q; std::cin >> n >> q;
	std::vector<int> a_value(n), b_value(n);
	for (auto i = 0; i < n; ++i) {
		int a, b; std::cin >> a >> b;
		a_value[i] = a;
		b_value[i] = b;
	}
	const int sub_size = std::sqrt(n);
	std::vector<SqrtSegment> segments;
	for (auto i = 0; i < n; i += sub_size) {
		segments.emplace_back(i, std::min(n, i + sub_size), a_value, b_value);
	}
	for (auto i = 0; i < q; ++i) {
		int type; std::cin >> type;
		if (type == 1) {
			int left, right, x; std::cin >> left >> right >> x; --left; --right;
			for (auto i = 0; i < segments.size(); ++i) {
				segments[i].add(left, right, x);
			}
		}
		else {
			long long int min = LLONG_MAX;
			int left, right; std::cin >> left >> right; --left; --right;
			for (auto i = 0; i < segments.size(); ++i) {
				min = std::min(min, segments[i].min(left, right));
			}
			std::cout << min << '\n';
		}
	}
}

