#include<bits/stdc++.h>
#define ln puts("")
#define sp printf(" ")
using namespace std;
typedef long long ll;

inline ll read() {
	ll sum = 0, ff = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')
			ff = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
		sum = sum * 10 + ch - '0', ch = getchar();
	return sum * ff;
}

void write(ll x) {
	if(x < 0)
		putchar('-'), x = -x;
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

int t, n, a[1007], zero;
bool flag;
 
int main() {
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	t = read();
	while(t--) {
		n = read();
		zero = 0;
		flag = true;
		for(int i = 1; i <= n; i++)
			scanf("%1d", &a[i]), zero += !a[i];
		for(int i = 1; i <= (n + 1) / 2; i++)
			if(a[i] != a[n - i + 1])
				flag = false;
		if(flag) {
			if(zero == 0)
				puts("DRAW");
			else if(zero % 2 && zero != 1)
				puts("ALICE");
			else
				puts("BOB");
		}
		else {
			if(zero == 2 && n % 2 && a[(n + 1) / 2] == 0)
				puts("DRAW");
			else
				puts("ALICE");
		}
	}
	return 0;
}
