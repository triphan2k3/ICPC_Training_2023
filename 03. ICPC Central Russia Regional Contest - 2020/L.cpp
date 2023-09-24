#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define ii pair<int, int>

using namespace std;

string s;

void build(int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    build(l, mid);
    build(mid + 1, r);

    for (int i = l, j = r; i < j; ++i, --j)
        swap(s[i], s[j]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s;
    int n = s.size();
    build(0, n - 1);
    cout << s;

    return 0;
}