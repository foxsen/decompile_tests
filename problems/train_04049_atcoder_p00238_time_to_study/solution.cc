#include <iostream>
using namespace std;

int main()
{
	int t, n, m;

	cin >> t;
	
	while (t > 0) {
		cin >> n;
		m = 0;

		for (int i = 0; i < n; i++) {
			int s, f;
			cin >> s >> f;

			m += f - s;
		}

		if (m >= t)
			cout << "OK" << endl;
		else
			cout << t - m << endl;

		cin >> t;
	}

	return 0;
}

