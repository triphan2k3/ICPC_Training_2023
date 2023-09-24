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

    int k1, k2;
    cin >> k1 >> k2;
    vector<int> ans;
    for (int i = 1; i <= max(3 * k1 + 2, 2 * k2 + 1); ++i)
        if ((i + 1) / 3 == k1 && (i + 1) / 2 == k2)
            ans.push_back(i);

    if (!ans.size())
        ans.push_back(0);

    for (int u : ans)
        cout << u << ' ';

    return 0;
}