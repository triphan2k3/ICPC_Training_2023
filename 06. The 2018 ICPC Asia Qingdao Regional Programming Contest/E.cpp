#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pb push_back
using namespace std;

int ok(ll mid, ll m, vector<int>& a) {
    vector<int> need;
    for (int i = 0; i < a.size(); i++) {
        need.pb((mid + a[i] - 1) / a[i]);
    }

    vector<int> vt;
    for(int i=0; i<a.size(); i++) {
        m -= need[i]-need[i]%2;
        need[i] %= 2;
        if(need[i]%2) {
            vt.pb(i);
            m -= 2;
        }
    }
    if(vt.size()) m += 1;

    return m>=0;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll m;
        cin >> n >> m;
        vector<int> a(n);
        for (int& x : a)
            cin >> x;
        ll l = 0, r = 1e17;
        ll ans = l;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ok(mid, m, a)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        cout << ans << "\n";
    }
}