/// hhoangcp

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FOR(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

pair<int, int> P[1000006];
int n, Maxr[1006], Maxc[1006];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j) {
        int a; cin >> a;
        P[a] = {i, j};
    }

    int ans = 1;
    for(int i = 1; i <= n * n; ++i) {
        int r = P[i].first, c = P[i].second;

        int premaxr = Maxr[r], premaxc = Maxc[c];
        Maxr[r] = max({Maxr[r], premaxc + 1, 1});
        Maxc[c] = max({Maxc[c], premaxr + 1, 1});

        ans = max(ans, Maxr[r]);
        ans = max(ans, Maxc[c]);
    }

    cout << ans;

    return 0;
}
