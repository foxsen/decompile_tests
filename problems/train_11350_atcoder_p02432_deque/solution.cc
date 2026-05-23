using namespace std;
#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
#include <deque>

int main()
{
	int q;
	deque <int> deq;
	int a0, a1, a2;

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a0 >> a1;

		switch (a0) {
		case 0:
			cin >> a2;
			if (a1 == 0)
				deq.push_front(a2);
			else if (a1 == 1)
				deq.push_back(a2);
			break;

		case 1:
			cout << deq[a1] << endl;
			break;

		case 2:
			if (a1 == 0)
				deq.pop_front();
			else if (a1 == 1)
				deq.pop_back();
			break;
		}
	}
}

