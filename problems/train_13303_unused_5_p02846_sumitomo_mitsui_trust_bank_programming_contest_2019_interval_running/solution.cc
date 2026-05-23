#include <iostream>
using namespace std;
int main(void){
    long long t1, t2, a1, a2, b1, b2, c1, c2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    c1 = (a1 - b1) * t1;
    c2 = (a2 - b2) * t2;

    if(c1 < 0){
        c1 *= -1;
        c2 *= -1;
    }

    if(c1+c2 == 0){
        puts("infinity");
        return 0;
    }else if(c1 < 0 || c1+c2 > 0){
        puts("0");
        return 0;
    }
    long long c3 = - c1 - c2, ans;
    ans = c1 / c3 * 2 + 1;
    if(c1 % c3 == 0) ans--;
    cout << ans << endl;
    return 0;
}
