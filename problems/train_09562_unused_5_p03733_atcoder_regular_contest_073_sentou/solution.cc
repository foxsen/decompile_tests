#include <iostream>
using namespace std;
int main(void) {
	long long N, T, t1, t2, sum = 0;
	cin >> N >> T >> t2;
	for (int i = 0; i < N; ++i) {
		t1 = t2;
		cin >> t2;
		if (t2 - t1 >= T) sum += T;
		else sum += t2 - t1;
	}
	sum += T;
	cout << sum << endl;
	return 0;
}