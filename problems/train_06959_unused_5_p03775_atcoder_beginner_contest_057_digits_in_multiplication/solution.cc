#include<iostream>
using namespace std;
int main() {
long long n;
cin >> n;
int ans = 10;
for(long long i = 1; i*i <= n; i++) {
if(n%i != 0) continue;
if(to_string(n/i).size() < ans) ans = to_string(n/i).size();
}
cout << ans << endl;
return 0;
}