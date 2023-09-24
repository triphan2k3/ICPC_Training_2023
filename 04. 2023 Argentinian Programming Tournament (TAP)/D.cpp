/// hhoangcp

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 7;
ll c[N], p[N];
int k;

int check(long long m) {
    ll rem = 0;
    for (int i = 1; i <= k; i++) {
        rem += p[i];
        if (rem / m < c[i]) return 0;
        rem -= c[i] * m;
    }
    return 1;
}


void hhoangcp() {
    cin >> k;
    for (int i = 1; i <= k; i++) cin >> c[i];
    for (int i = 1; i <= k; i++) cin >> p[i];
    ll ans = 0;
    ll l = 1, r = 1e9;
    while (l <= r) {
        ll m = (l + r) >> 1;
        if (check(m)) {
            l = m + 1;
            ans = m;
        } else r = m - 1;
    }
    cout << ans;

}


int main() {

    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; //cin >> tests;
    while (tests--) hhoangcp();

    return 0;
}
