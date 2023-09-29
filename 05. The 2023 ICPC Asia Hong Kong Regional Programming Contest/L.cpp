#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define ii pair<int, int>
using namespace std;

ii IT[1600007];

ii Get(int i, int l, int r, int L, int R) {
    if (l >= L && r <= R)
        return IT[i];
    if (l > R || r < L)
        return {0, 0};
    int m = (l + r) >> 1;
    ii getLeft = Get(i << 1, l, m, L, R);
    ii getRight = Get(i << 1 | 1, m + 1, r, L, R);
    return {max(getLeft.first, getRight.first),
            getLeft.second + getRight.second};
}

void Update(int i, int l, int r, int pos) {
    if (l == r) {
        IT[i] = {0, 0};
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m)
        Update(i << 1, l, m, pos);
    else
        Update(i << 1 | 1, m + 1, r, pos);
    IT[i] = {max(IT[i << 1].first, IT[i << 1 | 1].first),
             IT[i << 1].second + IT[i << 1 | 1].second};
}

void BuildTree(int i, int l, int r, vector<int>& a) {
    if (l == r) {
        IT[i] = {a[l], 1};
        return;
    }
    int m = (l + r) >> 1;
    BuildTree(i << 1, l, m, a);
    BuildTree(i << 1 | 1, m + 1, r, a);
    IT[i] = {max(IT[i << 1].first, IT[i << 1 | 1].first),
             IT[i << 1].second + IT[i << 1 | 1].second};
}

pair<int, int> FindLeft(int i, int l, int r, int R, int val) {
    if (R < l)
        return {0, 0};

    if (r <= R) {
        if (IT[i].first <= val)
            return IT[i];
        if (l == r)
            return {IT[i].first, 0};

        int mid = (l + r) >> 1;
        if (IT[i << 1 | 1].first > val)
            return FindLeft(i << 1 | 1, mid + 1, r, R, val);

        pair<int, int> num = FindLeft(i << 1, l, mid, R, val);
        num.first = max(num.first, IT[i << 1 | 1].first);
        num.second += IT[i << 1 | 1].second;

        return num;
    }

    if (l == r)
        return {0, 0};

    int mid = (l + r) >> 1;
    pair<int, int> num = FindLeft(i << 1 | 1, mid + 1, r, R, val);
    if (num.first <= val) {
        pair<int, int> num2 = FindLeft(i << 1, l, mid, R, val);
        num.first = max(num.first, num2.first);
        num.second += num2.second;
    }

    return num;
}

pair<int, int> FindRight(int i, int l, int r, int L, int val) {
    if (L > r)
        return {0, 0};

    if (l >= L) {
        if (IT[i].first <= val)
            return IT[i];

        if (l == r)
            return {IT[i].first, 0};

        int mid = (l + r) >> 1;
        if (IT[i << 1].first > val)
            return FindRight(i << 1, l, mid, L, val);

        pair<int, int> num = FindRight(i << 1 | 1, mid + 1, r, L, val);
        num.first = max(num.first, IT[i << 1].first);
        num.second += IT[i << 1].second;

        return num;
    }

    if (l == r)
        return {0, 0};

    int mid = (l + r) >> 1;
    pair<int, int> num = FindRight(i << 1, l, mid, L, val);
    if (num.first <= val) {
        pair<int, int> num2 = FindRight(i << 1 | 1, mid + 1, r, L, val);
        num.first = max(num.first, num2.first);
        num.second += num2.second;
    }

    return num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n + 1), pos(n + 1), l(k + 1), b(n + 1, 0);
        FOR(i, 1, n) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        FOR(i, 1, 8 * n) IT[i] = {0, 0};
        BuildTree(1, 1, n, a);
        vector<int> arr;

        FOR(i, 1, m) {
            int B;
            cin >> B;
            b[B] = 1;
            arr.push_back(B);
        }

        multiset<int> s;
        FOR(i, 1, k) {
            cin >> l[i];
            s.insert(l[i]);
        }

        string ans = "YES\n";
        for (int i = 1; i < arr.size(); i++)
            if (pos[arr[i]] < pos[arr[i - 1]])
                ans = "NO\n";

        FOD(i, n, 1)
        if (b[i] == 0) {
            int leftMost = FindLeft(1, 1, n, pos[i] - 1, i).second;
            int rightMost = FindRight(1, 1, n, pos[i] + 1, i).second;
            int maxSize = rightMost + leftMost + 1;
            if (s.size() == 0) {
                ans = "NO\n";
                break;
            }
            if (*s.begin() > maxSize) {
                ans = "NO\n";
                break;
            }
            Update(1, 1, n, pos[i]);
            s.erase(prev(s.upper_bound(maxSize)));
        }
        cout << ans;
    }
}