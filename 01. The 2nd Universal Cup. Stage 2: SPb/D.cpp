#include <iostream>
#include <vector>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;


int main() {
    int m, n;
    cin >> m >> n;
    if (m == n) {
        if (m == 1) {
            cout << "1\n1 1";
            return 0;
        }
        cout << 2 * m - 2 << "\n";
        FOR(i, 1, n)
            cout << 1 << " " << i << "\n";
        FOR(i, 2, n - 1)
            cout << n << " " << i << "\n";
        return 0;
    }
    int swaped = 0;
    // let m < n
    if (m > n) {
        swap(m, n);
        swaped = 1;
    }

    vector<pair<int, int>> ans;
    FOR(i, 1, m)
        ans.push_back({i, 1});
    FOR(i, 1, m)
        ans.push_back({i, n});
    if (m % 2) {
        int mid = (m + 1) / 2;
        int covered = (m + 1) / 2;
        FOR(j, covered + 1, n - covered)
            ans.push_back({mid, j});
    } else {
        int mid = m / 2;
        int covered = m / 2 + 1;
        for (int j = covered + 1; j <= n - covered; j += 2) {
            ans.push_back({mid, j});
            ans.push_back({mid + 1, j});
        }
    }

    cout << ans.size() << "\n";
    for (pair<int, int> item:ans) {
        int x = item.first;
        int y = item.second;
        if (swaped)
            swap(x, y);
        cout << x << " " << y << "\n";
    }
    return 0;
}