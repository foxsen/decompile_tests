
#if 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <list>

auto& in = std::cin;
auto& out = std::cout;
#define all_range(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

int32_t N,M;
int32_t step[3];

std::bitset<50> win;
std::bitset<101> passed[50];
std::vector<int32_t> graph[50];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N>>M>> step [0]>> step[1] >> step[2];

	for (int32_t i = 0; i < M; i++)
	{
		int a, b;
		in >> a >> b;
		--a; --b;
		graph[b].push_back(a);
	}

	
	win[N - 1] = true;
	for (size_t COUNTCOUNTCOUNT = 0; COUNTCOUNTCOUNT < 50; COUNTCOUNTCOUNT++)
	{
		std::queue<std::pair<int32_t, int32_t>> que;
		for (size_t i = 0; i < N; i++)
		{
			if (win[i] && !passed[i][0]) {
				que.emplace(i, 0);
				passed[i][0] = true;
			}
		}

		while (!que.empty())
		{
			auto v = que.front(); que.pop();

			if (passed[v.first][step[0]] && passed[v.first][step[1]] && passed[v.first][step[2]]) {
				win[v.first] = true;
			}

			if (v.second < 100) {
				for (auto& i : graph[v.first])
				{
					if (!passed[i][v.second + 1])
					{
						que.emplace(i, v.second + 1);
						passed[i][v.second + 1] = true;
					}
				}
			}
		}
		if (win[0]) {
			out << COUNTCOUNTCOUNT+1 << endl;
			return 0;
		}
	}

	
	out << "IMPOSSIBLE" << endl;
	return 0;
}
#endif

