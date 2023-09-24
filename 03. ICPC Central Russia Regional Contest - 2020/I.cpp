#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define ii pair<int, int>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll ans = -1;
    for (int i = 1; i * i <= n; ++i)
        if (n % i == 0)
        {
            ll t = (n / i + 1) * i;
            if (t * t % n == 0 && (ans == -1 || ans > t))
                ans = t;

            t = (i + 1) * (n / i);
            if (t * t % n == 0 && (ans == -1 || ans > t))
                ans = t;
        }

    cout << (ans * ans - n * n) / n;

    return 0;
}