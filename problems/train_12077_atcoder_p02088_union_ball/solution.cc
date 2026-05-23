#include <iostream>
#include <array>

using std::array;

int main() {
    int n;
    std::cin >> n;
    array<int, 2> cnt{};
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        ++cnt[a % 2];
    }

    if (cnt[0] == 0 || cnt[1] == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << n - (2 - cnt[1] % 2) << std::endl;
    }
    return 0;
}

