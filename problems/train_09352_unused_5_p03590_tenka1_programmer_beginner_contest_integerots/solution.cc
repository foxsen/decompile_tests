#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int>v;
	v.push_back(K);
	for (int i = 0;i<=30;++i) {
		if ((K>>i)&1) {
			int n = (K >> (i + 1)) << (i + 1);
			n += (1<<i)-1;
			v.push_back(n);
		}
	}
	vector<int>A(N);
	vector<long long>B(N);
	for (int i = 0;i<N;++i) {
		cin >> A[i] >> B[i];
	}
	long long ans = 0;
	for (int i = 0;i<v.size();++i) {
		long long sub = 0;
		for (int j = 0;j<N;++j) {
			bool b = true;
			for (int k = 0;k<=30;++k) {
				if ((v[i]>>k)&1) {
				}
				else {
					if ((1<<k)&A[j]) {
						b = false;
					}
				}
			}
			if (b) {
				sub += B[j];
			}
		}
		ans = max(ans,sub);
	}
	cout << ans <<  endl;
	return 0;
}
