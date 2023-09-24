#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define ii pair<int, int>

using namespace std;

ll suf[100006];
int a[100006], n, q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a + 1, a + n + 1);
    suf[n] = a[n];
    for (int i = n - 1; i >= 1; --i)
        suf[i] = suf[i + 1] + a[i];

    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;

        int p = lower_bound(a + 1, a + n + 1, k) - a;

        cout << max(0LL, suf[p] - 1LL * (n - p + 1) * k) << '\n';
    }

    return 0;
}