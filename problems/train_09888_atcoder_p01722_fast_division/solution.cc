#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main() {

    int n;
    cin >> n;

    if(n == 0) {
        cout << 1%2 << endl;
    }

    if(n == 1) {
        cout << 11%3 << endl;
    }
    
    if(n == 2) {
        cout << 111%5 << endl;
    }

    if(n >= 3) {
        cout << 0 << endl;
    }
    
    return 0;
}