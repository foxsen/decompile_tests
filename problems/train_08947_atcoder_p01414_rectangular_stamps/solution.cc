#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int,int> pint;

#define DE 1
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define ALL(s) (s).begin(),(s).end()
#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define EACH(i,s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define FOR_SUBSET(b, a) for(int b = a; b != 0; b = (b-1)&a)
#define COUT(x) cout<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl

template<class T1, class T2> ostream& operator<<(ostream &s, pair<T1,T2> P){return s<<'<'<<P.first<<", "<<P.second<<'>';}
template<class T> ostream& operator<<(ostream &s, vector<T> P) {s<<"{ ";for(int i=0;i<P.size();++i){if(i>0)s<<", ";s<<P[i];}return s<<" }"<<endl;}
template<class T1, class T2> ostream& operator<<(ostream &s, map<T1,T2> P) {s<<"{ ";for(__typeof__(P.begin()) it=P.begin();it!=P.end();++it){if(it!=P.begin())s<<", ";s<<'<'<<it->first<<"->"<<it->second<<'>';}return s<<" }"<<endl;}


const int MAX = 20;
const int INF = 1<<29;

int dp[1<<17];
int n;
int a[MAX], b[MAX];

char field[4][4];
char color[3] = {'R', 'G', 'B'};

int ind(int i, int j) {
    return i*4+j;
}

void debug(int bit) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << ((bit & (1<<ind(i,j))) != 0);
        }
        cout << endl;
    }
    cout << " : " << dp[bit] << endl << endl;
}

int main() {
    //freopen( "/Users/macuser/Documents/Programming/Contest/input.in", "r", stdin );
    
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        for (int i = 0; i < 4; ++i) 
            for (int j = 0; j < 4; ++j)
                cin >> field[i][j];
        
        for (int bit = 0; bit < (1<<16); ++bit) dp[bit] = INF;
        dp[0] = 0;
        
        for (int bit = 0; bit < (1<<16); ++bit) {
            
            //debug(bit);
            
            for (int id = 0; id < n; ++id) {
                int from1 = 1 - a[id], from2 = 1-b[id];
                for (int i = from1; i < 4; ++i) {
                    for (int j = from2; j < 4; ++j) {
                        for (int col = 0; col < 3; ++col) {
                            char c = color[col];
                            bool ok = true;
                            int addbit = 0;
                            for (int k = max(0, i); k < min(4, i+a[id]); ++k) {
                                for (int l = max(0, j); l < min(4, j+b[id]); ++l) {
                                    if ((bit & (1<<ind(k,l))) && field[k][l] != c) ok = false;
                                    if (!(bit & (1<<ind(k,l))) && field[k][l] == c) addbit += 1<<ind(k,l);
                                }
                            }
                            if (ok) {
                                FOR_SUBSET(subbit, addbit) {
                                    int nbit = bit | subbit;
                                    dp[nbit] = min(dp[nbit], dp[bit]+1);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << dp[(1<<16)-1] << endl;
    }
    
    return 0;
}
