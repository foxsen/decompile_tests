/*
 * Author: NomadThanatos
 * Created Time:  2011/8/31 13:51:49
 * File Name: J.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())

const int MAXINT = -1u>>1;
const int base[] = {1,5,10,50,100,500};

int num[6];

int calcGive(int mo) {
    int res = 0;
    for(int i = 5 ; i >= 0 ; i--) {
        int toGive = mo / base[i];
        if (toGive > num[i]) {
            toGive = num[i];
        }
        res += toGive;
        mo -= toGive * base[i];
    }
    if (mo) return -1;
    return res;
}

int calcReturn(int mo) {
    int res = 0;
    for(int i = 5 ; i >= 0 ; i--) {
        res += mo / base[i];
        mo %= base[i];
    }
    return res;
}

int main() {
    int sum,P;
    while(scanf("%d",&P) == 1) {
        sum = 0;
        for(int i = 0 ; i < 6 ; i++) {
            scanf("%d",num + i);
            sum += num[i] * base[i];
        }
        if (P == 0) break;
        int minm = MAXINT;
        //printf("%d %d",P,sum);
        for(int p = P ; p < sum + 1 ; p++) {
            int give = calcGive(p);
            int ret = calcReturn(p - P);
            if (give != -1) {
                minm = min(minm,give + ret);
            }
        }
        printf("%d\n",minm);
    }
    return 0;
}