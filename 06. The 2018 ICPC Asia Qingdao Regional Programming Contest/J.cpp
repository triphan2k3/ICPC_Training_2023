#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

ll a[1000006];
int n, k;

void solve() {
    cin >> n >> k;
    int d = 0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        d += (a[i] == 0);
    }

    if(d > k) {
        cout << "Impossible" << endl;
        return;
    }
    if(n == k) {
        cout << "Richman" << endl;
        return;
    }

    ll s = 0;
    for(int i=1; i<=n; i++) {
        if(d > k) break;
        if(a[i] == 0) continue;
        if(d == k) {
            ll minn = a[i]-1;
            for(int j=i+1; j<=n; j++) {
                if(a[j] > 0) minn = min(minn, a[j]-1);
            }
            s += minn;
        } 
        else s += a[i];
        d += 1;
    }
    cout << s << endl;
}

int main() {
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}