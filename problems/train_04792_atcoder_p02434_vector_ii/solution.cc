#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, q, op, t, x;
    scanf("%d %d", &n, &q);
    vector<int> v[n];
    while (q--) {
        scanf("%d %d", &op, &t);
        if (op == 0) {
            scanf("%d", &x);
            v[t].push_back(x);
        } else if (op == 1) {
            if (!v[t].empty()) printf("%d", v[t][0]);
            for (int i = 1; i < v[t].size(); i++) printf(" %d", v[t][i]);
            printf("\n");
        } else {
            v[t].clear();
        }
    }
    return 0;
}
