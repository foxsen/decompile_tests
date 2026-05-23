#include <bits/stdc++.h>
using namespace std;
char s[210];
int main()
{
	
	
	scanf("%s", s);
	int x = strlen(s);
	for (int i = (x - 1) / 2 - 1; i >= 0; i--) {
		if (!strncmp(s, s + i + 1, i + 1)) {
			printf("%d\n", 2 * (i + 1));
			break;
		}
	}
}