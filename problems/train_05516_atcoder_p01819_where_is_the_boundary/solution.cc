#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <climits>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>
#include <iostream>
#include <deque>
#include <array>
#include <set>
#include <functional>
#include <memory>
#include <stack>


int main() {
	int n, m; std::cin >> n >> m;
	std::vector<std::string> state(m);
	for (auto& line : state) std::cin >> line;
	std::vector<int> west_count(n, 0);
	std::vector<int> east_count(n, 0);
	auto all_west = 0;
	auto all_east = 0;
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < m; ++j) {
			if (state[j][i] == 'W') {
				west_count[i]++;
			}
			else {
				east_count[i]++;
			}
		}
		all_west += west_count[i];
		all_east += east_count[i];
	}
	int min = all_west;
	int pos = 0;
	int left_east = 0;
	int right_west = all_west;
	for (auto i = 0; i < n; ++i) {
		left_east += east_count[i];
		right_west -= west_count[i];
		if (left_east + right_west < min) {
			min = left_east + right_west;
			pos = i + 1;
		}
	}
	std::cout << pos << ' ' << pos + 1 << std::endl;
}
