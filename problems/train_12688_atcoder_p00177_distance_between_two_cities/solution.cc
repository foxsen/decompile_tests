#include<iostream>
#include<cmath>
#define LEN 6378.1
#define PI 3.141592653589793238
using namespace std;
double a, b, c, d, BC, CA, C;
int main() {
	while (true) {
		cin >> a >> b >> c >> d;
		if (a == -1) { break; }
		BC = PI / 180 * (90.0 - a);
		CA = PI / 180 * (90.0 - c);
		C = PI*(d - b) / 180;
		cout << (int)(0.5 + LEN*acos(cos(BC)*cos(CA) + sin(BC)*sin(CA)*cos(C)))<< endl;
	}
}