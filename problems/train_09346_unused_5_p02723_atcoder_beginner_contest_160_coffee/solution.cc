#include <stdio.h>

int main() {
	char a[10];
	scanf("%s", &a);
	
	(a[2] == a[3] && a[4] == a[5]) ? puts("Yes") : puts("No");
	
	return 0;
}