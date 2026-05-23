#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

long long gcd(long long a, long long b){ // Ååöñ
    if(a == 0 || b == 0)
        return 0;
    if(b > a)
        swap(a, b);
    long long tmp;
    while((tmp = a % b) != 0){
        a = b;
        b = tmp;
    }
    return b;
}

long long lcm(long long a, long long b){ // Å¬ö{
    return a / gcd(a, b) * b;
}

char add(char a, char b)
{
    int c;
    if('0' <= a && a <= '9')
        c = a - '0';
    else
        c = a - 'A' + 10;
    if('0' <= b && b <= '9')
        c += b - '0';
    else
        c += b - 'A' + 10;
    if(c < 10)
        return '0' + c;
    else
        return 'A' + c - 10;
}

int main()
{
    int t;
    cin >> t;
    while(--t >= 0){
        int n;
        cin >> n;
        vector<string> s(n);
        for(int i=0; i<n; ++i){
            string tmp;
            cin >> tmp;
            int a = tmp.size()/2;
            for(int j=1; j<tmp.size()/2; ++j){
                if(tmp[2*j] != '0' || tmp[2*j+1] != '0'){
                    if(a == -1)
                        a = j;
                    else
                        a = gcd(a, j);
                }
            }
            for(unsigned j=0; j<tmp.size()/2; j+=a){
                s[i] += tmp[j*2];
                s[i] += tmp[j*2+1];
            }
        }

        int len = 1;
        for(int i=0; i<n; ++i){
            len = lcm(len, s[i].size()/2);
            if(len > 1024)
                break;
        }
        if(len > 1024){
            cout << "Too complex." << endl;
            continue;
        }

        string ret(len*2, '0');
        for(int i=0; i<n; ++i){
            int a = len / (s[i].size()/2);
            for(unsigned j=0; j<s[i].size()/2; ++j){
                ret[2*j*a] = add(ret[2*j*a], s[i][2*j]);
                ret[2*j*a+1] = add(ret[2*j*a+1], s[i][2*j+1]);
            }
        }
        cout << ret << endl;
    }
}