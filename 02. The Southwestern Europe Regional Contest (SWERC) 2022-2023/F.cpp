#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> deg(n + 1);
        vector<ii> e;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            e.push_back({u,v});
            deg[u]++;
            deg[v]++;
        }
        int flex = 0;
        for (int i = 1; i <= n; i++)
            if (deg[i] < n - 1)
                flex = i;
        if (flex) {
            cout << "2\n";
            for (ii x:e)
                if (x.first == flex || x.second == flex)
                    cout << "1 ";
                else cout << "2 ";
        } else {
            cout << "3\n";
            flex = 1;
            for (ii x:e) {
                if (x.first == flex || x.second == flex) {
                    if (x == make_pair(1, 2) || x == make_pair(2, 1))
                        cout << "3 ";
                    else 
                        cout << "1 ";
                } else cout << "2 ";
            }
        }
        cout << "\n";

    }
}