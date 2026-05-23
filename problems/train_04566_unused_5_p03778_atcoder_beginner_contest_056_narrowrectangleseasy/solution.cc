#include <iostream>
using namespace std;
int main(){
    int w, a, b; cin >> w >> a >> b;
    if(abs(a-b)<=w) cout << 0 << endl;
    else cout << abs(a-b)-w << endl;
    return 0;
}