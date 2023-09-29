#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;
vector<int> e[N];
int n;

int dfs(int u) {
    vector<int> dp;
    for (int v:e[u]) 
        dp.push_back(dfs(v));
    if (dp.size() == 0) return 1;
    if (dp.size() == 1) return dp[0];
    sort(dp.begin(), dp.end());
    reverse(dp.begin(), dp.end());
    return max(dp[0], dp[1] + 1);
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            e[i].clear();
            int p; cin >> p;
            if (p == 0) continue;
            e[p].push_back(i);
        }
        cout << dfs(1) << "\n";
    }
}