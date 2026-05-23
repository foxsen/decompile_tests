#include <iostream>

using namespace std;

const int MAX_PRIME = (1 << 15);
bool prime[MAX_PRIME + 1];

void init_prime()
{
    for (int i = 0; i <= MAX_PRIME; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= MAX_PRIME; i++) 
        if (prime[i])
            for (int j = 2 * i; j <= MAX_PRIME; j += i)
                prime[j] = false;
}

void solve(int n)
{
    int ans = 0;

    for (int i = 2; i <= n / 2; i++) {
        if (n - i < 2)
            break;
        if (prime[i] && prime[n - i]) 
            ans++;
    }

    cout << ans << endl;
}

int main()
{
    int n;
    
    init_prime();
    while (cin >> n, n) {
        solve(n);
    }

    return 0;
}