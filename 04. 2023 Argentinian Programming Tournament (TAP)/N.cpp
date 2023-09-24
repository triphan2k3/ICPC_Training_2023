/// hhoangcp

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FOR(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

int a[5];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        ++a[x % 5];
    }

    int ans = a[0];

    int Min = min(a[1], a[4]); ans += Min; a[1] -= Min, a[4] -= Min;
    Min = min(a[2], a[3]); ans += Min; a[2] -= Min, a[3] -= Min;

    if (a[1] > 0 && a[2] > 0) {
        int best = 0;
        for(int i = 0; i <= min(a[2] / 2, a[1]); ++i) {
            int num1 = (a[1] - i) / 3;
            int num2 = a[2] - 2 * i;

            int num3 = min(num1, num2);
            num1 -= num3;
            num2 -= num3;
            best = max(best, i + num3 + num1 / 5 + num2 / 5);
        }

        ans += best;
    } else if (a[1] > 0 && a[3] > 0) {
        int best = 0;
        for(int i = 0; i <= min(a[1] / 2, a[3]); ++i) {
            int num1 = (a[3] - i) / 3;
            int num2 = a[1] - 2 * i;

            int num3 = min(num1, num2);
            num1 -= num3;
            num2 -= num3;
            best = max(best, i + num3 + num1 / 5 + num2 / 5);
        }

        ans += best;
    } else if (a[2] > 0 && a[4] > 0) {
        int best = 0;
        for(int i = 0; i <= min(a[4] / 2, a[2]); ++i) {
            int num1 = (a[2] - i) / 3;
            int num2 = a[4] - 2 * i;

            int num3 = min(num1, num2);
            num1 -= num3;
            num2 -= num3;
            best = max(best, i + num3 + num1 / 5 + num2 / 5);
        }

        ans += best;
    } else if (a[3] > 0 && a[4] > 0) {
        int best = 0;
        for(int i = 0; i <= min(a[3] / 2, a[4]); ++i) {
            int num1 = (a[4] - i) / 3;
            int num2 = a[3] - 2 * i;

            int num3 = min(num1, num2);
            num1 -= num3;
            num2 -= num3;
            best = max(best, i + num3 + num1 / 5 + num2 / 5);
        }

        ans += best;
    } else if (a[1] > 0) ans += a[1] / 5;
    else if (a[2] > 0) ans += a[2] / 5;
    else if (a[3] > 0) ans += a[3] / 5;
    else if (a[4] > 0) ans += a[4] / 5;

    cout << ans;

    return 0;
}
