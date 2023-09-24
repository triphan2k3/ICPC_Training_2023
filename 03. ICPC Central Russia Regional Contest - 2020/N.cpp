#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define ii pair<int, int>

using namespace std;

int a[16], p[16];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        p[i] = i;
    }

    int num = 0, best = 0;

    do
    {
        int s = 0, sum = 0;
        for (int i = 0; i < n; ++i)
        {
            s += a[p[i]];
            if (s > k)
                break;

            sum += s;
            sum %= 1440;

            if (num < i + 1)
            {
                num = i + 1;
                best = sum;
            }
            else if (num == i + 1)
                best = min(best, sum);
        }
    } while (next_permutation(p, p + n));

    cout << num << ' ' << best;

    return 0;
}