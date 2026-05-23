#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

constexpr lint INF = 1LL << 60;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<lint, lint>> ps(n);
    for (auto& p : ps) std::cin >> p.first >> p.second;
    std::sort(ps.begin(), ps.end());

    lint ans = 0, min = INF, vsum = 0;
    for (int r = 0; r < n; ++r) {
        min = std::min(min, vsum - ps[r].first);
        vsum += ps[r].second;
        ans = std::max(ans, vsum - ps[r].first - min);
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}

