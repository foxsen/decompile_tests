#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    set<int> se;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a, se.insert(a);

    cout << se.size() - !(se.size() % 2) << endl;

    return 0;
}
