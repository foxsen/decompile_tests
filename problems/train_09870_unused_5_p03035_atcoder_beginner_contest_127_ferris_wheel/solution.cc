#include <iostream>
using namespace std;

int main(){
    int A=0,B=0;
    cin >> A >> B;
    cout << (A>12?B:(A>5?B/2:0)) << endl;
}