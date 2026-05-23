#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int r = n;
    const int c25 = r / 25;
    r -= 25 * c25;
    const int c10 = r / 10;
    r -= 10 * c10;
    const int c5 = r / 5;
    r -= 5 * c5;

    cout << c25 + c10 + c5 + r << endl;
}
