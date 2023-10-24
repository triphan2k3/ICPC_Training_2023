#include <bits/stdc++.h>
#define ll long long
#define llong long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define all(a) a.begin(), a.end()
using namespace std;
// #define LOCAL

const int mod = 1e9 + 7;
int dp[101][8][7][6][5][4][3][2];
bool tick[9];

int main(int argc, char* argv[]) {
#ifdef LOCAL
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a;
        cin >> a;
        tick[a] = true;
    }
    // n = stoi(argv[1]);
    // m = stoi(argv[2]);
    // k = stoi(argv[3]);

    dp[0][0][0][0][0][0][0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int a = 0; a < max(1, 8 * tick[8]); ++a)
            for (int b = 0; b < max(1, 7 * tick[7]); ++b)
                for (int c = 0; c < max(1, 6 * tick[6]); ++c)
                    for (int d = 0; d < max(1, 5 * tick[5]); ++d)
                        for (int e = 0; e < max(1, 4 * tick[4]); ++e)
                            for (int f = 0; f < max(1, 3 * tick[3]); ++f)
                                for (int g = 0; g < max(1, 2 * tick[2]); ++g) {
                                    if (tick[1])
                                        (dp[i][a][b][c][d][e][f][g] +=
                                         dp[i - 1][max(0, a - 1)][max(0, b - 1)]
                                           [max(0, c - 1)][max(0, d - 1)]
                                           [max(0, e - 1)][max(0, f - 1)]
                                           [max(0, g - 1)]) %= mod;
                                    if (a == 7 && tick[8])
                                        (dp[i][a][b][c][d][e][f][g] +=
                                         dp[i - 1][0][max(0, b - 1)]
                                           [max(0, c - 1)][max(0, d - 1)]
                                           [max(0, e - 1)][max(0, f - 1)]
                                           [max(0, g - 1)]) %= mod;
                                    if (b == 6 && tick[7])
                                        (dp[i][a][b][c][d][e][f][g] +=
                                         dp[i - 1][max(0, a - 1)][0]
                                           [max(0, c - 1)][max(0, d - 1)]
                                           [max(0, e - 1)][max(0, f - 1)]
                                           [max(0, g - 1)]) %= mod;
                                    if (c == 5 && tick[6])
                                        (dp[i][a][b][c][d][e][f][g] +=
                                         dp[i - 1][max(0, a - 1)][max(0, b - 1)]
                                           [0][max(0, d - 1)][max(0, e - 1)]
                                           [max(0, f - 1)][max(0, g - 1)]) %=
                                            mod;
                                    if (d == 4 && tick[5])
                                        (dp[i][a][b][c][d][e][f][g] +=
                                         dp[i - 1][max(0, a - 1)][max(0, b - 1)]
                                           [max(0, c - 1)][0][max(0, e - 1)]
                                           [max(0, f - 1)][max(0, g - 1)]) %=
                                            mod;
                                    if (e == 3 && tick[4])
                                        (dp[i][a][b][c][d][e][f][g] +=
                                         dp[i - 1][max(0, a - 1)][max(0, b - 1)]
                                           [max(0, c - 1)][max(0, d - 1)][0]
                                           [max(0, f - 1)][max(0, g - 1)]) %=
                                            mod;
                                    if (f == 2 && tick[3])
                                        (dp[i][a][b][c][d][e][f][g] +=
                                         dp[i - 1][max(0, a - 1)][max(0, b - 1)]
                                           [max(0, c - 1)][max(0, d - 1)]
                                           [max(0, e - 1)][0][max(0, g - 1)]) %=
                                            mod;
                                    if (g == 1 && tick[2])
                                        (dp[i][a][b][c][d][e][f][g] +=
                                         dp[i - 1][max(0, a - 1)][max(0, b - 1)]
                                           [max(0, c - 1)][max(0, d - 1)]
                                           [max(0, e - 1)][max(0, f - 1)][0]) %=
                                            mod;
                                }

    int ans = 0;
    for (int a = 0; a < 8; ++a)
        for (int b = 0; b < 7; ++b)
            for (int c = 0; c < 6; ++c)
                for (int d = 0; d < 5; ++d)
                    for (int e = 0; e < 4; ++e)
                        for (int f = 0; f < 3; ++f)
                            for (int g = 0; g < 2; ++g) {
                                (ans += dp[n][a][b][c][d][e][f][g]) %= mod;
                            }

    cout << ans;

    return 0;
}