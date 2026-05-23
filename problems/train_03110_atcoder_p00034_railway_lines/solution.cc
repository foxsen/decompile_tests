#include<iostream>
using namespace std;

int main()
{
	int l[10], v[2];
	char d;
	while (cin >> l[0] >> d >> l[1] >> d >> l[2] >> d >> l[3] >> d >> l[4] >> d >> l[5] >> d >> l[6] >> d >> l[7] >> d >> l[8] >> d >> l[9] >> d >> v[0] >> d >> v[1]){
		double L = 0, V = v[0] + v[1],a = 0;
		for (int i = 0; i < 10; ++i){
			L += l[i];
		}

		a = L * v[0] / V;
		
		for (int i = 0; i < 10; ++i){
			a -= l[i];
			if (a <= 0){
				cout << i+1 << endl;
				break;
			}
		}

	}
	return 0;
}