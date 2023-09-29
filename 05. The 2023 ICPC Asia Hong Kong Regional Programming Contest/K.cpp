#include <bits/stdc++.h>

using namespace std;

int a[100006];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    int Min = 1e9 + 7;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        Min = min(Min, a[i]);
    }

    int GCD = Min;
    for (int i = 1; i <= n; ++i)
        GCD = __gcd(GCD, a[i]);

    bool ok = true;
    for (int i = 1; i <= n; ++i)
        ok &= a[i] == Min || a[i] >= 2 * Min;

    if (ok)
        GCD = Min;
    else {
        GCD = Min / 2;
        for (int i = 1; i <= n; i++)
            if (a[i] != Min)
                GCD = min(GCD, (a[i] - 1) / 2);
    }
    cout << GCD;

    return 0;
}