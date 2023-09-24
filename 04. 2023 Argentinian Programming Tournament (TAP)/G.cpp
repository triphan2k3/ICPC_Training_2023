/// hhoangcp

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FOR(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

struct TEdge {
    int u, v, cost;

    bool operator < (const TEdge &other) const {
        return cost < other.cost;
    }
};

vector<TEdge> E;
struct Segment {
    int l, r, y;

    bool operator < (const Segment &other) const {
        return y < other.y;
    }
} P[100006];

int lazy[800006], seg[800006], XY[200006], n, cnt, par[100006], L[100006], R[100006];

void down(int p) {
    if (lazy[p] != 0) {
        lazy[p << 1] = lazy[p << 1 | 1] = seg[p << 1] = seg[p << 1 | 1] = lazy[p];
        lazy[p] = 0;
    }
}

void update(int p, int l, int r, int u, int v, int val) {
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
        seg[p] = val;
        lazy[p] = val;
        return;
    }

    down(p);
    int mid = (l + r) >> 1;

    update(p << 1, l, mid, u, v, val);
    update(p << 1 | 1, mid + 1, r, u, v, val);

    seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
}

int query(int p, int l, int r, int u, int v) {
    if (l > v || r < u) return -1e9;
    if (u <= l && r <= v) return seg[p];

    down(p);
    int mid = (l + r) >> 1;
    return max(query(p << 1, l, mid, u, v), query(p << 1 | 1, mid + 1, r, u, v));
}

void build(int p, int l, int r) {
    if (l > r) return;

    seg[p] = -1e9; lazy[p] = 0;
    if (l == r) return;

    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}

int Find(int p) {
    if (par[p] < 0) return p;
    return par[p] = Find(par[p]);
}

bool Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;

    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v]; par[v] = u;
    return true;
}

void hhoangcp() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int l, r, y; cin >> y >> l >> r;
        P[i] = {l, r, y};
    }

    sort(P + 1, P + n + 1);

    if (true) {
        cnt = 0;
        for(int i = 1; i <= n; ++i) {
            XY[++cnt] = P[i].l - P[i].y;
            XY[++cnt] = P[i].r - P[i].y;
        }

        sort(XY + 1, XY + cnt + 1);
        cnt = unique(XY + 1, XY + cnt + 1) - XY - 1;

        build(1, 1, cnt);
        for(int i = 1, j = 1; i <= n; i = j) {
            while (j <= n && P[i].y == P[j].y) {
                int l = lower_bound(XY + 1, XY + cnt + 1, P[j].l - P[j].y) - XY;
                int r = lower_bound(XY + 1, XY + cnt + 1, P[j].r - P[j].y) - XY;

                L[j] = l;
                R[j] = r;

                int p1 = query(1, 1, cnt, l, l), p2 = query(1, 1, cnt, r, r);
                if (p1 >= 1 && p1 < i) E.push_back({j, p1, P[j].y - P[p1].y});
                if (p2 >= 1 && p2 < i) E.push_back({j, p2, P[j].y - P[p2].y});

                int p3 = query(1, 1, cnt, l + 1, r - 1);
                if (p3 >= 1 && p3 < i) E.push_back({j, p3, P[j].y - P[p3].y});

                ++j;
            }

            for(int k = i; k < j; ++k) update(1, 1, cnt, L[k], R[k], k);
        }

        build(1, 1, cnt);
        for(int i = n, j = n; i >= 1; i = j) {
            while (j >= 1 && P[i].y == P[j].y) {
                int l = L[j];
                int r = R[j];

                int p1 = query(1, 1, cnt, l, l), p2 = query(1, 1, cnt, r, r);
                if (p1 >= -n && p1 < -i) E.push_back({j, -p1, P[-p1].y - P[j].y});
                if (p2 >= -n && p2 < -i) E.push_back({j, -p2, P[-p2].y - P[j].y});

                int p3 = query(1, 1, cnt, l + 1, r - 1);
                if (p3 >= -n && p3 < -i) E.push_back({j, -p3, P[-p3].y - P[j].y});

                --j;
            }

            for(int k = i; k > j; --k) update(1, 1, cnt, L[k], R[k], -k);
        }

        build(1, 1, cnt);
    }

    if (true) {
        cnt = 0;
        for(int i = 1; i <= n; ++i) {
            XY[++cnt] = P[i].l + P[i].y;
            XY[++cnt] = P[i].r + P[i].y;
        }

        sort(XY + 1, XY + cnt + 1);
        cnt = unique(XY + 1, XY + cnt + 1) - XY - 1;

        build(1, 1, cnt);
        for(int i = 1, j = 1; i <= n; i = j) {
            while (j <= n && P[i].y == P[j].y) {
                int l = lower_bound(XY + 1, XY + cnt + 1, P[j].l + P[j].y) - XY;
                int r = lower_bound(XY + 1, XY + cnt + 1, P[j].r + P[j].y) - XY;

                L[j] = l;
                R[j] = r;

                int p1 = query(1, 1, cnt, l, l), p2 = query(1, 1, cnt, r, r);
                if (p1 >= 1 && p1 < i) E.push_back({j, p1, P[j].y - P[p1].y});
                if (p2 >= 1 && p2 < i) E.push_back({j, p2, P[j].y - P[p2].y});

                int p3 = query(1, 1, cnt, l + 1, r - 1);
                if (p3 >= 1 && p3 < i) E.push_back({j, p3, P[j].y - P[p3].y});

                ++j;
            }

            for(int k = i; k < j; ++k) update(1, 1, cnt, L[k], R[k], k);
        }

        build(1, 1, cnt);
        for(int i = n, j = n; i >= 1; i = j) {
            while (j >= 1 && P[i].y == P[j].y) {
                int l = L[j];
                int r = R[j];

                int p1 = query(1, 1, cnt, l, l), p2 = query(1, 1, cnt, r, r);
                if (p1 >= -n && p1 < -i) E.push_back({j, -p1, P[-p1].y - P[j].y});
                if (p2 >= -n && p2 < -i) E.push_back({j, -p2, P[-p2].y - P[j].y});

                int p3 = query(1, 1, cnt, l + 1, r - 1);
                if (p3 >= -n && p3 < -i) E.push_back({j, -p3, P[-p3].y - P[j].y});

                --j;
            }

            for(int k = i; k > j; --k) update(1, 1, cnt, L[k], R[k], -k);
        }

        build(1, 1, cnt);
    }

    for(int i = 1; i <= n; ++i)
        E.push_back({i, n + 1, P[i].y});

    sort(E.begin(), E.end());

    for(int i = 1; i <= n + 1; ++i) par[i] = -1;

    vector<TEdge> E1;

    ll ans = 0; int cnt1 = 0;
    for(TEdge e: E)
    if (Union(e.u, e.v)) ans += e.cost, ++cnt1, E1.push_back({e.u, e.v, e.cost});

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; // cin >> tests;
    while(tests--) hhoangcp();

    return 0;
}
