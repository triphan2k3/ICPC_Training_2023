#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 1007;
const int MOD = 998244353;
int n, m;
int a[N][N], b[N][N];
int bl[N][N], wh[N][N];

void add(int &a, int b) {
    a = (a + b) % MOD;
}

void mult(int &a, int b) {
    a = 1LL * a * b % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    FOR(i, 1, m) {
        FOR(j, 1, n) cin >> a[i][j];
        FOD(j, n, 1) add(a[i][j], a[i][j + 1]);
    }
    FOR(i, 1, m) FOR(j, 1, n) cin >> b[i][j];
    FOR(j, 1, n) FOD(i, m, 1) add(b[i][j], b[i + 1][j]);
    // chang N before submit
    int ans = 2;
    FOD(i, m, 2) FOD(j, n, 2) {
        int thisProb = 1LL * a[i][j - 1] * b[i - 1][j] % MOD;
        int thatProb = 1LL * (1 + MOD - a[i - 1][j - 1]) * (1 + MOD - b[i- 1][j - 1]) % MOD;
        int realProb = 1LL * thisProb * thatProb % MOD;
        add(ans, realProb);
    }
    cout << ans;
}