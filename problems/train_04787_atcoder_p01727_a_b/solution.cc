#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define MAX_N 500000
string A, B;
int n, c, d, e, sum;
int a[MAX_N], b[MAX_N], ab[MAX_N];
char f[MAX_N];

int main() {
	cin >> n;
	cin >> A >> B;
	d = max(A.size(), B.size()) + 1;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] == '1') { c = 1; }
		if (A[i] == '0') { c = 0; }
		a[A.size() - 1 - i] = c;
	}
	for (int i = 0; i < B.size(); i++)
	{
		if (B[i] == '1') { c = 1; }
		if (B[i] == '0') { c = 0; }
		b[B.size() - 1 - i] = c;
	}
	for (int i = 0; i < d; i++)
	{
		ab[i] += a[i] + b[i];
		if (ab[i] >= 2) {
			ab[i] -= 2; ab[i + 1]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> f[i];
		if (f[i] == 'A') {
			cin >> e;
			if (a[e] == 1)
			{
				a[e] = 0;
				ab[e]--;
				if (ab[e] < 0)
				{
					while (e < d)
					{
						ab[e + 1]--;
						ab[e] += 2;
						if (ab[e + 1] == 0) { break; }
						e++;
					}
				}
			}
			else
			{
				a[e] = 1;
				ab[e]++;
				if (ab[e] >= 2)
				{
					while (e < d)
					{
						ab[e + 1]++;
						ab[e] -= 2;
						if (ab[e + 1] == 1) { break; }
						e++;
					}
				}
			}
		}
		if (f[i] == 'B')
		{
			cin >> e;
			if (b[e] == 1)
			{
				b[e] = 0;
				ab[e]--;
				if (ab[e] < 0)
				{
					while (e < d)
					{
						ab[e + 1]--;
						ab[e] += 2;
						if (ab[e + 1] == 0) { break; }
						e++;
					}
				}
			}
			else
			{
				b[e] = 1;
				ab[e]++;
				if (ab[e] >= 2)
				{
					while (e < d)
					{
						ab[e + 1]++;
						ab[e] -= 2;
						if (ab[e + 1] == 1) { break; }
						e++;
					}
				}
			}
		}
		if (f[i] == 'Q') {
			if (i >= 1) {
				if (f[i - 1] == 'Q') {
					cout << sum << endl; goto H;
				}
			}
			sum = 0;
			for (int j = d; j >= 0; j--)
			{
				if (a[j] != ab[j])
				{
					sum += j;
					break;
				}
				if (a[j] == 1) {
					sum++;
				}
			}
			cout << sum << endl;
		H:;
		}
	}
	return 0;
}