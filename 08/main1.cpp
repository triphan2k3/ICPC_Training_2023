#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define all(a) a.begin(), a.end()
using namespace std;
// #define LOCAL

const int mod = 1e9 + 7;
ll dp[200006][16];
int T[200006], cnt[200006], sz = 0, Z[200006];
string s;
int n, k;
const int base = 31;

ll ha[200006 + 7], Pow[200006 + 7];
void buildHash() {
    for (int i = 1; i <= n; i++)
        ha[i] = (ha[i - 1] * base + s[i] - 'a' + 1) % mod;
    Pow[0] =1 ;
    for (int i = 1; i <= n; i++)
        Pow[i] = Pow[i - 1] * base % mod;
}

ll getHash(int l, int r) {
    return (ha[r] - ha[l - 1] * Pow[r- l + 1] + mod * 1LL * mod) % mod;
}

int check(int j, int numdel) {
    string ss;
    if (numdel == j) return 1;
    
    for (int leftMost = max(j - 2 * numdel + 1, 0); leftMost <= j-numdel; leftMost++) {
        int rightMost = leftMost + numdel - 1;
        if (getHash(leftMost, rightMost) == getHash(j - numdel + 1, j)) return 0;
    }
    return 1;
}

int main() {
#ifdef LOCAL
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    cin >> n >> k;
    cin >> s;
    s = " " + s; // 1 index;
    buildHash();
    dp[0][0] = 1;
    for (int i = 1; i<= n; i++) {
        dp[i][0] = 1;
        for (int j = 0; j <= min (i, k); j++) { // try del j
            if (!check(i, j)) continue;
            for (int jj = j; jj <= k; jj++) {
                dp[i][jj] += dp[i - j][jj - j];
                dp[i][jj] %= mod;
            }
        }
    }
    cout << dp[n][k];
    
    return 0;
}
