#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <long long, long long> pll;

ll mod = 1000000007;


int main(){

  ll test;
  cin >> test;

  while (test--){

     ll n;
     cin >> n;

     vector <ll> a(n);

     for (int i = 0; i < n; i++)
        cin >> a[i];

     vector <ll> brim(40, 0);

     ll bnod = n;

     for (int i = 0; i < n; i++){

        ll t = a[i], counter = 0;
        while (t > 0){
            brim[counter] += t%2;
            t/=2, counter++;
        }

     }

     for (int i = 0; i < n; i++){

        bool od = false;
        ll t = a[i], counter = 0;

        while (t > 0){
            if (t%2 == 1 && brim[counter] < n)
                od = true;
            t/=2, counter++;
        }

        if (od)
            bnod--;

     }

     if (bnod < 2){
        cout << "0" << endl;
        continue;
     }

     ll rjes = 1;
     rjes = bnod*(bnod-1);
     rjes %= mod;

     for (int i = 1; i <= n - 2; i++)
        rjes *= i, rjes%= mod;

     cout << rjes << endl;

  }

}
