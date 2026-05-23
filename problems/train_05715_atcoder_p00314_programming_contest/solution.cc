//15-5
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define LL_MIN -9223372036854775808
#define LL_MAX 9223372036854775807
#define segment_size 65536
#define ROOP() while (true)

int main(){
    int N;
    cin >> N;
    int p[100];
    for(int i=0; i<N; i++){
        cin >> p[i];
    }

    int ans = 0;
    for(int i=1; i<=100; i++){
        int tmp = 0;
        for(int j=0; j<N; j++){
            if(p[j] >= i) tmp++;
        }
        if(tmp >= i) ans = i;
    }
    cout << ans << endl;
    
    return 0;
}

