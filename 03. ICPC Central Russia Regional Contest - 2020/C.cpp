#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define ii pair<int, int>

using namespace std;

const int N = 1e5 + 7;
int n, m, s, t; 
vector<ii> e[N];
int d[N][8];

int cost(int u, int v) {
    if (u == v) return 7;
    if (u < v) return v - u;
    return v + 7 - u;
}
typedef pair<int, ii> iii;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m >> s >> t;
    FOR(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    FOR(i, 1, n)
        FOR(j, 1, 7)
            d[i][j] = 1e9;

    priority_queue<iii, vector<iii>, greater<iii>> pq;
    FOR(i, 1, 7) {
        d[s][i] = i - 1;
        pq.push({i - 1, {s, i}});
    }
    while (pq.size()) {
        int dui = pq.top().first;
        int u = pq.top().second.first;
        int i = pq.top().second.second;
        pq.pop();
        if (dui != d[u][i]) continue;
        for (ii edge:e[u]) {
            int v = edge.first;
            int j = edge.second % 7 + 1;
            if (d[v][j] > d[u][i] + cost(i, j)) {
                d[v][j] = d[u][i] + cost(i, j);
                pq.push({d[v][j], {v,j}});
                int cur = d[v][j];
                FOR(k, j + 1, 7) {
                    ++cur;
                    if (d[v][k] > cur) {
                        d[v][k] = cur;
                        pq.push({cur, {v, k}});
                    }
                }
                FOR(k, 1, j - 1) {
                    ++cur;
                    if (d[v][k] > cur) {
                        d[v][k] = cur;
                        pq.push({cur, {v, k}});
                    }
                }
            }
        }
    }
    int ans = __INT_MAX__;
    // FOR(i, 1, n)
    //     FOR(j, 1, 7) {
    //         printf("d[%d,%d]=%d\n", i, j, d[i][j]);
    //     }
    FOR(i, 1, 7)
        ans = min(ans, d[t][i]);
    cout << ans;   


}