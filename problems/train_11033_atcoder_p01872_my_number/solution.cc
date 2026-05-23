#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main() {
	std::string n;
	std::cin >> n;

	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		std::string s = n;
		std::replace(s.begin(), s.end(), '?', char('0' + i));
		long long sum = 0;
		for (int j = 0; j < 11; j++) {
			sum += (s[j] - '0') * (11 - j <= 6 ? (11 - j + 1) : (6 - j));
		}
		sum %= 11;
		if (sum <= 1) sum = 0;
		else sum = 11 - sum;
		if (sum == s[11] - '0') v.push_back(i);
	}


	if (v.size() == 1) {
		std::cout << v.front() << std::endl;
	} else {
		std::cout << "MULTIPLE" << std::endl;
	}
	return 0;
}