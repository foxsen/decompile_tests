#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* A = new int[n];
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	int q;
	cin >> q;
	int k;
	int answer;

	for (int i = 0; i < q; i++) {
		cin >> k;
		answer = lower_bound(A, A + n, k) - A;
		cout << answer << endl;
	}   
}
