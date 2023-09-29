#include <bits/stdc++.h>
#define ll long long
using namespace std;

int seg[8000006], cnt[8000006];

vector<int> P[1000006];

void update(int p, int l, int r, int u, int v, int val) {
    if (l > v || r < u)
        return;
    if (u <= l && r <= v) {
        cnt[p] += val;
        if (cnt[p] > 0)
            seg[p] = r - l + 1;
        else
            seg[p] = (seg[p << 1] + seg[p << 1 | 1]);

        return;
    }

    int mid = (l + r) >> 1;

    update(p << 1, l, mid, u, v, val);
    update(p << 1 | 1, mid + 1, r, u, v, val);

    if (cnt[p] > 0)
        seg[p] = r - l + 1;
    else
        seg[p] = seg[p << 1] + seg[p << 1 | 1];
}

void solve() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        P[a].push_back(i);

        if ((int)P[a].size() >= k) {
            int p1 = P[a].size() - k - 2;
            int p2 = P[a].size() - k - 1;
            int p3 = P[a].size() - k;

            if (p2 >= 0) {
                update(1, 1, 1000000, P[a][p2] + 1, P[a][p3], 1);
                if (p1 >= 0)
                    update(1, 1, 1000000, P[a][p1] + 1, P[a][p2], -1);
                else
                    update(1, 1, 1000000, 1, P[a][p2], -1);
            } else
                update(1, 1, 1000000, 1, P[a][p3], 1);
        }

        ans += i - seg[1];
    }

    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;  // cin >> t;
    while (t--) {
        solve();
    }
}