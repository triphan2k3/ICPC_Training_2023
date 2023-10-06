#include <algorithm>
#include <iostream>
#include <vector>
#define int long long

using namespace std;

constexpr int mod = 1e9 + 7;

int fact[200006], inv[200006], invf[200006], power[200006], invp[200006];

void init() {
    fact[0] = inv[0] = invf[0] = 1;
    fact[1] = inv[1] = invf[1] = 1;
    for (int i = 2; i <= 200000; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
        inv[i] = (mod - 1LL * (mod / i) * inv[mod % i] % mod) % mod;
        invf[i] = 1LL * invf[i - 1] * inv[i] % mod;
    }

    power[0] = invp[0] = 1;
    for (int i = 1; i <= 200000; ++i) {
        power[i] = power[i - 1] * 2LL % mod;
        invp[i] = 1LL * invp[i - 1] * inv[2] % mod;
    }
}

int C(int n, int r) {
    if (r > n)
        return 0;
    if (n == r || r == 0)
        return 1;
    return 1LL * fact[n] * (1LL * invf[r] * invf[n - r] % mod) % mod;
}

void Excalibur() {
    int n, m;
    cin >> n >> m;
    if (m > n)
        cout << "0\n";
    else if (m == n)
        cout << 1LL * fact[n - 1] * inv[2] % mod << '\n';
    else if (m == 0) {
        cout << "1\n";
    } else {
        int ans = 0;

        int tot = 2 * m;
        for (int i = 0; i < m; ++i) {
            int t = tot - 2 * i;
            if (t + i > n)
                continue;
            if (t <= 0)
                continue;

            int delta = 1LL * fact[t] * invp[t / 2] % mod;
            delta = 1LL * delta * invf[t / 2] % mod;

            delta = 1LL * delta * C(n, t) % mod;
            delta = 1LL * delta * C(n - t, i) % mod;
            delta = 1LL * delta * fact[i] % mod;
            delta = 1LL * delta * C(t / 2 - 1 + i, t / 2 - 1) % mod;

            ans = (1LL * ans + delta) % mod;
        }

        cout << ans << '\n';
    }
}

signed main() {
    init();

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int tests = 1;
    cin >> tests;
    while (tests--)
        Excalibur();

    return 0;
}