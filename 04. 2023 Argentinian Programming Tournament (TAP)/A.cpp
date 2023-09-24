/// hhoangcp

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int p[100006][18], lg2[100006], n, m, a[100006], e[100006];

void hhoangcp() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        cin >> e[i];
        p[i][0] = e[i];
        if (i > 1) lg2[i] = lg2[i >> 1] + 1;
    }

    for(int i = 1; i <= 16; ++i)
    for(int j = 1; j <= m - (1 << i) + 1; ++j) p[j][i] = min(p[j][i - 1], p[j + (1 << (i - 1))][i - 1]);

    for(int i = 1; i <= n; ++i) {
        for(int cur = 1; cur <= m; ++cur) {
            int l = cur, r = m, pa = m + 1;

            while (l <= r) {
                int mid = (l + r) >> 1;
                int k = lg2[mid - cur + 1];
                if (min(p[cur][k], p[mid - (1 << k) + 1][k]) <= a[i]) {
                    pa = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }

            if (pa > m) break;
            cur = pa;
            a[i] %= e[cur];
        }

        cout << a[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; //cin >> tests;
    while (tests--) hhoangcp();

    return 0;
}
