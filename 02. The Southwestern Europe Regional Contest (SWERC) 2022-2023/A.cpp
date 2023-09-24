#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x:a) cin >> x;
        a.push_back(0);
        a.push_back(1440);
        sort(a.begin(), a.end());
        int to = 0;
        for (int i = 1; i <= n + 1; i++)
            to += (a[i] - a[i - 1]) / 120;
        cout << (to >= 2? "YES\n":"NO\n");
    }
}