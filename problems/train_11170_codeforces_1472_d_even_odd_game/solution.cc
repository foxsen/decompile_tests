#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int p = 0; p < t; p++)
    {
        int n;
        cin >> n;
        int* arr = new int[n];
        long long suma = 0, sumb = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        
        bool ver = true;
        for (int i = n-1; i >=0; i--)
        {
            if (ver == true) {
                if (arr[i] % 2 == 0) {
                    suma+=arr[i];
                }
            }
            else {
                if (arr[i] % 2 != 0) {
                    sumb+=arr[i];
                }
            }
            ver = !ver;
        }
        if(suma>sumb) {
            cout << "Alice" << endl;
            continue;
        }
        else {
            if (suma < sumb) {
                cout << "Bob" << endl;
                continue;
            }
        }
        cout << "Tie" << endl;
    }

}