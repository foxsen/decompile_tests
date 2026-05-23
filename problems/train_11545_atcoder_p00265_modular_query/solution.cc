#include<iostream>
#include<set>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define max(a, b) (a>b?a:b)

int main() {
	int n, Q, c, q;
	set<int> card;
	cin >> n >> Q;
	rep(i, n) {
		cin >> c;
		card.insert(c);
	}
	int ma = *(--card.end());
	rep(i, Q) {
		cin >> q;
		
		if(q==1) {
			cout << "0" << endl;
			continue;
		}
		int ans = 0;
		for(int s=q; s<ma+q; s+=q) {
			set<int>::iterator it = card.lower_bound(s);
			if(it!=card.begin()) {
				int val = *(--it) % q;
				ans = max(ans, val);
			}
		}
		cout << ans << endl;
	}
	return 0;
}