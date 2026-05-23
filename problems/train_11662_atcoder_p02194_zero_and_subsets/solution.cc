#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

vector<int64_t> fact, seq_inv, fact_inv;

void create_fact_mod(int num){
    fact[0] = fact[1] = 1;
    for(int i=2; i<=num; i++) fact[i] = fact[i-1] * i % MOD;
}

void create_seq_inv_mod(int num){
    seq_inv[0] = seq_inv[1] = 1;
    for(int i=2; i<=num; i++) seq_inv[i] = (MOD - MOD/i) * seq_inv[MOD%i] % MOD;
}

void create_fact_inv_mod(int num){
    fact_inv[0] = fact_inv[1] = 1;
    for(int i=2; i<=num; i++) fact_inv[i] = fact_inv[i-1] * seq_inv[i] % MOD;
}

void create_mod_tables(int num){
    fact.resize(num+1);
    seq_inv.resize(num+1);
    fact_inv.resize(num+1);
    create_fact_mod(num);
    create_seq_inv_mod(num);
    create_fact_inv_mod(num);
}

int64_t comb_mod(int n, int k){
    return fact[n] * fact_inv[n-k] % MOD * fact_inv[k] % MOD;
}

int64_t perm_mod(int n, int k){
    return fact[n] * fact_inv[n-k] % MOD;
}

int64_t power_mod(int64_t num, int64_t power){
    int64_t prod = 1;
    num %= MOD;
    while(power > 0){
        if(power&1) prod = prod * num % MOD;
        num = num * num % MOD;
        power >>= 1;
    }
    return prod;
}

int64_t extgcd(int64_t a, int64_t b, int64_t& x, int64_t& y){
    int64_t d = a;
    if(b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }else{
        x = 1; y = 0;
    }
    return d;
}

int64_t inv_mod(int64_t a){
    int64_t x, y;
    extgcd(a, MOD, x, y);
    return (MOD + x%MOD) % MOD;
}

int nth_bit(int64_t num, int n){
    return (num >> n) & 1;
}

int pop_count(int bits){
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

int main(){
    int N;
    cin >> N;
    const int M = 1<<20;
    static int num[M];
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        num[a]++;
    }
    for(int k=0; k<20; k++) for(int i=M-1; i>=0; i--) if(!nth_bit(i, k)) num[i] += num[i+(1<<k)];

    vector<int64_t> pw2(N+1, 1);
    for(int i=1; i<=N; i++) pw2[i] = pw2[i-1] * 2 % MOD;


    int64_t ans = 0;
    for(int i=0; i<M; i++){
        int64_t res = pw2[num[i]] - 1;
        if(pop_count(i)%2) res *= -1;
        add(ans, MOD+res);
    }
    cout << ans << endl;
    return 0;
}

