#include <bits/stdc++.h>
using namespace std;

int tot;
int N, A[1<<17];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", A+i);

	tot += abs(A[0]);
	for (int i = 0; i < N; ++i) tot += abs(A[i] - A[i+1]);
	
	printf("%d\n", tot - abs(A[0]) - abs(A[1] - A[0]) + abs(A[1]));
	for (int i = 1; i < N; ++i) printf("%d\n", tot - abs(A[i] - A[i-1]) - abs(A[i+1] - A[i]) + abs(A[i+1] - A[i-1]));
}