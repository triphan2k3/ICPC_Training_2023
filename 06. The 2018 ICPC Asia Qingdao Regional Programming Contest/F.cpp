#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    int n2 = n, du = 1;
    while(n2 % 2 == 0) {
        n2 /= 2;
        du *= 2;
    }
    if(du <= k) {
        cout << "Impossible" << endl;
        return;
    }

    int ans[n+10], ans2[n+10];
    vector<int> a[n+10];
    for(int i=1; i<=n; i++) {
        if(i%2) {
            ans[i] = i+1;
            a[i].pb(i+1);
        }
        else {
            ans[i] = i-1;
            a[i].pb(i-1);
        }
        cout << ans[i] << " ";
    }
    cout << endl;
    for(int i=2; i<=k; i++) {
        for(int j=1; j<=n; j++) ans2[j] = 0;
        for(int j=1; j<=n; j++) {
            int x, y;
            if(ans2[j] == 0) {
                ans2[j] = j+i;
                ans2[j+i] = j;
                for(int k=0; k<a[j].size(); k++) {
                    x = a[j][k];
                    y = a[j+i][k];
                    ans2[x] = y; ans2[y] = x;
                }
            } 
        }
        for(int j=1; j<=n; j++) {
            cout << ans2[j] << " ";
            a[j].pb(ans2[j]);
            a[ans2[j]].pb(j);
            ans[j] = ans2[j];
        }
        cout << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}