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

    int ans = a[1];
    for (int i = 2; i <= n; ++i)
        if (abs(2LL * ans - a[1] - a[n]) > abs(2LL * a[i] - a[1] - a[n]))
            ans = a[i];

    cout << ans;

    return 0;
}