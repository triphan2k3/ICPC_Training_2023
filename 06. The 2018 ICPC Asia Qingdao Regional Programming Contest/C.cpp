#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[1000006];
int n, k;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i])
            l = i + 1;
        else
            break;
    }

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == t[i])
            r = i - 1;
        else
            break;
    }

    if (l > r) {
        cout << 1LL * n * (n + 1) / 2 << '\n';
        return;
    }

    int p = l + 1;
    for (; p < r; ++p)
        if (s[p] == t[p])
            break;

    if (p >= r) {
        cout << 2LL * (n - 1) << '\n';
        return;
    }

    int u = r - 1;
    for (; u > p; --u)
        if (s[u] == t[u])
            break;

    bool ok = true;
    for (int i = p + 1; i < u; ++i)
        ok &= s[i] == t[i];

    if (!ok)
        cout << 0 << '\n';
    else
        cout << 6 << '\n';
}

int main() {
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}