#include<iostream>
#include<map>
#include<algorithm>
#include<cassert>
#include<vector>
#include<cstring>
using namespace std;

int dp[1000], catsum[20010];
vector<pair< int, int > > cats;
vector<int> foods;
int N,M,lmost;

bool isable(int mid) {
    memset(dp, -1, sizeof(dp));

    for(int i=M-1; i>=0; --i) {
        if(i == M-1) {
            dp[i] = 0;
            continue;
        }
        int ret = 1<<29;
        for(int j=i+1; j<M; ++j) {
            int right = catsum[foods[j]] - catsum[(foods[i]+foods[j])/2];;
            int left = catsum[(foods[i]+foods[j])/2] - catsum[foods[i]];

            //cout<<i<<" "<<j<<" "<<right<<" "<<left<<endl;
            if(right + dp[j] <= mid) ret = min(left, ret);
        }
        dp[i] = ret;
    }
    if(dp[0] + lmost <= mid) return true;
    return false;
}

int main() {
    int x,y,c,totalcats = 0;
    while(cin>>N>>M, N|M) {

        memset(catsum, 0, sizeof(catsum));
        foods.clear();
        cats.clear();
        totalcats = 0;

        for(int i=0; i<N; ++i) {
            cin>>x>>y>>c;
            x += 10000;
            totalcats += c;
            cats.push_back(make_pair(x,c));
        }

        for(int i=0; i<M; ++i) {
            cin>>c;
            foods.push_back(c+10000);
        }

        if(M == 1) {
            cout<<totalcats<<endl;
            continue;
        }

        sort(cats.begin(), cats.end());
        sort(foods.begin(), foods.end());

        //êÔ¶Ì¦³¢êæè¶ÌLð¦³¢êÌªÉ í¹é
        //Eà¯l
        lmost = 0;
        for(int i=0; i<N; ++i) {

            if(cats[i].first <= foods[0]) {
                cats[i].first = foods[0];
                lmost += cats[i].second;
            }
            if(cats[i].first >= foods[M-1]) cats[i].first = foods[M-1];
            catsum[cats[i].first] += cats[i].second;
            //cout<<"add "<<cats[i].first<<endl;
        }

        int ss = 0;
        for(int i=0; i<20010; ++i) {
            ss += catsum[i];
            catsum[i] = ss;
        }

        int low = -1,hi = totalcats;
        while(low+1<hi) {
            int mid = (low+hi)/2;
            //cout<<mid<<" "<<low<<" "<<hi<<endl;
            if(isable(mid)) hi = mid;
            else low = mid;
        }
        cout<<hi<<endl;
    }
}