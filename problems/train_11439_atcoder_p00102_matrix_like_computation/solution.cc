#include <iostream>

using namespace std;

int main()
{
	int n;
	short matrix[11][11];

	while(cin >> n, n)
	{
		for(int i=0; i < n; i++) matrix[n][i] = matrix[i][n] = 0;
		matrix[n][n] = 0;
		for(int y=0; y < n; y++) {
			for(int x=0; x < n; x++) {
				cin >> matrix[y][x];
				matrix[n][x] += matrix[y][x];
				matrix[y][n] += matrix[y][x];
				matrix[n][n] += matrix[y][x];
			}
		}
		int nn = n + 1;
		for(int y=0; y < nn; y++) {
			for(int x=0; x < nn; x++) {
					printf("%5d", matrix[y][x]);
			}
			printf("\n");
		}
	}

	return 0;
}