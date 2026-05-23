#include <iostream>
#include <fstream>

using namespace std;

int main() {
    //ifstream cin("Note.txt");
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        int x, y;
        x=n/2020;
        y=n-2020*x;
        cout << (y<=x?"YES":"NO") << endl;
    }
}

