#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define ii pair<int, int>

using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> odset;
int n, q, a[200006];
bool tick[200006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        odset.insert(i);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;

        auto iter = odset.find_by_order(l + 1);
        vector<int> P;
        for (int i = l + 1; i <= r && iter != odset.end(); ++i)
        {
            P.push_back(*iter);
            iter = next(iter);
        }

        for (int i : P)
            odset.erase(i);
    }

    tick[n + 1] = true;
    for (auto i : odset)
        tick[i] = true;
    for (int i = 1, Max = 0; i <= n; ++i)
    {
        Max = max(Max, a[i]);
        if (tick[i + 1])
        {
            cout << Max << ' ';
            Max = 0;
        }
    }

    return 0;
}