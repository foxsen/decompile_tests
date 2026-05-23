// AOJ 1276

#include <iostream>

using namespace std;

bool prime[2000000];
void makeprime()
{
	fill(prime, prime + 2000000, true);
	prime[0] = prime[1] = false;
	for (int i = 4; i < 2000000; i+=2) prime[i] = false;
	for (int i = 3; i*i <= 2000000; i += 2){
		if (prime[i]){
			for (int j = i*2; j < 2000000; j += i){
				prime[j] = false;
			}
		}
	}

	return;
}

int main(void)
{
	makeprime();

	int k;
	while (cin >> k, k){
		int a = 0, b = 0;
		for (int i = k; i < 2000000; i++){
			if (prime[i]){
				a = i;
				break;
			}
		}
		for (int i = k; 0 <= i; i--){
			if (prime[i]){
				b = i;
				break;
			}
		}
		cout << a - b << endl;

	}

	return 0;
}