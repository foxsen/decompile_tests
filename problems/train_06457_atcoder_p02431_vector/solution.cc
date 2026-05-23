#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int q; cin >> q;
    while (q--) {
        int com; cin >> com;
        if (com == 0) {
            int x; cin >> x; v.push_back(x);
        } else if (com == 1) {
            int p; cin >> p; cout << v[p] << endl;
        } else if (com == 2) {
            v.pop_back();
        }
    }
	return 0;
}
