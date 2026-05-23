#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef long double ld;

int main () {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
    	int a, b; cin >> a >> b;
    	int cur = 0;

    	if (b == 1)
    		b++, cur++;

    	int mn = INT_MAX;

    	while (true) {
    		int tmp = a;
    		int res = cur;
    		while (a) {
    			a /= b;
    			res++;
    		}
    		if (res <= mn) {
    			mn = res;
    		} else {
    			break;
    		}
    		a = tmp;
    		cur++;
    		b++;
    	}

    	cout << mn << '\n';
    }

    return 0;
}