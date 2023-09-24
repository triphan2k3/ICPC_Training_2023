#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define ii pair<int, int>
#define iii pair<ii, int>

using namespace std;

constexpr ll MOD = 1e9 + 7;
ll fact[1000006], inv[1000006], invf[1000006];

ll C(int n, int r)
{
    if (r > n)
        return 0;
    return fact[n] * (invf[r] * invf[n - r] % MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    fact[0] = fact[1] = inv[0] = inv[1] = invf[0] = invf[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        invf[i] = invf[i - 1] * inv[i] % MOD;
    }

    ll sum = 0, pre = 1;
    for (int i = 1; i <= n; ++i)
    {
        (sum += pre * C(n, i) % MOD) %= MOD;
        (pre += C(n, i)) %= MOD;
    }

    cout << sum;

    return 0;
}