#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main() {
	cin >> a >> b >> c >> d;
	cout << (abs(c-a)<=d || (abs(a-b)<=d && abs(b-c)<=d) ? "Yes" : "No") << endl;
}