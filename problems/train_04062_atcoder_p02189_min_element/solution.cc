#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18];
int minx = (1 << 30), minid = 0;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		if (minx > A[i]) { minx = A[i]; minid = i; }
	}
	cout << minid << endl;
	return 0;
}
