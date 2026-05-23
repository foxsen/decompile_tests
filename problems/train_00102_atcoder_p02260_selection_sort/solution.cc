#include <iostream>
using namespace std;

int main(void)
{
	int n, an[100], cnt = 0;

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> an[i];

	for(int i = 0; i < n; i++) {
		int mini = i;
		int tmp = an[i];

		for(int j = i; j < n; j++) {
			if(an[j] < an[mini]) {
				mini = j;
			}
		}

		if(i != mini) {
			an[i] = an[mini];
			an[mini] = tmp;
			cnt++;
		}
	}

	for(int i = 0; i < n; i++)
		cout << an[i] << (i == n - 1 ? "\n" : " ");
	cout << cnt << endl;

	return 0;
}