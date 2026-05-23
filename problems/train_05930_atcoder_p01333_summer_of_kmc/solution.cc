#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
int main() {
	int a, b;
	while(cin>>a>>b&&a!=0&&b!=0){
		int h = 0, g = 0, s = 0,o=b-a;
		while (o >= 1000) {
			s++;
			o -= 1000;
		}
		while (o >= 500) {
			g++;
			o -= 500;
		}
		while (o >= 100) {
			h++;
			o -= 100;
		}
		cout << h << " " << g << " " << s << endl;
	}
}