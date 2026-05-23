#include <iostream>

using namespace std;

int main()
{
	int n, price, sum = 0, ave = 0, cont = 0;
	double dave = 0;
	char c;

	while(cin >> price >> c >> n){
		sum += price * n;
		ave += n;
		dave += n;
		cont++;
	}

	ave /= cont;
	dave /= (double)cont;

	if(dave - (double)ave >= 0.5)    ave++;

	cout << sum << endl << ave << endl;

	return 0;
}