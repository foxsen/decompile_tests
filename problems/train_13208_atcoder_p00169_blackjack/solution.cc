#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

void split( vector<int>& vi, string in ) {
    int i=0;
    while( i < in.length() ) {
        int x = 0;
        while( i < in.length() && in[i]!=' ' ) {
            x *= 10;
            x += in[i]-'0';
            i++;
        }
        vi.push_back(x);
        i++;
    }
}

int main(){
    string in;
    while( getline(cin, in), !(in.length()==1 && in[0]=='0') ) {
        vector<int> vi;
        split( vi, in );
        int score=0, one=0;
        rep(i, vi.size()) {
            if( vi[i] == 1 ) {
                one++;
                score += 1;
            } else {
                score += min(10, vi[i]);
            }
        }
        while( one && score+10<=21 ) {
            score += 10;
            one--;
        }
        cout << (score<=21 ? score : 0) << endl;
    }
    return 0;
}