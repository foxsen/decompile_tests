#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int N; string M;
int p[50]; long long power[20];
inline long long div(long long k, int m) {
	long long sum = 0;
	while (k >= 1) {
		k /= m; sum += k;
	}
	return sum;
}
int main() {
	while (true) {
		cin >> N >> M; power[0] = 1;
		for (int i = 0; i < 50; i++)p[i] = 0;
		for (int i = 1; i < M.size(); i++)power[i] = power[i - 1] * N;
		if (N == 0)break;
		long long C = 0;
		for (int i = 0; i < M.size(); i++) {
			int V = (char)(M[i] - '0'); if (M[i] >= 'A')V = (char)(M[i] - 'A') + 10;
			C += power[M.size() - 1 - i] * V;
		}
		int L = N;
		for (int i = 2; i <= L; i++) {
			while (L%i == 0) {
				L /= i; p[i]++;
			}
		}
		long long minx = 1LL << 62;
		for (int i = 2; i <= N; i++) {
			if (p[i] == 0)continue;
			minx = min(minx, div(C, i) / p[i]);
		}
		cout << minx << endl;
	}
	return 0;
}