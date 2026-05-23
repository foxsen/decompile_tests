#include <iostream>
#include <cstdio>
#define N 2005
using namespace std;

int h, w, c, mx, s[N][N];
char a[N][N];
int main()
{
	int i, j;
	cin >> h >> w;
	for (i = 0; i < h; i++) scanf("%s", &a[i]);
	for (i = 0; i < h; i++) {
		c = 0;
		for (j = 0; j < w; j++) {
			if (a[i][j] == '.') c++;
			else c = 0;
			s[i][j] += c;
		}
		c = 0;
		for (j = w - 1; j >= 0; j--) {
			s[i][j] += c;
			if (a[i][j] == '.') c++;
			else c = 0;
		}
	}
	for (j = 0; j < w; j++) {
		c = 0;
		for (i = 0; i < h; i++) {
			if (a[i][j] == '.') c++;
			else c = 0;
			s[i][j] += c;
		}
		c = 0;
		for (i = h - 1; i >= 0; i--) {
			s[i][j] += c;
			if (a[i][j] == '.') c++;
			else c = 0;
		}
	}
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			mx = max(mx, s[i][j] - 1);
		}
	}
    cout << mx << endl;
    return 0;
}