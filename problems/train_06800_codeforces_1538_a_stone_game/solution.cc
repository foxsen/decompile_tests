#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector <int> stones(n);
        for (int i = 0; i < n; i++)
            cin >> stones[i];
        int min_weight = 101, max_weight = 0, min_index, max_index;
        for (int i = 0; i < n; i++) {
            if (stones[i] < min_weight) {
                min_weight = stones[i];
                min_index = i;
            }
            if (stones[i] > max_weight) {
                max_weight = stones[i];
                max_index = i;
            }
        }
        int min_index1 = min(min_index + 1, n - min_index), max_index1 = min(max_index + 1, n - max_index);
        if (min_index1 < max_index1) {
            if (min_index + 1 < n - min_index)
                cout << min_index1 + min(max_index - min_index, n - max_index) << '\n';
            else
                cout << min_index1 + min(max_index + 1, min_index - max_index) << '\n';
        }
        else {
            if (max_index + 1 < n - max_index)
                cout << max_index1 + min(min_index - max_index, n - min_index) << '\n';
            else
                cout << max_index1 + min(min_index + 1, max_index - min_index) << '\n';
        }
    }
    return 0;
}
