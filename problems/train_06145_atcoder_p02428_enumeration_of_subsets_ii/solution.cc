#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    int k;
    std::cin >> k;

    std::vector<int> bs{};
    for (int i = 0; i < k; ++i) {
        int b;
        std::cin >> b;
        bs.push_back(b);
    }

    // XXX: using `test` function with bitset failed. why?
    for (int i = 0; i < (1 << n); ++i) {
        bool is_ok = true;
        for (int b : bs)
            if (~i & (1 << b)) {
                is_ok = false;
                break;
            }
        if (!is_ok) continue;

        std::vector<int> members{};
        for (int j = 0; j < n; ++j)
            if (i & (1 << j)) members.push_back(j);

        std::cout << i << ':';
        for (int j : members) std::cout << ' ' << j;
        std::cout << std::endl;
    }
}

/**
 * ref: https://onlinejudge.u-aizu.ac.jp/
 *        solutions/problem/ITP2_11_B/review/3113216/face4/C++14
 */
