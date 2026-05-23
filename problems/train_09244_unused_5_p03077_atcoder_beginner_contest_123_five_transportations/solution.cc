#include <bits/stdc++.h>

int main(){
    using namespace std;
    long N;
    cin >> N;
    vector<long> v(5);
    for(auto& i : v)cin >> i;
    cout << 5 + (N - 1) / *min_element(v.begin(), v.end()) << endl;
    return 0;
}