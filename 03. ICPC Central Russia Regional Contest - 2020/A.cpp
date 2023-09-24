#include<bits/stdc++.h>
#define ll long long 
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second 
#define ii pair<int, int>


using namespace std;
const int N = 1e5 + 7;
vector<int> e[N];
int in[N], out[N], sz[N], depth[N];
int n, k;
int cnt = 0;
int ans = 0;

int dfs(int u, int p = 0) {
    sz[u] = 1;
    in[u] = ++cnt;
    depth[u] = depth[p] + 1;
    for (int v:e[u])
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    out[u] = ++cnt;
    if (sz[u] >= k && depth[u] > depth[ans])
        ans = u; 
    return 0;
}

int main() {
    cin >> n >> k;
    FOR(u, 2, n) {
        int v; cin >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int r = dfs(1);
    FOR(u, 1, n) {
        if (in[u] >= in[ans] && out[u] <= out[ans]) {
            --k;
            cout << u << " ";
        }
        if (k == 0)
            break;
    }
}